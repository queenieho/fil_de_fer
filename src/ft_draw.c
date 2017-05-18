/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 23:06:44 by qho               #+#    #+#             */
/*   Updated: 2017/05/17 17:49:43 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// // void	draw_x(t_pt one, t_pt two, t_map *map)
// // {
// // 	int	x;

// // 	x = one.x + 1;
// // 	while (x < two.x)
// // 	{
// // 		mlx_pixel_put(map->mlx, map->window, x, one.y, 0x666666);
// // 		x++;
// // 	}
// // }

// void	ft_draw_vertical(t_pt one, t_pt two, t_map *map)
// {
// 	t_pt	tmp;
// 	double	y;

// 	if (two.y < one.y)
// 	{
// 		tmp = one;
// 		one = two;
// 		two = tmp;
// 	}
// 	y = round(one.y);
// 	while (++y < two.y)
// 	{
// 		mlx_pixel_put(map->mlx, map->window, one.x, y, 0x666666);
// 	}
// }

// void	ft_draw_x_slope(t_val v, t_pt one, t_pt two, t_map *map)
// {
// 	t_pt	main;
// 	t_pt	tmp;

// 	v.delta = abs(v.m);
// 	ft_bzero(&main, sizeof(t_pt));
// 	if (two.x < one.x)
// 	{
// 		tmp = one;
// 		one = two;
// 		two = tmp;
// 	}
// 	main = one;
// 	while (main.x < two.x)
// 	{
// 		mlx_pixel_put(map->mlx, map->window, main.x, main.y, 0x666666);
// 		v.offset += v.delta;
// 		if (v.offset >= v.threshold)
// 		{
// 			main.y += v.adjust;
// 			v.threshold++;
// 		}
// 		main.x++;
// 	}
// }

// void	ft_draw_y_slope(t_val v, t_pt one, t_pt two, t_map *map)
// {
// 	t_pt	main;
// 	t_pt	tmp;

// 	ft_bzero(&main, sizeof(t_pt));
// 	if (two.x < one.x)
// 	{
// 		tmp = one;
// 		one = two;
// 		two = tmp;
// 	}
// 	main = one;
// 	while (main.y <= two.y)
// 	{
// 		mlx_pixel_put(map->mlx, map->window, main.x, main.y, 0x666666);
// 		v.offset += v.delta;
// 		if (v.offset >= v.threshold)
// 		{
// 			main.x += v.adjust;
// 			v.threshold++;
// 		}
// 		main.y++;
// 	}
// }

// void	draw_line(t_pt one, t_pt two, t_map *map)
// {
// 	double	rise;
// 	double	run;
// 	t_val	v;

// 	rise = (two.y - one.y);
// 	run = (two.x - one.x);
// 	v.m = round(rise / run);
// 	v.adjust = v.m >= 0? 1 : -1;
// 	v.offset = 0;
// 	v.threshold = 0.5;
// 	if (run == 0)
// 		ft_draw_vertical(one, two, map);
// 	else if (v.m <= 1 && v.m >= -1)
// 	{
// 		// ft_putendl("X slope");
// 		ft_draw_x_slope(v, one, two, map);
// 	}
// 	else
// 	{
// 		// ft_putendl("Y slope");
// 		v.delta = abs((int)round(run / rise));
// 		ft_draw_y_slope(v, one, two, map);
// 	}
// }

// void	draw_lines(t_map *map)
// {
// 	int	x_idx;
// 	// int	y_idx;
// 	// int	x;
// 	// int	y;

// 	x_idx = 0;
// 	// x = map->point[0].x;
// 	// y = map->point[0].y;
// 	while (map->point[x_idx].x != 0)
// 	{
// 		if ((x_idx + 1) % map->m_width)
// 			draw_line(map->point[x_idx], map->point[x_idx + 1], map);
// 		x_idx++;
// 	}
// 	// x_idx = 0;
// 	// while (map->point[x_idx].x != 0)
// 	// {
// 	// 	draw_line(map->point[x_idx], map->point[x_idx + 19], map);
// 	// 	x_idx++;
// 	// }
// }

void	draw_points(t_map *map)
{
	int		r;
	int		c;
	float	x;
	float	y;

	r = -1;
	// draw_lines(map);
	while (++r < map->m_height)
	{
		c = -1;
		while (++c < map->m_width)
		{
			x = map->point[r][c].x;
			y = map->point[r][c].y;
			if (map->point[r][c].raw_z == 0)
				mlx_pixel_put(map->mlx, map->window, x, y, 0x00FF00);
			else
				mlx_pixel_put(map->mlx, map->window, x, y, 0xFF0000);
		}
	}

	// while (map->point[idx].x != 0)
	// {
	// 	if (map->point[idx].raw_z == 0)
	// 		mlx_pixel_put(map->mlx, map->window, map->point[idx].x, map->point[idx].y, 0x00FF00);
	// 	else
	// 		mlx_pixel_put(map->mlx, map->window, map->point[idx].x, map->point[idx].y, 0xFF0000);
	// 	idx++;
	// }
}
