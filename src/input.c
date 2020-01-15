#include "../includes/fdf.h"

void save_color(char *a, t_mlx *mlx)
{
	printf("%s\n", a);
	mlx->cam.color = ft_htoi(a);
	printf("%d\n", ft_htoi(a));
}

int check_digit(char *a, t_mlx *mlx)
{
	char *p;

	while (*a != '\0' && *a != ',')
	{
		if (!ft_isdigit(*a) && *a != '-' && *a != '+')
			return (0);
		if ((p = ft_strchr(a, ',')))
			save_color(p + 1, mlx);
		a++;
	}
	return (1);
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

t_point	*point_new(int x, int y, int z, t_mlx *mlx)
{
	t_point *p;

	p = (t_point *)malloc(sizeof(t_point));
	p->x = x;
	p->y = y;
	p->z = z;
	p->next = NULL;
	(*p).color = mlx->cam.color;
	mlx->cam.color = 0xEEE8AA;
	return (p);
}

int		temp(char **a, int y, t_point **pt, t_mlx *mlx)
{
	static int w;
	t_point *tmp;
	int x;

	x = 0;
	while (a[x])
	{
		if (!check_digit(a[x], mlx))
			return (0);
		tmp = point_new(x, y, ft_atoi(a[x]), mlx);
		if (*pt != NULL)
		{
			(*pt)->next = tmp;
			*pt = (*pt)->next;
		}
		else
		{
			*pt = point_new(x, y, ft_atoi(a[x]), mlx);
			mlx->scn = *pt;
		}
		x++;
	}
	((w == 0) ? (w = x) : (w));
	return ((w != x) ? 0 : w);
}

int	input(int fd, t_mlx *mlx)
{
	char *line;
	char **a;
	int y;
	t_point *pt;

	pt = NULL;
	y = 0;
	while ((get_next_line(fd, &line)) != 0)
	{
		a = ft_strsplit(line, ' ');
		if (!temp(a, y, &pt, mlx))
			return (0);
		dfree(a);
		free(line);
		y++;
	}
	free(line);
	make_matrix(mlx, y);
	return (1);
}

/*
int main(int ac, char **av)
{
	t_mlx mlx;
	int fd;

	init(&mlx);
	if (ac != 2)
	{
		ft_putstr("error: not enough arguments");
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	printf("%d\n", input(fd, &mlx));
	free_mtr(&mlx);
	return (0);
}
*/