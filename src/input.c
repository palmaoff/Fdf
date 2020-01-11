#include "fdf.h"

void	print_points(t_point *strt)
{
	while (strt != NULL)
	{
		printf("x: %d y: %d z: %d\n", strt->x, strt->y, strt->z);
		strt = strt->next;
	}
}

void dfree(char **a)
{
	while (*a)
	{
		free(*a);
		a++;
	}
	a = NULL;
}

t_point	*point_new(int x, int y, int z)
{
	t_point *p;

	p = (t_point *)malloc(sizeof(t_point));
	p->x = x;
	p->y = y;
	p->z = z;
	p->next = NULL;
	return (p);
}

int		temp(char **a, int y, t_point **pt, t_point **strt)
{
	static int w;
	t_point *tmp;
	int x;

	x = 0;
	while (a[x])
	{
		tmp = point_new(x, y, ft_atoi(a[x]));
		if (*pt != NULL)
		{
			(*pt)->next = tmp;
			*pt = (*pt)->next;
		}
		else
		{
			*pt = point_new(x, y, ft_atoi(a[x]));
			*strt = *pt;
		}
		x++;
	}
	if (w == 0)
		w = x;
	else if (w != x)
		return (0);
	return (w);
}

int	input(int fd, t_mlx *mlx)
{
	char *line;
	char **a;
	int y;
	t_point *pt;;

	pt = NULL;
	y = 0;
	while ((get_next_line(fd, &line)) != 0)
	{
		a = ft_strsplit(line, ' ');
		if (temp(a, y, &pt, &mlx->scn) == 0)
			return (0);
		dfree(a);
		free(line);
		y++;
	}
	free(line);
	make_matrix(mlx, y);
	return (1);
}