/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 19:30:24 by qho               #+#    #+#             */
/*   Updated: 2017/05/17 17:18:40 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"

# define WIDTH 1024
# define HEIGHT 768

# ifndef ERRORS
#  define ERR(a, b) if(a){return(b);}
#  define ERR1(a, b, c) if(a){b;return(c);}
#  define ERR2(a, b, c, d) if(a){b;c;return(d);}
# endif

# ifndef W_ERRORS
#  define WERR1(a, b, c) if(a){ft_putendl(b);return(c);}
#  define WERR2(a, b, c, d) if(a){b;ft_putendl(c);return(d);}
# endif

typedef struct	s_val
{
	int			m;
	float		adjust;
	float		offset;
	float		threshold;
	float		delta;
}				t_val;

typedef struct	s_limit
{
	float		max_x;
	float		min_x;
	float		max_y;
	float		min_y;
}				t_limit;

typedef struct	s_env
{
	void *mlx;
	void *win;
}				t_env;

typedef struct	s_pt
{
	float		x;
	float		y;
	float		z;
	int			raw_x;
	int			raw_y;
	int			raw_z;
}				t_pt;

typedef struct	s_map
{
	void		*mlx;
	void		*window;
	int			m_width;
	int			m_height;
	t_pt		**point;
}				t_map;

/*
** FT_MAP_INIT_C
*/
int		ft_array_len(char **args);
int		ft_load_raw_points(char *line, t_map *map);
int		ft_load_points(t_map *map);
int		ft_get_map(char *filename, t_map *map);
void	ft_map_init(t_map *map, char *filename);

/*
** PRINT_MAP_C
*/
void	ft_print_raw_map(t_map map);
void	ft_print_map(t_map map);

/*
** FT_DRAW_C
*/
void	draw_x(t_pt one, t_pt two, t_map *map);
void	draw_lines(t_map *map);
void	draw_points(t_map *map);

/*
** ROTATE_MAP
*/
void	ft_rotate_map(t_map *map);
void	ft_rotate_map_z(t_map *map);

/*
** MAIN_C
*/
void	ft_array_del(char **values);



#endif