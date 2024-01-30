/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 10:24:31 by wecorzo-          #+#    #+#             */
/*   Updated: 2024/01/30 07:40:36 by wecorzo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Libft/libft.h"
#include <signal.h>
#include <stdio.h>

static void	handler(int sign)
{
	if (sign == SIGUSR2)
	{
		ft_printf("Message sent succesfully ✨\n");
		exit(0);
	}
}

static void	send_binario(char *str, int pid)
{
	int		i;
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
			usleep(120);
		}
		str++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*str;

	if (signal(SIGUSR1, handler) == SIG_ERR 
		|| signal(SIGUSR2, handler) == SIG_ERR)
		ft_printf("Error registerin signal\n");
	if (argc != 3)
		return (1);
	pid = ft_atoi(argv[1]);
	str = argv[2];
	send_binario(str, pid);
	sleep(8);
	ft_printf("Error sending message\n");
	return (0);
}
