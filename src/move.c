/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 15:52:22 by eflorean          #+#    #+#             */
/*   Updated: 2020/01/18 15:52:24 by eflorean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	die(char *str)
{
	ft_putstr(str);
	exit(0);
}

static	int		key_press_again(int keycode, t_mlx *mlx)
{
	if (keycode == 34)
	{
		mlx->cam.x_r = -0.785398;
		mlx->cam.y_r = -0.523599;
		mlx->cam.z_r = 0.523599;
	}
	if (keycode == 8)
	{
		mlx->cam.x_r = 0;
		mlx->cam.y_r = 0;
		mlx->cam.z_r = 0;
	}
	if (keycode == 24)
	{
		mlx->cam.d_color += 1000;
	}
	if (keycode == 27)
	{
		mlx->cam.d_color -= 1000;
	}
	print_map(mlx);
	return (0);
}

static	int		key_press_too_too(int keycode, t_mlx *mlx)
{
	if (keycode == 82)
	{
		mlx->cam.x_r = -0.785398;
		mlx->cam.y_r = -0.523599;
		mlx->cam.z_r = 0.523599;
		mlx->cam.di = 1;
		mlx->cam.z = 20;
		mlx->cam.x = X_START_POS;
		mlx->cam.y = Y_START_POS;
	}
	if (mlx->cam.z < 1)
		mlx->cam.z = 1;
	if (keycode == 35)
	{
		mlx->cam.x_r = -1.5708;
		mlx->cam.y_r = 0;
		mlx->cam.z_r = 0;
	}
	key_press_again(keycode, mlx);
	return (0);
}

static	int		key_press_too(int keycode, t_mlx *mlx)
{
	if (keycode == 69)
	{
		if (mlx->cam.z > 0)
			mlx->cam.z += 1;
	}
	else if (keycode == 88)
		mlx->cam.x_r -= 0.1;
	else if (keycode == 85)
		mlx->cam.x_r += 0.1;
	else if (keycode == 86)
		mlx->cam.y_r += 0.1;
	else if (keycode == 87)
		mlx->cam.y_r -= 0.1;
	else if (keycode == 83)
		mlx->cam.z_r += 0.1;
	else if (keycode == 84)
		mlx->cam.z_r -= 0.1;
	key_press_too_too(keycode, mlx);
	return (0);
}

int		key_press(int keycode, t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, (*mlx).img.img_ptr);
	img_new(mlx);
	if (keycode == 53)
		exit(0);
	else if (keycode == 13 || keycode == 125)
		mlx->cam.y += 5;
	else if (keycode == 1 || keycode == 126)
		mlx->cam.y -= 5;
	else if (keycode == 0 || keycode == 124)
		mlx->cam.x += 5;
	else if (keycode == 2 || keycode == 123)
		mlx->cam.x -= 5;
	else if (keycode == 6)
		mlx->cam.di -= 0.1;
	else if (keycode == 7)
		mlx->cam.di += 0.1;
	else if (keycode == 78)
	{
		if (mlx->cam.z > 0)
			mlx->cam.z -= 1;
	}
	key_press_too(keycode, mlx);
	return (0);
}
