//
// Created by Emilee Florean on 19/12/2019.
//

#include "fdf.h"

static void ft_swap(int *x1, int *x2)
{
  int tmp;

  tmp = *x1;
  *x1 = *x2;
  *x2 = tmp;
}

static void vertical(int x1, int y1, int y2, void *mlx, void *win)
{
  if (y1 > y2)
    ft_swap(&y1, &y2);
  while (y1 < y2)
  {
    mlx_pixel_put(mlx, win, x1, y1, 0xFF15a2);
    y1++;
  }
}

void draw_line(int x1, int y1, int x2, int y2, void *mlx, void *win)
{
    int dx;
    int dy;
    int x;
    int y;

    if (x1 > x2)
    {
      ft_swap(&x1, &x2);
      ft_swap(&y1, &y2);
    }
    if (x1 == x2)
      vertical(x1, y1, y2, mlx, win);
    else
    {
    x = x1;
    dx = x2 - x1;
    dy = y2 - y1;
      while (x <= x2)
      {
	y = y1 + dy * (x - x1) / dx;
	mlx_pixel_put(mlx, win, x, y, 0xFF15a2);
	x++;
      }
    }
}
