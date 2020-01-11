#include "fdf.h"

static void iso(t_point *scrn, t_mlx *mlx)
{
    int pre_x;
    int pre_y;

	scrn->z *= mlx->cam.di;
	scrn->z += mlx->cam.z;
    pre_x = scrn->x;
    pre_y = scrn->y;
    scrn->x = (pre_x - pre_y) * cos(0.46373398) + mlx->cam.x;
    scrn->y = -(scrn->z) + (pre_x + pre_y) * sin(0.46373398) + mlx->cam.y;
}

static void screen_map(t_point *scn, t_point *scrn, t_mlx *mlx)
{
    scrn->x = scn->x * mlx->cam.z;
	scrn->y = scn->y * mlx->cam.z;
	scrn->z = scn->z * mlx->cam.z;
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
			screen_map(&(mlx->mtrx)[i][j], &(mlx->scrn)[i][j], mlx);
			iso(&(mlx->scrn)[i][j], mlx);
			if ((mlx->scrn)[i][j].x > 0 && (mlx->scrn)[i][j].y > 0 && (mlx->scrn)[i][j].y < WIDTH && (mlx->scrn)[i][j].x < HEIGHT)
				mlx->img.data[((mlx->scrn)[i][j].y) * WIDTH + ((mlx->scrn)[i][j].x)] = 0xFF15a2;
			j++;
		}
		i++;
	}
	lines(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img_ptr, 0, 0);
}