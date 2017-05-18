/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 10:49:39 by qho               #+#    #+#             */
/*   Updated: 2017/05/17 17:45:42 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_cleanup_and_exit(t_map *map)
{
	int		h_idx;
	int		w_idx;
	
	h_idx = -1;
	while (++h_idx < map->m_height)
	{
		w_idx = -1;
		free(map->point[h_idx]);
		// while (++w_idx < map.m_width)
			// free(map.point[h_idx][w_idx]);
	}
	free(map->point);
	// exit (0);
}

int		expose_hook(t_map *map)
{
	(void)map;
	draw_points(map);
	return (0);
}

int		key_hook(int keycode, t_map *map)
{
	(void) *map;
	printf("key: %d\n", keycode);
	if (keycode == 53)
		ft_cleanup_and_exit(map);
		exit (0);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_map *map)
{
	(void) *map;
	printf("mouse: %d (%d:%d)\n", button, x, y);
	return (0);
}

int		ft_validate_filename(char *name, char *type)
{
	char	*end;

	if ((end = ft_strstr(name, type)) == NULL)
		return (-1);
	else
	{
		if ((ft_strcmp(end, type)) != 0)
			return (-1);
	}
	// ft_putendl("valid file");
	return (0);
}

void	ft_array_del(char **values)
{
	int	idx;

	idx = -1;
	while (values[++idx])
	{
		free(values[idx]);
	}
	free(values);
}

int		ft_validate_map(char *filename, t_map *map)
{
	char	buf[BUFF_SIZE + 1];
	int		fd;
	char	*line;
	char	**values;

	ft_bzero((void *)buf, sizeof(char) * (BUFF_SIZE + 1));
	fd = open(filename, O_RDONLY);
	map->m_height = 0;
	map->m_width = 0;
	while (get_next_line(fd, &line) == 1)
	{
		map->m_height++;
		values = ft_strsplit(line, ' ');
		if (map->m_height == 1)
			map->m_width = ft_array_len(values);
		else if (map->m_width != ft_array_len(values))
			return (-1);
		ft_array_del(values);
		free(line);
	}
	if (get_next_line(fd, &line) == -1)
		return (-1);
	close(fd);
	return (0);
}

int		main(int ac, char **av)
{
	t_map	map;
	
	if (ac > 2)
		ft_putendl("usage: ./fdf [map_name].fdf");
	else
	{
		// printf("getting map\n");
		WERR1((ft_validate_filename(av[1], ".fdf") == -1), "Invalid filename", -1);
		WERR1((ft_validate_map(av[1], &map) == -1), "Invalid map", -1);
		WERR1((map.m_width == 0 && map.m_height == 0), "Empty map", -1);
		printf("width: %d, height: %d\n", map.m_width, map.m_height);
		ft_map_init(&map, av[1]);
		printf("map inited\n");
		WERR1((ft_get_map(av[1], &map) == -1), "Invalid map", -1);
		// ft_rotate_map(&map);
		ft_print_raw_map(map);
		ft_putchar('\n');
		ft_putchar('\n');
		ft_print_map(map);
	}
	// env.mlx = mlx_init();
	// env.win = mlx_new_window(env.mlx, 500, 500, "42");
	// // sleep(2);
	// // draw(env.mlx, env.win);

	mlx_key_hook(map.window, key_hook, &map);
	mlx_mouse_hook(map.window, mouse_hook, &map);
	mlx_expose_hook(map.window, expose_hook, &map);

	// // sleep(5);

	mlx_loop(map.mlx);
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