/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 15:36:07 by eflorean          #+#    #+#             */
/*   Updated: 2020/01/18 15:36:12 by eflorean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static	void	free_lists(t_point *strt)
{
	t_point *tmp;

	while (strt->next != NULL)
	{
		tmp = strt;
		strt = strt->next;
		free(tmp);
	}
}

void			free_mtr(t_mlx *mlx)
{
	int i;

	i = 0;
	while (i < mlx->p.y)
	{
		free((mlx->mtrx)[i]);
		free((mlx->scrn)[i]);
	}
	free(mlx->mtrx);
	free(mlx->scrn);
	free_lists(mlx->scn);
}
