#include "fdf.h"

static void iso(t_point *scrn, t_mlx *mlx)
{
    int pre_x;
    int pre_y;

	scrn->x *= mlx->cam.z;
	scrn->z *= mlx->cam.z;
	scrn->y *= mlx->cam.z;
    pre_x = scrn->x;
    pre_y = scrn->y;
    scrn->x = (pre_x - pre_y) * cos(0.46373398) + mlx->cam.x;
    scrn->y = -scrn->z + (pre_y + pre_x) * sin(0.46373398) + mlx->cam.y;
}

static void screen_map(t_point *scn, t_point *scrn, t_mlx *mlx)
{
    scrn->x = scn->x;
	scrn->y = scn->y;
	scrn->z = scn->z * mlx->cam.di;
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
			rotate(mlx, i, j);
			iso(&(mlx->scrn)[i][j], mlx);
			j++;
		}
		i++;
	}
	lines(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img_ptr, 0, 0);
}