//
// Created by Emilee Florean on 20/12/2019.
//

#ifndef FDF_H
#define FDF_H

# include "../minilibx_macos/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "libft.h"

void draw_line(int x1, int y1, int x2, int y2, void *mlx, void *win);

typedef struct  s_point
{
    int     x;
    int     y;
    void    *mlx;
    void    *win;
}               t_point;

typedef struct  s_mlx
{
    int    **mtrx;
    void    *mlx;
    void    *win;
}               t_mlx;

#endif
