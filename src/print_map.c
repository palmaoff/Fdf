/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 15:54:10 by eflorean          #+#    #+#             */
/*   Updated: 2020/01/18 15:54:11 by eflorean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void	iso(t_point *scrn, t_mlx *mlx)
{
	int	pre_x;
	int	pre_y;

	scrn->x *= mlx->cam.z;
	scrn->z *= mlx->cam.z;
	scrn->y *= mlx->cam.z;
	pre_x = scrn->x;
	pre_y = scrn->y;
	scrn->x = pre_x + mlx->cam.x;
	scrn->y = pre_y + mlx->cam.y;
}

static	void	screen_map(t_point *scn, t_point *scrn, t_mlx *mlx)
{
	scrn->x = scn->x;
	scrn->y = scn->y;
	scrn->z = scn->z * mlx->cam.di;
	scrn->color = scn->color + mlx->cam.d_color;
}

void			print_map(t_mlx *mlx)
{
	int i;
	int j;

	background(mlx);
	i = 0;
	while (i < mlx->p.y)
	{
		j = 0;
		while (j <= mlx->p.x)
		{
			screen_map(&(mlx->mtrx)[i][j], &(mlx->scrn)[i][j], mlx);
			rotate(mlx, i, j);
			iso(&(mlx->scrn)[i][j], mlx);
			j++;
		}
		i++;
	}
	lines(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img_ptr, 0, 0);
	print_menu(mlx);
}
