/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:19:52 by wecorzo-          #+#    #+#             */
/*   Updated: 2024/01/31 15:04:11 by wecorzo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Libft/libft.h"

char	*join_string(char *word, char *result)
{
	char		*aux;

	aux = word;
	word = ft_strjoin(word, result);
	free(aux);
	if (!word)
		(free(word), exit(1));
	return (word);
}

char	*handle_string(siginfo_t *info, char *word)
{
	kill(info->si_pid, SIGUSR2);
	ft_printf("%s\n", word);
	free(word);
	word = NULL;
	return (word);
}

void	handler(int sign, siginfo_t *info, void *context)
{
	static char	result;
	static int	i;
	static char	*word;

	((void)context, i++);
	if (word == NULL)
		word = calloc(1, sizeof(char));
	result <<= 1;
	if (sign == SIGUSR1)
		result += 1;
	else
		result += 0;
	if (i == 8)
	{
		if (result == '\0')
			word = handle_string(info, word);
		else
			word = join_string(word, &result);
		i = 0;
		result = 0;
	}
}

int	main(void)
{
	struct sigaction	sa1;
	struct sigaction	sa2;
	pid_t				pid;

	pid = getpid();
	sa1.sa_flags = SA_SIGINFO;
	sa1.sa_sigaction = handler;
	if (sigaction(SIGUSR1, &sa1, NULL) == -1)
		ft_printf("Error registering signal handler\n");
	sa2.sa_flags = SA_SIGINFO;
	sa2.sa_sigaction = handler;
	if (sigaction(SIGUSR2, &sa2, NULL) == -1)
		ft_printf("Error registering signal handler\n");
	ft_printf("Served started \n PID:%d\n", pid);
	while (1)
		sleep(1);
	return (0);
}
