#include "fdf.h"

static int how_long(t_point *p)
{
	int i;

	i = 0;
	if (p->next != NULL)
		p = p->next;
	while (p->x != 0 && p != NULL)
	{
		p = p->next;
		i++;
	}
	return (i);
}

static void connect(t_mlx *mlx, float h, float w)
{
	int i;
	int j;
	t_point *tmp; 

	tmp = mlx->scn;
	i = 0;
	while (i < h)
	{
		j = 0;
		while (j <= w)
		{
			mlx->mtrx[i][j] = *tmp;
			mlx->mtrx[i][j].x -= w / 2;
			mlx->mtrx[i][j].y -= (h - 1) / 2;
			mlx->mtrx[i][j].color = tmp->color;
			tmp = tmp->next;
			j++;
		}
		i++;
	}
}

void	make_matrix(t_mlx *mlx, float h)
{
	float w;
	int i;

	i = 0;
	w = how_long(mlx->scn);
	mlx->p.x = w;
	mlx->p.y = h;
	if (!(mlx->mtrx = (t_point **)malloc(sizeof(t_point *) * h)))
		die("malloc error\n");
	if (!(mlx->scrn = (t_point **)malloc(sizeof(t_point *) * h)))
		die("malloc error\n");
	while (i < h)
	{
		if (!((mlx->mtrx)[i] = (t_point *)malloc(sizeof(t_point ) * (w + 1))))
			die("malloc error\n");
		if (!((mlx->scrn)[i] = (t_point *)malloc(sizeof(t_point ) * (w + 1))))
			die("malloc error\n");
		i++;
	}
	connect(mlx, mlx->p.y, mlx->p.x);
}