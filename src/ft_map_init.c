/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 17:04:45 by qho               #+#    #+#             */
/*   Updated: 2017/05/19 12:33:46 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_validate_filename(char *name, char *type)
{
	char	*end;

	if ((end = ft_strstr(name, type)) == NULL)
		return (-1);
	else
	{
		if ((ft_strcmp(end, type)) != 0)
			return (-1);
	}
	return (0);
}

void	ft_array_del(char **values)
{
	int	idx;

	idx = -1;
	while (values[++idx])
	{
		free(values[idx]);
	}
	free(values);
}

int		ft_validate_map(char *filename, t_map *map)
{
	char	buf[BUFF_SIZE + 1];
	int		fd;
	char	*line;
	char	**values;

	ft_bzero((void *)buf, sizeof(char) * (BUFF_SIZE + 1));
	fd = open(filename, O_RDONLY);
	map->m_height = 0;
	map->m_width = 0;
	while (get_next_line(fd, &line) == 1)
	{
		map->m_height++;
		values = ft_strsplit(line, ' ');
		if (map->m_height == 1)
			map->m_width = ft_array_len(values);
		else if (map->m_width != ft_array_len(values))
			return (-1);
		ft_array_del(values);
		free(line);
	}
	if (get_next_line(fd, &line) == -1)
		return (-1);
	close(fd);
	return (0);
}

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
	}
}
