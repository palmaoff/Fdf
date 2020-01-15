#include "fdf.h"

void lines(t_mlx *mlx)
{
	int i;
	int j;

	i = 0;
	while(i < mlx->p.y)
	{
		j = 0;
		while (j <= mlx->p.x)
		{
			if (j < mlx->p.x)
				draw_line((mlx->scrn)[i][j], (mlx->scrn)[i][j + 1], mlx);
			if (i < mlx->p.y - 1)
				draw_line((mlx->scrn)[i][j], (mlx->scrn)[i + 1][j], mlx);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img_ptr, 0, 0);
}