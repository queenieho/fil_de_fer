/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 17:50:16 by qho               #+#    #+#             */
/*   Updated: 2017/05/18 22:03:14 by qho              ###   ########.fr       */
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
	// printf("%d\n", one.raw_z);
	if (one.raw_z > 0)
	{
		// b = ((one.raw_z * b) / map->z_max);
		r = r - ((one.raw_z * r) / map->z_max);
		g = g - ((one.raw_z * g) / map->z_max);
	}
	else if (one.raw_z < 0)
	{
		// printf("red?\n");
		// r = ((one.raw_z * r) / map->z_min);
		g = g - ((one.raw_z * g) / map->z_min);
		b = b - ((one.raw_z * b) / map->z_min);
	}
	return ((r * 0x10000) + (g * 0x100) + b);
}

int		ft_get_color_increase(t_pt one, t_pt two, int steps)
{
	// int		inc;
	int		r = 0;
	int		g = 0;
	int		b = 0;

	if (one.color == 0xFFFFFF || two.color == 0xFFFFFF)
	{
		if (one.color == 0xFFFFFF && two.color > 0xFFFF)
		{
			r = 0;
			g = (-((0xFF0000) + 0xFF - two.color) / 0xFF00);
			b = -((0xFF0000) + (0xFF00) - two.color);
			// it's white to red, output is negative
		}
		// else if (one.color == 0xFFFFFF && two.color <= 0xFF)
		// 	// its white to blue
		if (two.color == 0xFFFFFF && one.color > 0xFFFF)
		{
			r = 0;
			g = (((0xFF0000) + 0xFF - two.color) / 0xFF00);
			b = ((0xFF0000) + (0xFF00) - two.color);
			// it's white to red, output is negative
		}
		// else if (two.color == 0xFFFFFF && one.color <= 0xFF)
		// 	// its blue to white
	}
	// else
	// {

	// 	// color to color
	// }
	return (((r * 0x10000) + (g * 0x100) + b) / steps);
}

void	ft_draw_x_slope(t_val v, t_pt one, t_pt two, t_map *map)
{
	t_pt	main;
	t_pt	tmp;
	int		c_inc;

	v.delta = fabsf(v.m);
	ft_bzero(&main, sizeof(t_pt));
	if (two.x < one.x)
	{
		// printf("swap points?\n");
		tmp = one;
		one = two;
		two = tmp;
	}
	main = one;
	main.color = ft_get_color(main, map);
	two.color = ft_get_color(two, map);
	c_inc = ft_get_color_increase(main, two, two.x - main.x);
	// c_inc = 0;
	// if (color != 0xFFFFFF && color != 0x0000FF)
	// 	printf("red!?\n");
	// printf("%d\n", main.raw_z);
	// if (main.raw_z == 0 && two.raw_z == 0)
	// 	color = 0xFFFFFF;
	// else
	// 	color = 0xFF0000;
	while (main.x < two.x)
	{
		mlx_pixel_put(map->mlx, map->window, main.x, main.y, main.color);
		v.offset += v.delta;
		if (v.offset >= v.threshold)
		{
			main.y += v.adjust;
			v.threshold++;
		}
		main.color += c_inc;
		main.x++;
	}
}

void	ft_draw_y_slope(t_val v, t_pt one, t_pt two, t_map *map)
{
	t_pt	main;
	t_pt	tmp;
	int		color;

	// printf("adjust: %f\n", v.adjust);
	// printf("offset: %f\n", v.offset);
	// printf("threshold: %f\n", v.threshold);
	// printf("delta: %f\n\n", v.delta);
	ft_bzero(&main, sizeof(t_pt));
	if (two.y < one.y)
	{
		// ft_putendl("swapping?");
		tmp = one;
		one = two;
		two = tmp;
	}
	main = one;
	// printf("%d\n", main.raw_z);
	// color = main.raw_z = 0? 0xFFFFFF : 0xFF0000;
	color = ft_get_color(main, map);
	// if (main.raw_z == 0 || two.raw_z == 0)
	// 	color = 0xFFFFFF;
	// else
	// 	color = 0xFF0000;
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

	// printf("about to draw\n");
	// printf("first point: %.2f, %.2f\n", one.x, one.y);
	// printf("second point: %.2f, %.2f\n\n\n", two.x, two.y);
	rise = (two.y - one.y);
	run = (two.x - one.x);
	v.m = (rise / run);
	v.adjust = v.m >= 0? 1 : -1;
	v.offset = 0;
	v.threshold = 0.5;
	if (run == 0)
		ft_draw_vertical(one, two, map);
	else if (v.m <= 1 && v.m >= -1)
	{
		// ft_putendl("X slope");
		ft_draw_x_slope(v, one, two, map);
	}
	else
	{
		// ft_putendl("Y slope");
		v.delta = fabsf(run / rise);
		ft_draw_y_slope(v, one, two, map);
	}
}
