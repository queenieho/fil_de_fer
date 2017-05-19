/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 23:06:44 by qho               #+#    #+#             */
/*   Updated: 2017/05/18 17:50:35 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_row_lines(t_map *map)
{
	int	r;
	int	c;

	r = -1;
	// draw_line(map->point[0][0], map->point[0][1], map);
	while (++r < map->m_height)
	{
		c = -1;
		while ((++c + 1) < map->m_width)
			draw_line(map->point[r][c], map->point[r][c + 1], map);
	}
}

void	draw_col_lines(t_map *map)
{
	int	r;
	int	c;

	c = -1;
	while (++c < map->m_width)
	{
		r = -1;
		while ((++r + 1) < map->m_height)
			draw_line(map->point[r][c], map->point[r + 1][c], map);
	}
}

void	draw_points(t_map *map)
{
	// int		r;
	// int		c;
	// float	x;
	// float	y;

	// r = -1;
	draw_row_lines(map);
	draw_col_lines(map);
	// printf("\n\n first point: %.2f, %.2f\n", map->point[0][0].x, map->point[0][0].y);
	// printf("second point: %.2f, %.2f\n\n\n", map->point[0][1].x, map->point[0][1].y);
	
	// while (++r < map->m_height)
	// {
	// 	c = -1;
	// 	while (++c < map->m_width)
	// 	{
	// 		x = map->point[r][c].x;
	// 		y = map->point[r][c].y;
	// 		if (map->point[r][c].raw_z == 0)
	// 			mlx_pixel_put(map->mlx, map->window, x, y, 0x00FF00);
	// 		else
	// 			mlx_pixel_put(map->mlx, map->window, x, y, 0xFF0000);
	// 	}
	// }
}
