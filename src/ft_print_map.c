/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 21:53:00 by qho               #+#    #+#             */
/*   Updated: 2017/05/12 21:54:43 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_print_raw_map(t_map map)
{
	int		idx;
	int		y;

	idx = 0;
	y = map.point[idx].raw_y;
	ft_putstr("Width: ");
	ft_putnbr(map.m_width);
	ft_putchar('\n');
	ft_putstr("Height: ");
	ft_putnbr(map.m_height);
	ft_putchar('\n');
	while (map.point[idx].raw_x != 0)
	{
		if (map.point[idx].raw_y != y)
		{
			y = map.point[idx].raw_y;
			ft_putchar('\n');
		}
		ft_putnbr(map.point[idx].raw_x);
		ft_putchar(',');
		ft_putnbr(map.point[idx].raw_y);
		ft_putchar(',');
		ft_putnbr(map.point[idx].raw_z);
		ft_putchar('\t');	
		idx++;	
	}
}

void	ft_print_map(t_map map)
{
	int		idx;
	int		y;

	idx = 0;
	y = map.point[idx].y;
	ft_putstr("Width: ");
	ft_putnbr(map.m_width);
	ft_putchar('\n');
	ft_putstr("Height: ");
	ft_putnbr(map.m_height);
	ft_putchar('\n');
	while (map.point[idx].x != 0)
	{
		if (map.point[idx].y != y)
		{
			y = map.point[idx].y;
			ft_putchar('\n');
		}
		ft_putnbr(map.point[idx].x);
		ft_putchar(',');
		ft_putnbr(map.point[idx].y);
		ft_putstr("\t\t");	
		// printf("point? %d,%d\t", map.point[idx].x, map.point[idx].y);
		idx++;	
	}
}
