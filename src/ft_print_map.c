/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 21:53:00 by qho               #+#    #+#             */
/*   Updated: 2017/05/17 23:55:42 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_print_raw_map(t_map map)
{
	int		h_idx;
	int		w_idx;
	// int		y;
	
	h_idx = -1;
	// y = map.point[idx].raw_y;
	ft_putstr("Width: ");
	ft_putnbr(map.m_width);
	ft_putchar('\n');
	ft_putstr("Height: ");
	ft_putnbr(map.m_height);
	ft_putchar('\n');
	while (++h_idx < map.m_height)
	{
		w_idx = -1;
		while (++w_idx < map.m_width)
		{
			ft_putnbr(map.point[h_idx][w_idx].raw_x);
			ft_putchar(',');
			ft_putnbr(map.point[h_idx][w_idx].raw_y);
			ft_putchar(',');
			ft_putnbr(map.point[h_idx][w_idx].raw_z);
			ft_putchar('\t');	
		}
		ft_putchar('\n');
	// 	// map->point[idx].x = 0;
	// 	// map->point[idx].y = 0;
	// 	// map->point[idx].z = 0;
	}
}

void	ft_print_map(t_map map)
{
	int		r;
	int		c;
	// int		y;
	
	r = -1;
	// y = map.point[idx].raw_y;
	ft_putstr("Width: ");
	ft_putnbr(map.m_width);
	ft_putchar('\n');
	ft_putstr("Height: ");
	ft_putnbr(map.m_height);
	ft_putchar('\n');
	while (++r < map.m_height)
	{
		c = -1;
		while (++c < map.m_width)
		{
			printf("| %.2f, %.2f, %.2f |\t", map.point[r][c].x, map.point[r][c].y, map.point[r][c].z);
			// ft_putnbr(map.point[r][c].x);
			// ft_putchar(',');
			// ft_putnbr(map.point[r][c].y);
			// ft_putchar(',');
			// ft_putnbr(map.point[r][c].z);
			// ft_putchar('\t');	
		}
		// ft_putchar('\n');
		printf("\n");
	// 	// map->point[idx].x = 0;
	// 	// map->point[idx].y = 0;
	// 	// map->point[idx].z = 0;
	}
}
