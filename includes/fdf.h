/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 21:13:58 by wquirrel          #+#    #+#             */
/*   Updated: 2020/01/15 21:14:02 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WIDTH 1280
# define HEIGHT 720

# define WHITE 0xffffff;
# define BLACK 0x000000;
# define RED 0xe80c0c;

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

typedef struct  s_dot
{
    int			x;
    int			y;
}               t_dot;

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
void	make_matrix(t_mlx *mlx, float h);
void	lines(t_mlx *mlx);
void	free_mtr(t_mlx *mlx);
void	move_it(t_mlx *mlx, int x);
void	zoom_it(t_mlx *mlx, int x);
void	print(t_mlx *mlx);
void	rotate(t_mlx *mlx, int i, int j);
void	print_points(t_point *strt); // tmp
int     ft_htoi(const char *hex);
int 	get_color(t_dot current, t_point start, t_point end, t_dot delta);
#endif
