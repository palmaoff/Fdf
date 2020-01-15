#include "fdf.h"

static void ft_swap(t_point *x1, t_point *x2)
{
	t_point tmp;

	tmp = *x1;
	*x1 = *x2;
	*x2 = tmp;
}

static	void	draw_y(t_point p1, t_point p2, t_mlx *mlx, int b)
{
	int x;
	int y;
	int dx;
	int dy;

	if (p1.y > p2.y)
	{
    	ft_swap(&p1, &p2);
		b = 1;
	}
	y = (int)p1.y;
	dx = (int)p2.x - p1.x;
	dy = (int)p2.y - p1.y;
	while(y < p2.y && dy != 0)
	{
		x = (int)p1.x + dx * (y - (int)p1.y) / dy;
		if (x > 0 && y > 0 && x < WIDTH && y < HEIGHT)
			mlx->img.data[y * WIDTH + x] = mlx->p.color;
		y++;
	}
	if (b == 1)
    	ft_swap(&p1, &p2);
}

static	void	draw_x(t_point p1, t_point p2, t_mlx *mlx, int b)
{
	int x;
	int y;
	int dx;
	int dy;

	if (p1.x > p2.x)
    {
    	ft_swap(&p1, &p2);
		b = 1;
	}
	x = (int)p1.x;
	dx = (int)p2.x - p1.x;
	dy = (int)p2.y - p1.y;
	while(x < p2.x && dx != 0)
	{
		y = (int)p1.y + dy * (x - (int)p1.x) / dx;
		if (x > 0 && y > 0 && x < WIDTH && y < HEIGHT)
			mlx->img.data[y * WIDTH + x] = mlx->p.color;
		x++;
	}
	if (b == 1)
    	ft_swap(&p1, &p2);
}

void	draw_line(t_point p1, t_point p2, t_mlx *mlx)
{
	int dx;
	int dy;

	if (p1.color == p2.color)
		mlx->p.color = p1.color;
	else
		mlx->p.color = 0xEEE8AA;
	
	dx = (int)(p2.x - p1.x);
	dy = (int)(p2.y - p1.y);
	if (abs(dx) < abs(dy))
		draw_y(p1, p2, mlx, 0);
	else
		draw_x(p1, p2, mlx, 0);
}