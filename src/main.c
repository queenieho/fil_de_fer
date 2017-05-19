/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 10:49:39 by qho               #+#    #+#             */
/*   Updated: 2017/05/19 12:43:56 by qho              ###   ########.fr       */
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
	}
	free(map->point);
	exit(0);
}

int		expose_hook(t_map *map)
{
	(void)map;
	draw_points(map);
	return (0);
}

int		key_hook(int keycode, t_map *map)
{
	(void)map;
	if (keycode == 53)
		ft_cleanup_and_exit(map);
	return (0);
}

/*
** int x and int y indicate which coordinates are being clicked
*/

int		mouse_hook(int button, int x, int y, t_map *map)
{
	(void)*map;
	(void)button;
	(void)x;
	(void)y;
	return (0);
}

int		main(int ac, char **av)
{
	t_map	map;

	if (ac > 2)
	{
		ft_putendl("usage: ./fdf [map_name].fdf");
		return (0);
	}
	WERR1((ft_validate_filename(av[1], ".fdf") == -1), "Invalid filename", -1);
	WERR1((ft_validate_map(av[1], &map) == -1), "Invalid map", -1);
	WERR1((map.m_width == 0 && map.m_height == 0), "Empty map", -1);
	ft_map_init(&map, av[1]);
	WERR1((ft_get_map(av[1], &map) == -1), "Invalid map", -1);
	ft_rotate_map(&map);
	mlx_key_hook(map.window, key_hook, &map);
	mlx_mouse_hook(map.window, mouse_hook, &map);
	mlx_expose_hook(map.window, expose_hook, &map);
	mlx_loop(map.mlx);
	return (0);
}
