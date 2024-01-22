/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 10:24:31 by wecorzo-          #+#    #+#             */
/*   Updated: 2024/01/22 16:27:03 by wecorzo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Libft/libft.h"
#include <signal.h>

int main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
		return (1);
	pid = ft_atoi(argv[1]);
	ft_putstr_fd(argv[1], 1);
	kill(pid, SIGUSR1);
	return (0);
}
