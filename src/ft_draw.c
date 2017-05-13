/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 23:06:44 by qho               #+#    #+#             */
/*   Updated: 2017/05/12 23:17:47 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_x(t_pt one, t_pt two, t_map *map)
{
	int	x;

	x = one.x + 1;
	while (x < two.x)
	{
		mlx_pixel_put(map->mlx, map->window, x, one.y, 0x666666);
		x++;
	}
}

void	draw_lines(t_map *map)
{
	int	idx;
	int	x;
	int	y;

	idx = 0;
	x = map->point[0].x;
	y = map->point[0].y;
	while (map->point[idx].x != 0)
	{
		if ((idx + 1) % map->m_width)
			draw_x(map->point[idx], map->point[idx + 1], map);
		idx++;
	}
}

void	draw_points(t_map *map)
{
	int	idx;

	idx = 0;
	while (map->point[idx].x != 0)
	{
		if (map->point[idx].raw_z == 0)
			mlx_pixel_put(map->mlx, map->window, map->point[idx].x, map->point[idx].y, 0x00FF00);
		else
			mlx_pixel_put(map->mlx, map->window, map->point[idx].x, map->point[idx].y, 0xFF0000);
		idx++;
	}
	draw_lines(map);
}
