#include "fdf.h"

static void ft_swap(int *x1, int *x2)
{
	int tmp;

	tmp = *x1;
	*x1 = *x2;
	*x2 = tmp;
}

static	void	draw_y(int x1, int y1, int x2, int y2, t_mlx *mlx)
{
	int x;
	int y;
	int dx;
	int dy;

	if (y1 > y2)
    {
      ft_swap(&x1, &x2);
      ft_swap(&y1, &y2);
    }
	y = y1;
	dx = x2 - x1;
	dy = y2 - y1;
	while(y <= y2 && dy != 0)
	{
		x = x1 + dx * (y - y1) / dy;
		if (x > 0 && y > 0 && x < WIDTH && y < HEIGHT)
			mlx->img.data[y * WIDTH + x] = 0xFF15a2;
		y++;
	}
}

static	void	draw_x(int x1, int y1, int x2, int y2, t_mlx *mlx)
{
	int x;
	int y;
	int dx;
	int dy;

	if (x1 > x2)
    {
      ft_swap(&x1, &x2);
      ft_swap(&y1, &y2);
    }
	x = x1;
	dx = x2 - x1;
	dy = y2 - y1;
	while(x <= x2 && dx != 0)
	{
		y = y1 + dy * (x - x1) / dx;
		if (x > 0 && y > 0 && x < WIDTH && y < HEIGHT)
			mlx->img.data[y * WIDTH + x] = 0xFF15a2;
		x++;
	}
}

void	draw_line(int x1, int y1, int x2, int y2, t_mlx *mlx)
{
	int dx;
	int dy;

	dx = x2 - x1;
	dy = y2 - y1;
	if (abs(dx) >= abs(dy))
		draw_x(x1, y1, x2, y2, mlx);
	else
		draw_y(x1, y1, x2, y2, mlx);
}