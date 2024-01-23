/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 10:24:31 by wecorzo-          #+#    #+#             */
/*   Updated: 2024/01/23 15:49:36 by wecorzo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Libft/libft.h"
#include <signal.h>
#include <stdio.h>

void	send_binario(char *str, int pid)
{
	int	i;
	char	c;

	while (*str)
	{
		c = *str;
		i = 7;
		while (i >= 0)
		{
			if (c & (1 << i))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			i--;
			usleep(380);
		}
		str++;
	}
	/*
	if (num > 1)
		send_binario(num / 2, pid);
	if  (num % 2 == 1)
	{
		kill(pid, SIGUSR1);
		usleep(350);
	}
	else if (num % 2 == 0)
	{
		kill(pid, SIGUSR2);
		usleep(350);
	}*/
}

int main(int argc, char **argv)
{
	pid_t	pid;
	char	*str;

	if (argc != 3)
		return (1);
	pid = ft_atoi(argv[1]);
	str = argv[2];
	send_binario(str, pid);
	return (0);
}
