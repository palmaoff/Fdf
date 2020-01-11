#include "fdf.h"

void	move_it(t_mlx *mlx, int x)
{
	int i;
	int j;

	mlx_destroy_image(mlx->mlx, (*mlx).img.img_ptr);
	img_new(mlx);
	i = 0;
	while (i < mlx->p.y)
	{
		j = 0;
		while (j <= mlx->p.x)
		{
			if (x == 1 || x == -1)
				(mlx->mtrx)[i][j].y += 5 * x;
			else if (x == 2 || x == -2)
				(mlx->mtrx)[i][j].x += 5 * x / 2;
			else if (x == 3 || x == -3)
				(mlx->mtrx)[i][j].y += (mlx->mtrx)[i][j].z * x / 3;
			else if (x == 4 || x == -4)
			{
				(mlx->mtrx)[i][j].x *= x / 2;
				(mlx->mtrx)[i][j].y *= x / 2;
			}
			if ((mlx->mtrx)[i][j].x > 0 && (mlx->mtrx)[i][j].y > 0 && (mlx->mtrx)[i][j].y < WIDTH && (mlx->mtrx)[i][j].x < HEIGHT)
				mlx->img.data[((mlx->mtrx)[i][j].y) * WIDTH + ((mlx->mtrx)[i][j].x)] = 0xFF15a2;
			j++;
		}
		i++;
	}
	lines(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img_ptr, 0, 0);
}

void	zoom_it(t_mlx *mlx, int x)
{

	mlx_destroy_image(mlx->mlx, (*mlx).img.img_ptr);
	img_new(mlx);
	x = 0;
	mlx->cam.x += 10;
//	print_map(mlx);
//	lines(mlx);
//	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img_ptr, 0, 0);
}