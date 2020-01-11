//
// Created by Emilee Florean on 20/12/2019.
//

#ifndef FDF_H
# define FDF_H
# define WIDTH 800
# define HEIGHT 800

# include "mlx.h"
# include <unistd.h>
# include <stdio.h> // KILL ME
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "get_next_line.h"
# include "../libft/libft.h"

typedef struct	s_img
{
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct  s_point
{
    int			x;
    int			y;
    int			z;
    struct  	s_point *next;
}               t_point;

typedef struct  s_cam
{
    double		x;
    double		y;
    double		z;
	double		di;
}               t_cam;

typedef struct  s_mlx
{
    void		*mlx;
    void		*win;
    t_img		img;
    t_cam		cam;
    t_point		p;
    t_point		*scn;
    t_point		**scrn;
    t_point		**mtrx;
}               t_mlx;

void	draw_line(int x1, int y1, int x2, int y2, t_mlx *mlx);
void	img_new(t_mlx *mlx);
int		input(int fd, t_mlx *mlx);
void	print_map(t_mlx *mlx);
void	make_matrix(t_mlx *mlx, int h);
void	lines(t_mlx *mlx);
void	free_mtr(t_mlx *mlx);
void	move_it(t_mlx *mlx, int x);
void	zoom_it(t_mlx *mlx, int x);
void	print(t_mlx *mlx);

#endif
