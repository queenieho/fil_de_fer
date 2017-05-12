/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 19:30:24 by qho               #+#    #+#             */
/*   Updated: 2017/05/12 11:05:34 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"

# define ROW_SIZE 300
# define COL_SIZE 300

# ifndef ERRORS
#  define ERR(a, b) if(a){return(b);}
#  define ERR1(a, b, c) if(a){b;return(c);}
#  define ERR2(a, b, c, d) if(a){b;c;return(d);}
# endif

# ifndef W_ERRORS
#  define WERR1(a, b, c) if(a){ft_putendl(b);return(c);}
#  define WERR2(a, b, c, d) if(a){b;ft_putendl(c);return(d);}
# endif

typedef struct	s_env
{
	void *mlx;
	void *win;
}				t_env;

typedef struct	s_pt
{
	int			x;
	int			y;
	// int			raw_x;
	// int			raw_y;
	int			z;
}				t_pt;

typedef struct	s_map
{
	void		*mlx;
	void		*window;
	int			m_width;
	int			m_height;
	t_pt		point[90000];
}				t_map;

#endif