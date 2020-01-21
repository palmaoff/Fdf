/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 21:49:17 by wquirrel          #+#    #+#             */
/*   Updated: 2020/01/17 21:49:20 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	rotate(t_mlx *mlx, int i, int j)
{
	double pre_y;
	double pre_x;
	double pre_z;

	pre_y = mlx->scrn[i][j].y;
	mlx->scrn[i][j].y = pre_y * cos(mlx->cam.x_r) + mlx->scrn[i][j].z
			* sin(mlx->cam.x_r);
	mlx->scrn[i][j].z = -pre_y * sin(mlx->cam.x_r) + mlx->scrn[i][j].z
			* cos(mlx->cam.x_r);
	pre_z = mlx->scrn[i][j].z;
	mlx->scrn[i][j].z = -mlx->scrn[i][j].x * sin(mlx->cam.y_r) + pre_z
			* cos(mlx->cam.y_r);
	mlx->scrn[i][j].x = pre_z * sin(mlx->cam.y_r) + mlx->scrn[i][j].x
			* cos(mlx->cam.y_r);
	pre_x = mlx->scrn[i][j].x;
	mlx->scrn[i][j].x = pre_x * cos(mlx->cam.z_r) - mlx->scrn[i][j].y
			* sin(mlx->cam.z_r);
	mlx->scrn[i][j].y = pre_x * sin(mlx->cam.z_r) + mlx->scrn[i][j].y
			* cos(mlx->cam.z_r);
}
