/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 23:06:44 by qho               #+#    #+#             */
/*   Updated: 2017/05/19 12:09:22 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_row_lines(t_map *map)
{
	int	r;
	int	c;

	r = -1;
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
	draw_row_lines(map);
	draw_col_lines(map);
}
