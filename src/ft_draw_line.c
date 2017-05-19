/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 17:50:16 by qho               #+#    #+#             */
/*   Updated: 2017/05/19 12:32:15 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_vertical(t_pt one, t_pt two, t_map *map)
{
	t_pt	tmp;
	double	y;

	if (two.y < one.y)
	{
		tmp = one;
		one = two;
		two = tmp;
	}
	y = round(one.y);
	while (++y < two.y)
	{
		mlx_pixel_put(map->mlx, map->window, one.x, y, 0x333333);
	}
}

int		ft_get_color(t_pt one, t_map *map)
{
	int		r;
	int		g;
	int		b;

	r = 255;
	g = 255;
	b = 255;
	if (one.raw_z > 0)
	{
		r = r - ((one.raw_z * r) / map->z_max);
		g = g - ((one.raw_z * g) / map->z_max);
	}
	else if (one.raw_z < 0)
	{
		g = g - ((one.raw_z * g) / map->z_min);
		b = b - ((one.raw_z * b) / map->z_min);
	}
	return ((r * 0x10000) + (g * 0x100) + b);
}

void	ft_draw_x_slope(t_val v, t_pt one, t_pt two, t_map *map)
{
	t_pt	main;
	int		color;

	v.delta = fabsf(v.m);
	if (two.x < one.x)
	{
		main = one;
		one = two;
		two = main;
	}
	main = one;
	main.color = ft_get_color(main, map);
	two.color = ft_get_color(two, map);
	color = main.raw_z < two.raw_z ? main.color : two.color;
	while (main.x < two.x)
	{
		mlx_pixel_put(map->mlx, map->window, main.x, main.y, color);
		v.offset += v.delta;
		if (v.offset >= v.threshold)
		{
			main.y += v.adjust;
			v.threshold++;
		}
		main.x++;
	}
}

void	ft_draw_y_slope(t_val v, t_pt one, t_pt two, t_map *map)
{
	t_pt	main;
	int		color;

	if (two.y < one.y)
	{
		main = one;
		one = two;
		two = main;
	}
	main = one;
	main.color = ft_get_color(main, map);
	two.color = ft_get_color(two, map);
	color = main.raw_z < two.raw_z ? main.color : two.color;
	while (main.y <= two.y)
	{
		mlx_pixel_put(map->mlx, map->window, main.x, main.y, color);
		v.offset += v.delta;
		if (v.offset >= v.threshold)
		{
			main.x += v.adjust;
			v.threshold++;
		}
		main.y++;
	}
}

void	draw_line(t_pt one, t_pt two, t_map *map)
{
	float	rise;
	float	run;
	t_val	v;

	rise = (two.y - one.y);
	run = (two.x - one.x);
	v.m = (rise / run);
	v.adjust = v.m >= 0 ? 1 : -1;
	v.offset = 0;
	v.threshold = 0.5;
	if (run == 0)
		ft_draw_vertical(one, two, map);
	else if (v.m <= 1 && v.m >= -1)
	{
		ft_draw_x_slope(v, one, two, map);
	}
	else
	{
		v.delta = fabsf(run / rise);
		ft_draw_y_slope(v, one, two, map);
	}
}
