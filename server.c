/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:19:52 by wecorzo-          #+#    #+#             */
/*   Updated: 2024/01/23 16:58:11 by wecorzo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Libft/libft.h"
#include <signal.h>
#include <stdio.h>

void handler(int sign)
{
	static char	result;
	static int	i;

	if(sign == SIGUSR1)
	{
		result <<= 1;
		result+= 1;
	}
	else
	{
		result <<= 1;
		result+= 0;
	}
	i++;
	if (i == 8)
	{
		write(1, &result, 1);
		result = 0;
		i = 0;
	}

}
int main(void)
{
	pid_t	pid;

	if ((signal(SIGUSR1, handler) == SIG_ERR) || signal(SIGUSR2, handler) == SIG_ERR)
		write(2, "Error Al configurar el Manejador de Señales \n", 44);
	pid = getpid();
	ft_putstr_fd(ft_itoa(pid), 1);
	write(1, "\n", 1);
	while (1)
		sleep(1);
	return (0);
}
