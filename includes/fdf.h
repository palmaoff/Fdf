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
# define WIDTH 2048
# define HEIGHT 1080
# define MENU_WIDHT 300

/*
** Default Colors
*/

# define HELL 0x3F27D9
# define TOP 0x47C52E

/*
** Colors
*/

# define WHITE 0xffffff
# define BLACK 0x000000
# define RED 0xe80c0c
# define MIDDLE_GRAY 0x7a7a7a
# define VERY_DARK_GRAY 0x0d0d0d
# define ORANGE 0xFFA500
# define MANN_CO_ORANGE 0xCF7336
# define AUSTRALIUM_GOLD 0xE7B53B

/*
** Keys
*/

# define M 46
# define MLB 1
# define MRB 2

/*
** Menu
*/

# define MOVEMENT "   Up/Down/Left/Right"
# define MOVEMENT1 "   Ar.Up/Ar.Down/Ar.L/Ar.R"
# define R_MOVEMENT "   Up/Down/Left/Right"
# define R_MOVEMENT1 "   Ar.Down/Ar.Up/Ar.R/Ar.L"
# define Z_SHIFT "   Z-/Z+"
# define Z_SHIFT1 "   Z/X"
# define ZOOM_IN_OUT "   (numpad)+/-|(m. wheel)"
# define ROTATION_X "   X:(numpad) 6/3"
# define ROTATION_Y "   Y:(numpad) 1/2"
# define ROTATION_Z "   Z:(numpad) 4/5"
# define ROTATION_M "   MLB->Hold&move"
# define RESET_BTN "   (numpad) 0"
# define PROJ_I "   Iso: I"
# define PROJ_C "   Con: C"
# define PROJ_P "   Paral: P"
# define COLOR_CH " (top_r) -/+"

/*
** Other
*/

# include "mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "get_next_line.h"
# include "../libft/libft.h"

typedef struct		s_mouse
{
	int				old_x;
	int				old_y;
	int				x;
	int				y;
	int				pressed;
}					t_mouse;

typedef struct		s_img
{
	void			*img_ptr;
	int				*data;
	int				size_l;
	int				bpp;
	int				endian;
}					t_img;

typedef	struct		s_point
{
	float			x;
	float			y;
	float			z;
	int				color;
	struct s_point	*next;
}					t_point;

typedef	struct		s_dot
{
	int				x;
	int				y;
}					t_dot;

typedef	struct		s_cam
{
	float			x;
	float			y;
	float			z;
	float			x_r;
	float			y_r;
	float			z_r;
	float			di;
	int				color;
	int				d_color;
}					t_cam;

typedef	struct		s_mlx
{
	char			*file;
	void			*mlx;
	void			*win;
	t_mouse			mouse;
	t_img			img;
	t_cam			cam;
	t_point			p;
	t_point			*scn;
	t_point			**mtrx;
	t_point			**scrn;
}					t_mlx;

void				draw_line(t_point p1, t_point p2, t_mlx *mlx);
void				img_new(t_mlx *mlx);
int					input(int fd, t_mlx *mlx);
void				print_map(t_mlx *mlx);
void				make_matrix(t_mlx *mlx, float h);
void				lines(t_mlx *mlx);
void				free_mtr(t_mlx *mlx);
void				move_it(t_mlx *mlx, int x);
void				zoom_it(t_mlx *mlx, int x);
void				print(t_mlx *mlx);
void				rotate(t_mlx *mlx, int i, int j);
int					ft_htoi(const char *hex);
int					get_color(t_dot current, t_point start,
					t_point end, t_dot delta);
void				print_menu(t_mlx *mlx);
void				background(t_mlx *mlx);
int					key_press(int keycode, t_mlx *mlx);
void				die(char *str);
int					hook_mouse(int button, int x, int y, t_mlx *mlx);
int					mouse_move(int x, int y, void *param);
int					mouse_release(int button, int x, int y, void *param);

#endif
