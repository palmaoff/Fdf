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

static void connect(t_mlx *mlx, int h, int w)
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
			mlx->mtrx[i][j].y -= h / 2;
			tmp = tmp->next;
			j++;
		}
		i++;
	}
}
/*
static	void make_rotate_matrix(t_mlx *mlx)
{
	int i;
	int j;

	i = 0;
	mlx->xr = (int **)malloc(sizeof(t_point *) * mlx->p.y);
	while (i < mlx->p.y)
	{
		(mlx->xr)[i] = (int *)malloc(sizeof(t_point ) * (mlx->p.x + 1));
		j = 0;
		while (j <= mlx->p.x)
		{
			if (i == j)
				(mlx->xr)[i][j] = 1;
			if ((j == mlx->p.x && i == (mlx->p.y - 1)) || (j == (mlx->p.x - 1) && i == (mlx->p.y - 2)))
				(mlx->xr)[i][j] = cos(0.46373398);
			if (j == (mlx->p.x - 1) && i == (mlx->p.y - 1))
				(mlx->xr)[i][j] = sin(0.46373398);
			if (j == (mlx->p.x) && i == (mlx->p.y - 2))
				(mlx->xr)[i][j] = -sin(0.46373398);
			j++;
		}
		i++;
	}
}
*/
void	make_matrix(t_mlx *mlx, int h)
{
	int w;
	int i;

	i = 0;
	w = how_long(mlx->scn);
	mlx->p.x = w;
	mlx->p.y = h;
	mlx->mtrx = (t_point **)malloc(sizeof(t_point *) * h);
	mlx->scrn = (t_point **)malloc(sizeof(t_point *) * h);
	while (i < h)
	{
		(mlx->mtrx)[i] = (t_point *)malloc(sizeof(t_point ) * (w + 1));
		(mlx->scrn)[i] = (t_point *)malloc(sizeof(t_point ) * (w + 1));
		i++;
	}
//	make_rotate_matrix(mlx);
	connect(mlx, mlx->p.y, mlx->p.x);
}