/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 19:41:41 by qho               #+#    #+#             */
/*   Updated: 2017/05/17 01:32:19 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init_limits(t_pt pt, t_limit *l)
{
	l->max_x = pt.x;
	l->min_x = pt.x;
	l->max_y = pt.y;
	l->min_y = pt.y;
}

void	ft_find_limits(t_limit *l, t_map *map)
{
	int		idx;
	t_pt	*pt;

	idx = 0;
	pt = map->point;
	// (void)map;
	// ft_bzero(l, sizeof(t_limit));
	if (pt[idx].x != 0)
		ft_init_limits(pt[idx], l);
	// printf("max X: %f\n", l->max_x);
	// printf("max Y: %f\n", l->max_y);
	// printf("min X: %f\n", l->min_x);
	// printf("min Y: %f\n\n\n", l->min_y);
	while (pt[idx].x != 0)
	{
		if (pt[idx].x > l->max_x)
			l->max_x = pt[idx].x;
		else if (pt[idx].x < l->min_x)
			l->min_x = pt[idx].x;
		if (pt[idx].y > l->max_y)
			l->max_y = pt[idx].y;
		else if (pt[idx].y < l->min_y)
			l->min_y = pt[idx].y;
		idx++;
	}
	printf("max X: %f\n", l->max_x);
	printf("max Y: %f\n", l->max_y);
	printf("min X: %f\n", l->min_x);
	printf("min Y: %f\n", l->min_y);
}

void	ft_adjust_map(t_map *map)
{
	t_pt	*pt;
	t_limit	l;
	double	width;
	double	height;
	int		idx;

	ft_find_limits(&l, map);
	// width = (l.max_x - l.min_x) < 0? -(l.max_x - l.min_x) : (l.max_x - l.min_x);
	// height = (l.max_y - l.min_y) < 0? -(l.max_y - l.min_y) : (l.max_y - l.min_y);
	width = abs((int)round(l.max_x - l.min_x));
	height = abs((int)round(l.max_y - l.min_y));
	pt = map->point;
	idx = 0;
	while (pt[idx].x != 0)
	{
		pt[idx].x = (pt[idx].x - l.min_x) + ((WIDTH - width) / 2);
		pt[idx].y = (pt[idx].y - l.min_y) + ((HEIGHT - height) / 2);
		idx++;
	}
	// printf("width %f\n", width);
	// printf("height %f\n", height);
}

void	ft_rotate_map_z(t_map *map)
{
	int		idx;
	double	x;
	double	y;
	t_pt	*point;

	idx = 0;
	point = map->point;
	while (point[idx].x != 0)
	{
		x = point[idx].x;
		y = point[idx].y;
		// point[idx].x = ((x * cos(0.785398)) - (y * sin(0.785398)));
		// point[idx].y = ((x * sin(0.785398)) + (y * cos(0.785398)));
		point[idx].x = ((x * cos(0.698132)) - (y * sin(0.698132)));
		point[idx].y = ((x * sin(0.698132)) + (y * cos(0.698132)));
		idx++;
	}
}

void	ft_rotate_map(t_map *map)
{
	ft_rotate_map_z(map);
	ft_adjust_map(map);
}
