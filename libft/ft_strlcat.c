/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 03:34:44 by fsarbout          #+#    #+#             */
/*   Updated: 2019/11/05 21:00:21 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dlen;
	size_t	slen;
	size_t	j;
	size_t	f;

	j = 0;
	slen = ft_strlen(src);
	if ((dst == NULL) && (size == 0))
		return (slen);
	dlen = ft_strlen(dst);
	if (size <= dlen)
		return (slen + size);
	f = size - dlen - 1;
	while ((f > 0) && *(src + j))
	{
		*(dst + dlen + j) = *(src + j);
		j++;
		f--;
	}
	*(dst + dlen + j) = '\0';
	return (slen + dlen);
}
