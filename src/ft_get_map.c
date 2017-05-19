/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 17:27:07 by qho               #+#    #+#             */
/*   Updated: 2017/05/18 17:30:58 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_find_z_limit(t_map *map, int	z)
{
	if (z > map->z_max)
		map->z_max = z;
	if (z < map->z_min)
		map->z_min = z;
}

static int	ft_load_raw_points(char *line, t_map *map)
{
	// printf("loading points\n");
	static int	r_idx = 0;
	int			c_idx;
	char		**values;
	int			val_idx;

	val_idx = 0;
	c_idx = 0;
	values = ft_strsplit(line, ' ');
	while (val_idx < map->m_width && values[val_idx] != '\0')
	{
		map->point[r_idx][c_idx].raw_x = val_idx + 1;
		map->point[r_idx][c_idx].raw_y = r_idx + 1;
		map->point[r_idx][c_idx].raw_z = ft_atoi(values[val_idx]);
		ft_find_z_limit(map, map->point[r_idx][c_idx].raw_z);
		c_idx++;
		val_idx++;
	}
	r_idx++;
	// ft_putendl("here?");
	ft_array_del(values);
	return (0);
}

static int	ft_load_points(t_map *map)
{
	int		r;
	int		c;
	float	x;
	float	y;
	float	inc;

	r = -1;
	x = (WIDTH - 300)/(map->m_width + 1);
	y = (HEIGHT - 200)/(map->m_height + 1);
	inc = x < y? x : y;
	ft_putstr("Width increment: ");
	ft_putnbr(x);
	ft_putchar('\n');
	ft_putstr("Height increment: ");
	ft_putnbr(y);
	ft_putchar('\n');
	while (++r < map->m_height)
	{
		c = -1;
		while (++c < map->m_width)
		{
			map->point[r][c].x = (map->point[r][c].raw_x * inc) + 150;
			map->point[r][c].y = (map->point[r][c].raw_y * inc) + 100;
			if (map->point[r][c].raw_z != 0)
				map->point[r][c].z = ((map->point[r][c].raw_z * inc) / map->z_max);
			else
				map->point[r][c].z = 0;
		}
	}
	return (0);
}

int			ft_get_map(char *filename, t_map *map)
{
	// printf("getting map?\n");
	char	buf[BUFF_SIZE + 1];
	int		fd;
	char	*line;

	ft_bzero((void *)buf, sizeof(char) * (BUFF_SIZE + 1));
	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		if ((ft_load_raw_points(line, map)) == -1)
			return (-1);
		free(line);
	}
	if (get_next_line(fd, &line) == -1)
		return (-1);
	if (ft_load_points(map) == -1)
		return (-1);
	close(fd);
	return (0);
}