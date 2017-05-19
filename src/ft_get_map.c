/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 17:27:07 by qho               #+#    #+#             */
/*   Updated: 2017/05/19 12:37:17 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_find_z_limit(t_map *map, int z)
{
	if (z > map->z_max)
		map->z_max = z;
	if (z < map->z_min)
		map->z_min = z;
}

static int		ft_load_raw_points(char *line, t_map *map)
{
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
	ft_array_del(values);
	return (0);
}

static float	ft_get_z(int raw_z, float inc, int z_max)
{
	float	z;

	if (raw_z == 0)
		z = 0;
	else
		z = (raw_z * inc) / (inc / z_max);
	return (z);
}

static int		ft_load_points(t_map *m)
{
	int		r;
	int		c;
	float	x;
	float	y;
	float	inc;

	r = -1;
	x = (WIDTH - 300) / (m->m_width + 1);
	y = (HEIGHT - 200) / (m->m_height + 1);
	inc = x < y ? x : y;
	while (++r < m->m_height)
	{
		c = -1;
		while (++c < m->m_width)
		{
			m->point[r][c].x = (m->point[r][c].raw_x * inc) + 150;
			m->point[r][c].y = (m->point[r][c].raw_y * inc) + 100;
			m->point[r][c].z = ft_get_z(m->point[r][c].raw_z, inc, m->z_max);
		}
	}
	return (0);
}

int				ft_get_map(char *filename, t_map *map)
{
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
