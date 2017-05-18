/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 17:04:45 by qho               #+#    #+#             */
/*   Updated: 2017/05/17 17:50:28 by qho              ###   ########.fr       */
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

int		ft_load_raw_points(char *line, t_map *map)
{
	// printf("loading points\n");
	static int	r_idx = 0;
	int			c_idx;
	char		**values;
	int			val_idx;

	val_idx = 0;
	c_idx = 0;
	values = ft_strsplit(line, ' ');
	while (val_idx < map->m_width)
	{
		printf("%d: %s\n", val_idx, values[val_idx]);
		map->point[r_idx][c_idx].raw_x = val_idx + 1;
		map->point[r_idx][c_idx].raw_y = r_idx + 1;
		map->point[r_idx][c_idx].raw_z = ft_atoi(values[val_idx]);
		c_idx++;
		val_idx++;
	}
	r_idx++;
	// ft_putendl("here?");
	ft_array_del(values);
	return (0);
}

int		ft_load_points(t_map *map)
{
	int		r;
	int		c;
	float	x;
	float	y;
	float	inc;

	r = -1;
	x = (WIDTH - 200)/(map->m_width + 1);
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
			map->point[r][c].x = (map->point[r][c].raw_x * inc) + 100;
			map->point[r][c].y = (map->point[r][c].raw_y * inc) + 100;
			if (map->point[r][c].raw_z != 0)
				map->point[r][c].z = (map->point[r][c].raw_z * inc) / map->point[r][c].raw_z;
			else
				map->point[r][c].z = 0;
		}
	}
	return (0);
}

int		ft_get_map(char *filename, t_map *map)
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

void	ft_map_init(t_map *map, char *filename)
{
	int		h_idx;
	int		w_idx;

	h_idx = -1;
	map->mlx = mlx_init();
	map->window = mlx_new_window(map->mlx, WIDTH, HEIGHT, filename);
	map->point = (t_pt **)malloc(sizeof(t_pt *) * map->m_height);
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
