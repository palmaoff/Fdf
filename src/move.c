#include "fdf.h"

void	move_it(t_mlx *mlx, int x)
{

	mlx_destroy_image(mlx->mlx, (*mlx).img.img_ptr);
	img_new(mlx);
	if (x == 1 || x == -1)
		mlx->cam.y += 5 * x;
	else if (x == 2 || x == -2)
		mlx->cam.x += 5 * x / 2;
	else if (x == 3 || x == -3)
		mlx->cam.di += 0.1 * x / 3;
	else if (x == 4 || x == -4)
	{
		if (x > 0 || mlx->cam.z > 0)
			mlx->cam.z += x / 4;
	}
	print_map(mlx);
}