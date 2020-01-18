/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 15:42:19 by eflorean          #+#    #+#             */
/*   Updated: 2020/01/18 15:42:20 by eflorean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static	int		save_color(char *a, t_mlx *mlx)
{
	if (!(mlx->cam.color = ft_htoi(a)))
		return (0);
	return (1);
}

static	int		check_digit(char *a, t_mlx *mlx)
{
	char *p;

	while (*a != '\0' && *a != ',')
	{
		if (!ft_isdigit(*a) && *a != '-' && *a != '+')
			return (0);
		if ((p = ft_strchr(a, ',')))
		{
			if (!(save_color(p + 1, mlx)))
				return (0);
		}
		a++;
	}
	return (1);
}

static	void	dfree(char **a)
{
	while (*a)
	{
		free(*a);
		a++;
	}
	a = NULL;
}

static	t_point	*point_new(int x, int y, int z, t_mlx *mlx)
{
	t_point *p;

	if (!(p = (t_point *)malloc(sizeof(t_point))))
		die("malloc error");
	p->x = x;
	p->y = y;
	p->z = z;
	p->next = NULL;
	if (mlx->cam.color != 0)
		(*p).color = mlx->cam.color;
	else if (z != 0)
		(*p).color = 0xF98C61 + z * 10;
	else
		(*p).color = 0x66151C;
	mlx->cam.color = 0;
	return (p);
}

static	int		temp(char **a, int y, t_point **pt, t_mlx *mlx)
{
	static int	w;
	t_point		*tmp;
	int			x;

	x = 0;
	while (a[x])
	{
		if (!check_digit(a[x], mlx))
			return (0);
		tmp = point_new(x, y, ft_atoi(a[x]), mlx);
		if (*pt != NULL)
		{
			(*pt)->next = tmp;
			*pt = (*pt)->next;
		}
		else
		{
			*pt = point_new(x, y, ft_atoi(a[x]), mlx);
			mlx->scn = *pt;
		}
		x++;
	}
	((w == 0) ? (w = x) : (w));
	return ((w != x) ? 0 : w);
}

int			input(int fd, t_mlx *mlx)
{
	char	*line;
	char	**a;
	int		y;
	t_point	*pt;

	pt = NULL;
	y = 0;
	while ((get_next_line(fd, &line)) != 0)
	{
		a = ft_strsplit(line, ' ');
		if (!temp(a, y, &pt, mlx))
			return (0);
		dfree(a);
		free(line);
		y++;
	}
	free(line);
	make_matrix(mlx, y);
	return (1);
}
