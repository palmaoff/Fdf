/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 13:47:20 by eflorean          #+#    #+#             */
/*   Updated: 2019/12/26 18:14:02 by eflorean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"


int		hook_exit(void *param)
{
	(void)param;
	exit(0);
}

void	init(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "42");
	img_new(mlx);
	mlx->cam.x = (WIDTH + MENU_WIDHT) / 2;
	mlx->cam.y = HEIGHT / 2;
	mlx->cam.z = 20;
	mlx->cam.di = 1;
	mlx->cam.x_r = -0.785398;
	mlx->cam.y_r = -0.523599;
	mlx->cam.z_r = 0.523599;
	mlx->cam.color = 0;
	mlx->cam.d_color = 0;
	mlx->mouse.pressed = 0;
}

int		main(int ac, char **av)
{
	t_mlx	mlx;
	int		fd;

	if (ac != 2)
	{
		ft_putstr("ussage:\t./fdf [filename]\n");
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	init(&mlx);
	mlx.file = av[1];
	if (!input(fd, &mlx))
	{
		ft_putstr("invalid file\n");
		return (0);
	}
	print_map(&mlx);
	mlx_hook(mlx.win, 2, 0, key_press, &mlx);
	mlx_hook(mlx.win, 4, 0, hook_mouse, &mlx);
	mlx_hook(mlx.win, 5, 0, mouse_release, &mlx);
	mlx_hook(mlx.win, 6, 0, mouse_move, &mlx);
	mlx_hook(mlx.win, 17, 0, hook_exit, mlx.mlx);
	print_menu(&mlx);
	mlx_loop(mlx.mlx);
	free_mtr(&mlx);
	return (0);
}
