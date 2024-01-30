/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:19:52 by wecorzo-          #+#    #+#             */
/*   Updated: 2024/01/30 08:16:12 by wecorzo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Libft/libft.h"
#include <signal.h>
#include <stdio.h>

void	handler(int sign, siginfo_t *info, void *context)
{
	static char	result;
	static int	i;
	static char	*word;

	result = 0;
	(void)context;
	(void)info;
	if (word == NULL)
		word = malloc(sizeof(char));
	if (sign == SIGUSR1)
		result += 1;
	result <<= 1;
	i++;
	if (i == 8)
	{
		if (result == '\0')
			(/*kill(info->si_pid, SIGUSR2), */ft_printf("%s", word));
		else
		{
			word = ft_strjoin(word, &result);
			if (!word)
				(free(word), exit(1));
		}
		//free(word);
		i = 0;
	}
}

int	main(void)
{
	struct sigaction sa1;
	struct sigaction sa2;
	pid_t	pid;

	pid = getpid();
	sa1.sa_flags = SA_SIGINFO;
	sa1.sa_sigaction = handler;
	if (sigaction(SIGUSR1, &sa1, NULL) == -1)
		ft_printf("Error registering signal handler\n");
	sa2.sa_flags = SA_SIGINFO;
	sa2.sa_sigaction = handler;
	if (sigaction(SIGUSR2, &sa2, NULL) == -1)
		ft_printf("Error registering signal handler\n");
	ft_printf("Served started \n PID:%d", pid);
	while (1)
		sleep(1);
	return (0);
}
