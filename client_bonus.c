/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 10:24:31 by wecorzo-          #+#    #+#             */
/*   Updated: 2024/02/07 11:11:04 by wecorzo-         ###   ########.fr       */
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

static int	error_syntax(char *str_n)
{
	int	i;

	i = 0;
	if (!(str_n || str_n[i] == '\0'))
		return (ft_putstr_fd("Error PID Invalid", 2), 1);
	while (str_n[i])
	{
		if (!(str_n[i] >= '0' && str_n[i] <= '9'))
			return (ft_putstr_fd("Error PID Invalid", 2), 1);
		i++;
	}
	return (0);
}

void	send_binario(char str, int pid)
{
	int		i;
	char	c;

	c = str;
	i = 7;
	while (i >= 0)
	{
		if (c & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
		usleep(200);
	}
	usleep(350);
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*str;

	if (signal(SIGUSR1, handler) == SIG_ERR
		|| signal(SIGUSR2, handler) == SIG_ERR)
		ft_printf("Error registerin signal\n");
	if (argc != 3 || (argc == 3 && !(argv[2][0])))
		return (ft_printf("Invalid Parametre"), 1);
	if (error_syntax(argv[1]) == 1)
		(exit(1));
	pid = ft_atoi(argv[1]);
	if (pid < -2147483648 || pid > 2147483647)
		(ft_printf("Invalid Parametre"), exit (1));
	str = argv[2];
	while (*str)
		send_binario(*str++, pid);
	send_binario('\0', pid);
	sleep(150);
	ft_printf("Error sending message\n");
	return (0);
}
