/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 20:30:20 by wquirrel          #+#    #+#             */
/*   Updated: 2020/01/21 20:30:23 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		hook_mouse(int button, int x, int y, t_mlx *mlx)
{
	x = 0;
	y = 0;
	mlx_destroy_image(mlx->mlx, (*mlx).img.img_ptr);
	img_new(mlx);
	if (button == 4)
	{
		if (mlx->cam.z > 0)
			mlx->cam.z += 1;
	}
	if (button == 5)
	{
		if (mlx->cam.z > 0)
			mlx->cam.z -= 1;
	}
	if (mlx->cam.z < 1)
		mlx->cam.z = 1;
	if (button == MLB)
		mlx->mouse.pressed = 1;
	print_map(mlx);
	return (0);
}


int			mouse_release(int button, int x, int y, void *param)
{
	t_mlx	*mlx;

	(void)button;
	(void)x;
	(void)y;
	mlx = (t_mlx *)param;
	mlx->mouse.pressed = 0;
	return (0);
}


int mouse_move(int x, int y, void *param)
{
	t_mlx *mlx;

	mlx = (t_mlx *)param;
	mlx->mouse.old_x = mlx->mouse.x;
	mlx->mouse.old_y = mlx->mouse.y;
	mlx->mouse.x = x;
	mlx->mouse.y = y;
	if(mlx->mouse.pressed)
	{
		mlx->cam.x_r += (y - mlx->mouse.old_y) * 0.002;
		mlx->cam.y_r += (x - mlx->mouse.old_x) * 0.002;
		print_map(mlx);
	}
	return (0);
}