/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 16:29:51 by wquirrel          #+#    #+#             */
/*   Updated: 2020/01/16 16:29:53 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_menu(t_mlx *mlx)
{
	int y;

	y = 0;
	int color = AUSTRALIUM_GOLD;
	mlx_string_put(mlx->mlx, mlx->win, 25, y += 20, color
			, "File:");
	mlx_string_put(mlx->mlx, mlx->win, 25, y += 20, color
			, mlx->file);
	mlx_string_put(mlx->mlx, mlx->win, 25, y += 20, color
			, "Commands:");
	mlx_string_put(mlx->mlx, mlx->win, 25, y += 20 , color
			, " Movement:");
	mlx_string_put(mlx->mlx, mlx->win, 25, y += 20 , color
			, MOVEMENT);
	mlx_string_put(mlx->mlx, mlx->win, 25, y += 20 , color
			, MOVEMENT1);
	mlx_string_put(mlx->mlx, mlx->win, 25, y += 20 , color
			, " Revers Move:");
	mlx_string_put(mlx->mlx, mlx->win, 30, y += 20 , color
			, R_MOVEMENT);
	mlx_string_put(mlx->mlx, mlx->win, 30, y += 20 , color
			, R_MOVEMENT1);
	mlx_string_put(mlx->mlx, mlx->win, 30, y += 20 , color
			, " Z shift:");
	mlx_string_put(mlx->mlx, mlx->win, 30, y += 20 , color
			, Z_SHIFT);
	mlx_string_put(mlx->mlx, mlx->win, 30, y += 20 , color
			, Z_SHIFT1);
	mlx_string_put(mlx->mlx, mlx->win, 30, y += 20 , color
			, " Zoom in/out:");
	mlx_string_put(mlx->mlx, mlx->win, 30, y += 20 , color
			, ZOOM_IN_OUT);
}

void background(t_mlx *mlx)
{
	int i;

	i = 0;
	while(i < HEIGHT * WIDTH)
	{
		if(i % WIDTH < MENU_WIDHT)
			mlx->img.data[i] = VERY_DARK_GRAY;
		else
			mlx->img.data[i] = BLACK;
		i++;
	}
}
