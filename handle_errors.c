/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:02:04 by wecorzo-          #+#    #+#             */
/*   Updated: 2024/03/05 16:49:07 by wecorzo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	finish(char	*str)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	write(1, "\n", 2);
	exit(0);
}

void	val_ext(char *str)
{
	int	len;

	len = ft_strlen(str) - 4;
	if (ft_strncmp(str + len, ".ber", 4) != 0)
		finish("Invalid Extension\n");
}

void	validate_char(char **map)
{
	int		x;
	int		y;
	int		val;
	char	c;

	y = 0;
	if (map[y] == NULL)
		finish("empty map");
	x = ft_strlen(map[0]);
	while (map[y])
	{
		val = ft_strlen(map[y]);
		if (val != x)
			finish("val");
		x = 0;
		while (map[y][x])
		{
			c = map[y][x];
			if (c == '1' || c == 'P' || c == '0'
				|| c == 'E' || c == 'C' || c == '\n')
				x++;
			else
				finish("Invalid Map");
		}
		y++;
	}
	if (x == y + 1)
		finish("only  rectangle");
}

void	validate_map(char **map)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (x <= ft_strlen(map[0]))
		{
			if ((x == 0 && map[y][x] != '1') ||
				(y == 0 && map[y][x] != '1' && x < (ft_strlen(map[0]) - 1)))
				(printf("%c", map[y][x]),finish("Missing Walls"));
			x++;
		}
		y++;
	}
}
