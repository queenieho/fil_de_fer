/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adjust_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 17:35:52 by qho               #+#    #+#             */
/*   Updated: 2017/05/19 12:34:29 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_init_limits(t_pt pt, t_limit *l)
{
	l->max_x = pt.x;
	l->min_x = pt.x;
	l->max_y = pt.y;
	l->min_y = pt.y;
}

static void	ft_find_limits(t_limit *l, t_map *map)
{
	int		r;
	int		c;
	t_pt	**pt;

	r = -1;
	pt = map->point;
	if (pt[0][0].x != 0)
		ft_init_limits(pt[0][0], l);
	while (++r < map->m_height)
	{
		c = -1;
		while (++c < map->m_width)
		{
			if (pt[r][c].x > l->max_x)
				l->max_x = pt[r][c].x;
			else if (pt[r][c].x < l->min_x)
				l->min_x = pt[r][c].x;
			if (pt[r][c].y > l->max_y)
				l->max_y = pt[r][c].y;
			else if (pt[r][c].y < l->min_y)
				l->min_y = pt[r][c].y;
		}
	}
}

void		ft_adjust_map(t_map *map)
{
	t_limit	l;
	float	width;
	float	height;
	int		r;
	int		c;

	ft_find_limits(&l, map);
	width = abs((int)round(l.max_x - l.min_x));
	height = abs((int)round(l.max_y - l.min_y));
	r = -1;
	while (++r < map->m_height)
	{
		c = -1;
		while (++c < map->m_width)
		{
			map->point[r][c].x =
			round((map->point[r][c].x - l.min_x) + ((WIDTH - width) / 2));
			map->point[r][c].y =
			round((map->point[r][c].y - l.min_y) + ((HEIGHT - height) / 2));
		}
	}
}
