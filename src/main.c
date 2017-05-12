/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 10:49:39 by qho               #+#    #+#             */
/*   Updated: 2017/05/12 11:09:21 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void draw(void *mlx, void *win)
{
	int x;
	int y;

	y = 100;
	while (y < 200)
	{
		x = 100;
		while (x < 200)
		{
			mlx_pixel_put(mlx, win, x, y, 0xFF00FF);
			x++;
		}
		y++;
	}
}

int expose_hook(t_env *e)
{
	draw(e->mlx, e->win);
	return (0);
}

int key_hook(int keycode, t_env *e)
{
	(void) *e;
	printf("key: %d\n", keycode);
	if (keycode == 53)
		exit (0);
	return (0);
}

int mouse_hook(int button, int x, int y, t_env *e)
{
	(void) *e;
	printf("mouse: %d (%d:%d)\n", button, x, y);
	return (0);
}

int		ft_load_raw_points(char *line, t_map *map)
{
	// printf("loading points\n");
	static int	pt_idx = 0;
	static int	row = 1;
	char		**values;
	int			val_idx;

	val_idx = 0;
	values = ft_strsplit(line, ' ');
	while (values[val_idx])
	{
		map->point[pt_idx].x = val_idx + 1;
		map->point[pt_idx].y = row;
		map->point[pt_idx].z = atoi(values[val_idx]);
		pt_idx++;
		val_idx++;
	}
	map->m_width = map->point[pt_idx].x;
	map->m_height = row;
	row++;
	free(values);
	return (0);
}

int		ft_get_map(char *filename, t_map *map)
{
	// printf("getting map?\n");
	char	buf[BUFF_SIZE + 1];
	int		fd;
	char	*line;

	ft_bzero((void *)buf, sizeof(char) * (BUFF_SIZE + 1));
	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		ft_load_raw_points(line, map);
		free(line);
	}
	if (get_next_line(fd, &line) == -1)
		return (-1);
	return (0);
}

void	ft_map_init(t_map *map)
{
	int		idx;

	idx = -1;
	// map->mlx = mlx_init();
	// map->window = mlx_new_window(map->mlx, 500, 500, "fdf");
	map->m_width = 0;
	map->m_height = 0;
	while (++idx < 90000)
	{
		ft_memset((void *)&map->point[idx], 0, sizeof(t_pt));
		// map->point[idx].x = 0;
		// map->point[idx].y = 0;
		// map->point[idx].z = 0;
	}
}

void	ft_print_map(t_map map)
{
	int		idx;
	int		y;

	idx = 0;
	y = map.point[idx].y;
	while (map.point[idx].x != 0)
	{
		if (map.point[idx].y != y)
		{
			y = map.point[idx].y;
			ft_putchar('\n');
		}
		ft_putnbr(map.point[idx].raw_x);
		ft_putchar(',');
		ft_putnbr(map.point[idx].raw_y);
		ft_putchar(',');
		ft_putnbr(map.point[idx].raw_z);
		ft_putchar('\t');	
		idx++;	
	}
}

int main(int ac, char **av)
{
	t_map	map;
	
	if (ac > 2)
		ft_putendl("usage: ./fdf [map_name]");
	else
	{
		// printf("getting map\n");
		ft_map_init(&map);
		WERR1((ft_get_map(av[1], &map) == -1), "issue getting map", -1);
		ft_print_map(map);
		// ft_get_map(av[1]);
	}
	// env.mlx = mlx_init();
	// env.win = mlx_new_window(env.mlx, 500, 500, "42");
	// // sleep(2);
	// // draw(env.mlx, env.win);
	// mlx_key_hook(env.win, key_hook, &env);
	// mlx_mouse_hook(env.win, mouse_hook, &env);
	// mlx_expose_hook(env.win, expose_hook, &env);
	
	// // sleep(5);
	// mlx_loop(env.mlx);
	return (0);
}

// int my_key_funct(int keycode, void *param)
// {
// 	(void) param;
// 	printf("key event %d\n", keycode);

// 	return (0);
// }

// int main()
// {
// 	void *mlx;
// 	void *win; //window connection
// 	int x;
// 	int y;

// 	mlx = mlx_init(); // initiates mlx
// 	win = mlx_new_window(mlx, 400, 400, "mlx 42"); // opens the window, uses connector mlx, 400 by 400 size?
// 	y = 50;
// 	while (y < 150)
// 	{
// 		x = 50;
// 		while (x < 150)
// 		{
// 			mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);	
// 			x++;
// 		}
// 		y++;
// 	}
// 	mlx_key_hook(win, my_key_funct, 0);
// 	mlx_loop(mlx); //allows you to see drawings in window
// 	return (0);
// }