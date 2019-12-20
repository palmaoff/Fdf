//
// Created by Emilee Florean on 19/12/2019.
//

#include "fdf.h"

void draw_line(int x1, int y1, int x2, int y2, void *mlx, void *win)
{
    int dx;
    int dy;
    int x;
    int y;

    x = x1;
    dx = abs(x2 - x1);
    dy = abs(y2 - y1);

    while (x <= x2)
    {
        y = y1 + dy * (x - x1) / dx;
        mlx_pixel_put(mlx, win, x, y, 0xFF15a2);
        x++;
    }
}
