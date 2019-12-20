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

int hook_mouse(int button, int x, int y, void *param)
{
  printf("%d\n", button);
//  draw_line(0, 0, x, y);
  return (0);
}

int main()
{
	void *mlx;
	void *win;

	printf("s");
	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "42");
	draw_line(100, 50, 100, 10, mlx, win);
	mlx_key_hook(win, hook_keydown, mlx);
	mlx_mouse_hook(win, hook_mouse, mlx);
	mlx_loop(mlx);
	return (0);
}
