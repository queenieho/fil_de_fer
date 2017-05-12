/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 11:33:20 by qho               #+#    #+#             */
/*   Updated: 2017/05/10 14:42:05 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_get_line(char **line, char **hold, char *buf)
{
	char		*tmp;
	char		*tmp_hold;

	if (buf)
	{
		if (*hold != NULL)
		{
			tmp_hold = ft_strjoin(*hold, buf);
			free(*hold);
			*hold = tmp_hold;
		}
		else
			*hold = ft_strdup(buf);
	}
	if (*hold && (tmp = ft_strchr(*hold, '\n')))
	{
		*tmp = '\0';
		tmp++;
		tmp_hold = ft_strdup(tmp);
		*line = ft_strdup(*hold);
		free(*hold);
		*hold = tmp_hold;
		return (1);
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static char	*hold = NULL;
	char		buf[BUFF_SIZE + 1];
	int			ret;

	if (fd < 0 || (size_t)&*line == 0)
		return (-1);
	if (hold && (ft_get_line(line, &hold, NULL)))
		return (1);
	ft_bzero((void *)buf, sizeof(char) * (BUFF_SIZE + 1));
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		if (ft_get_line(line, &hold, buf))
			return (1);
	}
	if (hold && *hold != '\0' && (*line = ft_strdup(hold)))
	{
		free(hold);
		return (1);
	}
	free(hold);
	hold = NULL;
	return (0);
}
