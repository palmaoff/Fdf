#include "fdf.h"

static void iso(t_point *scrn)
{
    int pre_x;
    int pre_y;

    pre_x = scrn->x;
    pre_y = scrn->y;
    scrn->x = (pre_x - pre_y) * cos(0.46373398) + 200;
    scrn->y = -(scrn->z) + (pre_x + pre_y) * sin(0.46373398) + 200;
}

static void screen_map(t_point *scn, t_point *scrn)
{
    scrn->x = scn->x * 20;
	scrn->y = scn->y * 20;
	scrn->z = scn->z * 2;
}

void	print_map(t_mlx *mlx)
{
	int i;
	int j;

	i = 0;
	while(i < mlx->p.y)
	{
		j = 0;
		while (j <= mlx->p.x)
		{
			printf("%d %d %d\n", (mlx->mtrx)[i][j].x, (mlx->mtrx)[i][j].y, (mlx->mtrx)[i][j].z);
			screen_map(&(mlx->mtrx)[i][j], &(mlx->scrn)[i][j]);
			iso(&(mlx->scrn)[i][j]);
			if ((mlx->scrn)[i][j].x > 0 && (mlx->scrn)[i][j].y > 0 && (mlx->scrn)[i][j].y < WIDTH && (mlx->scrn)[i][j].x < HEIGHT)
				mlx->img.data[((mlx->scrn)[i][j].y) * WIDTH + ((mlx->scrn)[i][j].x)] = 0xFF15a2;
			j++;
		}
		i++;
	}
	lines(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img_ptr, 0, 0);
}