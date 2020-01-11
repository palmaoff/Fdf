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
			if (i < mlx->p.y - 1)
				draw_line(((mlx->scrn)[i][j].x), ((mlx->scrn)[i][j].y), ((mlx->scrn)[i + 1][j].x), ((mlx->scrn)[i + 1][j].y), mlx);
			if (j < mlx->p.x)
				draw_line(((mlx->scrn)[i][j].x), ((mlx->scrn)[i][j].y), ((mlx->scrn)[i][j + 1].x), ((mlx->scrn)[i][j + 1].y), mlx);
			j++;
		}
		i++;
	}
}