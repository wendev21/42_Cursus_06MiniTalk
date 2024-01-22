/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:19:52 by wecorzo-          #+#    #+#             */
/*   Updated: 2024/01/22 15:22:49 by wecorzo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Libft/libft.h"
#include <signal.h>

void handler(int sign)
{
	(void)sign;
	write(1, "recived \n", 9);
}
int main(void)
{
	char	*str;
	pid_t	pid;

	if (signal(SIGUSR1, handler) == SIG_ERR)
		write(2, "Error Al configurar el Manejador de Señales \n", 44);
	pid = getpid();
	str = ft_itoa(pid);
	ft_putstr_fd(str, 1);
	while (1)
		sleep(1);
	return (0);
}
