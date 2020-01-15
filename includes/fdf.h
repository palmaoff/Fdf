//
// Created by Emilee Florean on 20/12/2019.
//

#ifndef FDF_H
# define FDF_H
# define WIDTH 1280
# define HEIGHT 720

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
    float			x;
    float			y;
    float			z;
	int 			color;
    struct	s_point	*next;
}               t_point;

typedef struct  s_cam
{
    float		x;
    float		y;
    float		z;
	float		x_r;
	float		y_r;
	float		z_r;
	float		di;
	int			color;
}               t_cam;

typedef struct  s_mlx
{
    void		*mlx;
    void		*win;
    t_img		img;
    t_cam		cam;
    t_point		p;
    t_point		*scn;
	t_point		**mtrx;
    t_point		**scrn;
}               t_mlx;

void	draw_line(t_point p1, t_point p2, t_mlx *mlx);
void	img_new(t_mlx *mlx);
int		input(int fd, t_mlx *mlx);
void	print_map(t_mlx *mlx);
void	make_matrix(t_mlx *mlx, int h);
void	lines(t_mlx *mlx);
void	free_mtr(t_mlx *mlx);
void	move_it(t_mlx *mlx, int x);
void	zoom_it(t_mlx *mlx, int x);
void	print(t_mlx *mlx);
void	rotate(t_mlx *mlx, int i, int j);
void	print_points(t_point *strt); // tmp
int     ft_htoi(const char *hex);
#endif
