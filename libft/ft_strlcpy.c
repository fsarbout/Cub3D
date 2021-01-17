/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 17:16:59 by fsarbout          #+#    #+#             */
/*   Updated: 2021/01/17 07:58:44 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t		ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (size && dst != src)
	{
		i = 0;
		while (src[i] && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

size_t		ft_strlcpy1(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (size && dst != src)
	{
		i = 0;
		while (src[i] && i < (size))
		{
			dst[i] = src[i];
			i++;
		}
		while (i < (size))
		{
			dst[i] = ' ';
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
