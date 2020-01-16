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
	t_dot dlt;
	t_dot crnt;
	// int x;
	// int y;
	// int dx;
	// int dy;

	if (p1.y > p2.y)
	{
    	ft_swap(&p1, &p2);
		b = 1;
	}
	crnt.y = (int)p1.y;
	dlt.x = (int)p2.x - p1.x;
	dlt.y = (int)p2.y - p1.y;
	while(crnt.y < p2.y && dlt.y != 0)
	{
		crnt.x = (int)p1.x + dlt.x * (crnt.y - (int)p1.y) / dlt.y;
		if (crnt.x >= MENU_WIDHT && crnt.y > 0 && crnt.x < WIDTH && crnt.y < HEIGHT)
			mlx->img.data[crnt.y * WIDTH + crnt.x] = get_color(crnt, p1, p2, dlt);
		crnt.y++;
	}
	if (b == 1)
    	ft_swap(&p1, &p2);
}

static	void	draw_x(t_point p1, t_point p2, t_mlx *mlx, int b)
{
	t_dot dlt;
	t_dot crnt;
//	int x;
//	int y;
//	int dx;
//	int dy;

	if (p1.x > p2.x)
    {
    	ft_swap(&p1, &p2);
		b = 1;
	}
	crnt.x = (int)p1.x;
	dlt.x = (int)p2.x - p1.x;
	dlt.y = (int)p2.y - p1.y;
	while(crnt.x < p2.x && dlt.x != 0)
	{
		crnt.y = (int)p1.y + dlt.y * (crnt.x - (int)p1.x) / dlt.x;
		if (crnt.x >= MENU_WIDHT && crnt.y > 0 && crnt.x < WIDTH && crnt.y < HEIGHT)
			mlx->img.data[crnt.y * WIDTH + crnt.x] = get_color(crnt, p1, p2, dlt);
		crnt.x++;
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