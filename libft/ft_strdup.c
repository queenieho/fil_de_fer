/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 11:25:40 by qho               #+#    #+#             */
/*   Updated: 2016/09/26 17:06:38 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	unsigned int	i;
	char			*dst;

	i = 0;
	dst = (char *)malloc(ft_strlen(s1) + 1);
	if (dst != NULL)
	{
		ft_strcpy(dst, s1);
		return (dst);
	}
	else
		return (0);
}
