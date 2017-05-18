/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 21:53:00 by qho               #+#    #+#             */
/*   Updated: 2017/05/17 17:43:28 by qho              ###   ########.fr       */
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
			ft_putnbr(map.point[h_idx][w_idx].x);
			ft_putchar(',');
			ft_putnbr(map.point[h_idx][w_idx].y);
			ft_putchar(',');
			ft_putnbr(map.point[h_idx][w_idx].z);
			ft_putchar('\t');	
		}
		ft_putchar('\n');
	// 	// map->point[idx].x = 0;
	// 	// map->point[idx].y = 0;
	// 	// map->point[idx].z = 0;
	}
}
