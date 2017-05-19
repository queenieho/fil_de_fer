/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 19:41:41 by qho               #+#    #+#             */
/*   Updated: 2017/05/18 18:17:55 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_rotate_map_z(t_map *map)
{
	int		r;
	int		c;
	float	x;
	float	y;
	t_pt	**point;

	r = -1;
	point = map->point;
	while (++r < map->m_height)
	{
		c = -1;
		while (++c < map->m_width)
		{
			x = point[r][c].x;
			y = point[r][c].y;
			point[r][c].x = round((x * cos(0.785398)) - (y * sin(0.785398)));
			point[r][c].y = round((x * sin(0.785398)) + (y * cos(0.785398)));
		}
	}
}

void	ft_rotate_map_x(t_map *map)
{
	int		r;
	int		c;
	float	z;
	float	y;
	t_pt	**point;

	r = -1;
	point = map->point;
	while (++r < map->m_height)
	{
		c = -1;
		while (++c < map->m_width)
		{
			z = point[r][c].z;
			y = point[r][c].y;
			point[r][c].y = round((y * cos(0.296706)) - (z * sin(0.296706)));
			point[r][c].z = round((y * sin(0.296706)) + (z * cos(0.296706)));
		}
	}
}

void	ft_rotate_map_y(t_map *map)
{
	int		r;
	int		c;
	float	x;
	float	z;
	t_pt	**point;

	r = -1;
	point = map->point;
	while (++r < map->m_height)
	{
		c = -1;
		while (++c < map->m_width)
		{
			x = point[r][c].x;
			z = point[r][c].z;
			point[r][c].x = round((x * cos(0.0523599)) + (z * sin(0.0523599)));
			point[r][c].z = round(-(x * sin(0.0523599)) + (z * cos(0.0523599)));
		}
	}
}

void	ft_rotate_map(t_map *map)
{
	ft_rotate_map_z(map);
	ft_rotate_map_x(map);
	ft_rotate_map_y(map);
	ft_adjust_map(map);
}
