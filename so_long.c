/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:38:58 by wecorzo-          #+#    #+#             */
/*   Updated: 2024/02/15 16:13:33 by wecorzo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	leaks(void)
{
	system("leaks -q so_long");
}

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

int	closed( t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
		closed(vars);
	return (0);
}

void	exec_prog(char *argv)
{
	read_map(argv);
	return ;
	t_vars	vars;
	void	*img;
	int		h;
	int		w;

	h = 0;
	w = 0;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello, Wendy!");
	img = mlx_xpm_file_to_image(vars.mlx, "images/background.xpm", &w, &h);
	mlx_put_image_to_window(vars.mlx, vars.win, img, 0, 0);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
}

int	main(int argc, char **argv)
{
	//atexit(leaks);
	if (argc == 2)
		exec_prog(argv[1]);
	else
		finish("invalid number of paramets\n");
	return (0);
}
