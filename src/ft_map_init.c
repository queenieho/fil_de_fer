/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 17:04:45 by qho               #+#    #+#             */
/*   Updated: 2017/05/16 18:54:34 by qho              ###   ########.fr       */
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
	static int	pt_idx = 0;
	static int	row = 1;
	char		**values;
	int			val_idx;

	val_idx = 0;
	values = ft_strsplit(line, ' ');
	if (row == 1)
		map->m_width = ft_array_len(values);
	else if (map->m_width != ft_array_len(values))
		return (-1);
	while (values[val_idx])
	{
		map->point[pt_idx].raw_x = val_idx + 1;
		map->point[pt_idx].raw_y = row;
		map->point[pt_idx].raw_z = atoi(values[val_idx]);
		pt_idx++;
		val_idx++;
	}
	map->m_height = row;
	row++;
	// ft_putendl("here?");
	free(values);
	return (0);
}

int		ft_load_points(t_map *map)
{
	int		idx;
	int		x;
	int		y;

	idx = 0;
	if (map->m_height == 0 && map->m_width == 0)
		return (-1);
	x = (WIDTH - 200)/(map->m_width + 1);
	y = (HEIGHT - 200)/(map->m_height + 1);
	// y = map.point[idx].raw_y;
	ft_putstr("Width increment: ");
	ft_putnbr(x);
	ft_putchar('\n');
	ft_putstr("Height increment: ");
	ft_putnbr(y);
	ft_putchar('\n');
	while (map->point[idx].raw_x != 0)
	{
		map->point[idx].x = (map->point[idx].raw_x * x) + 100;
		map->point[idx].y = (map->point[idx].raw_y * y) + 100;
		// if (map.point[idx].raw_y != y)
		// {
		// 	y = map.point[idx].raw_y;
		// 	ft_putchar('\n');
		// }
		// ft_putnbr(map.point[idx].raw_x);
		// ft_putchar(',');
		// ft_putnbr(map.point[idx].raw_y);
		// ft_putchar(',');
		// ft_putnbr(map.point[idx].raw_z);
		// ft_putchar('\t');	
		idx++;	
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
		// ft_putendl("theres a line");
		// ft_putendl(line);
		if ((ft_load_raw_points(line, map)) == -1)
			return (-1);
		free(line);
	}
	if (get_next_line(fd, &line) == -1)
		return (-1);
	if (ft_load_points(map) == -1)
		return (-1);
	return (0);
}

void	ft_map_init(t_map *map)
{
	int		idx;

	idx = -1;
	map->mlx = mlx_init();
	map->window = mlx_new_window(map->mlx, WIDTH, HEIGHT, "fdf");
	map->m_width = 0;
	map->m_height = 0;
	while (++idx < 90000)
	{
		ft_memset((void *)&map->point[idx], 0, sizeof(t_pt));
		// map->point[idx].x = 0;
		// map->point[idx].y = 0;
		// map->point[idx].z = 0;
	}
}
