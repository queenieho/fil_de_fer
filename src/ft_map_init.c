/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 17:04:45 by qho               #+#    #+#             */
/*   Updated: 2017/05/18 17:27:41 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_array_len(char **args)
{
	int		len;
	char	**tmp;

	len = 0;
	tmp = args;
	while (*tmp)
	{
		tmp++;
		len++;
	}
	// printf("array len %d\n", len);
	return (len);
}

void	ft_map_init(t_map *map, char *filename)
{
	int		h_idx;
	int		w_idx;

	h_idx = -1;
	map->mlx = mlx_init();
	map->window = mlx_new_window(map->mlx, WIDTH, HEIGHT, filename);
	map->point = (t_pt **)malloc(sizeof(t_pt *) * map->m_height);
	map->z_max = 0;
	map->z_min = 0;
	while (++h_idx < map->m_height)
	{
		w_idx = -1;
		map->point[h_idx] = (t_pt *)malloc(sizeof(t_pt) * map->m_width);
		while (++w_idx < map->m_width)
			ft_memset((void *)&map->point[h_idx][w_idx], 0, sizeof(t_pt));
	// 	// map->point[idx].x = 0;
	// 	// map->point[idx].y = 0;
	// 	// map->point[idx].z = 0;
	}
}
