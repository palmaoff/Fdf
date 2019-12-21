/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 13:47:20 by eflorean          #+#    #+#             */
/*   Updated: 2019/12/18 14:13:45 by eflorean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		hook_keydown(int key)
{
	if (key == 53)
		exit(1);
	return (0);
}

int hook_mouse(int button, int x, int y, t_point *p)
{

  if (p->x == 0 && p->y == 0)
  {
    p->x = x;
    p->y = y;
    return (0);
  }
  if (button == 1)
  {
    draw_line(p->x, p->y, x, y, p->mlx, p->win);
    p->x = x;
    p->y = y;
  }
  return (0);
}

t_point *intit(void *mlx, void *win)
{
  t_point *p;

  p = malloc(sizeof(t_point));
  p->mlx = mlx;
  p->win = win;
  p->x = 0;
  p->y = 0;
  return (p);
}

int main()
{
	void *mlx;
	void *win;
	t_point *p;

	printf("%d\n", atoi(" 123 123"));
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1000, 1000, "42");
	p = intit(mlx, win);
	mlx_key_hook(win, hook_keydown, mlx);
	mlx_mouse_hook(win, hook_mouse, p);
	mlx_loop(mlx);
	return (0);
}
