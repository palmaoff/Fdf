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

int key_press(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 13 || keycode == 125)
		move_it(mlx, 1);
	else if (keycode == 0 || keycode == 124)
		move_it(mlx, 2);
	else if (keycode == 1 || keycode == 126)
		move_it(mlx, -1);
	else if (keycode == 2 || keycode == 123)
		move_it(mlx, -2);
	else if (keycode == 6) 
		move_it(mlx, -3);
	else if (keycode == 7) 
		move_it(mlx, 3);
	else if (keycode == 27) 
		move_it(mlx, -4);
	else if (keycode == 24) 
		move_it(mlx, 4);
	else if (keycode == 88) 
		move_it(mlx, -5);
	else if (keycode == 85) 
		move_it(mlx, 5);
	else if (keycode == 83) 
		move_it(mlx, 6);
	else if (keycode == 84) 
		move_it(mlx, -6);
	else if (keycode == 86) 
		move_it(mlx, 7);
	else if (keycode == 87) 
		move_it(mlx, -7);
	else
	{
		printf("%d\n", keycode);
	}
	return (0);
}

int hook_mouse(int button, int x, int y, t_mlx *mlx)
{
	x = 0;
	y = 0;
	if (button == 4) 
		move_it(mlx, 4);
	if (button == 5) 
		move_it(mlx, -4);
	return (0);
}

int hook_exit(void *param)
{
    (void)param;
    exit(0);
}

void init(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "42");
	img_new(mlx);
	mlx->cam.x = WIDTH / 2;
	mlx->cam.y = HEIGHT / 2;
	mlx->cam.z = 20;
	mlx->cam.di = 1;
	mlx->cam.x_r = 0;
	mlx->cam.y_r = 0;
	mlx->cam.z_r = 0;
}

int main(int ac, char **av)
{
	t_mlx mlx;
	int fd;

	if (ac != 2)
	{
		ft_putstr("error: not enough arguments");
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	init(&mlx);
	input(fd, &mlx);
	print_map(&mlx);
	mlx_hook(mlx.win, 2, 0, key_press, &mlx);
	mlx_hook(mlx.win, 4, 0, hook_mouse, &mlx);
	mlx_hook(mlx.win, 17, 0, hook_exit, mlx.mlx);
	mlx_loop(mlx.mlx);
	free_mtr(&mlx);
	return (0);
}
