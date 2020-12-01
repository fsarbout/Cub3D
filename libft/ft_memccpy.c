/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 19:48:42 by fsarbout          #+#    #+#             */
/*   Updated: 2019/11/05 06:59:59 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr2 = (unsigned char *)src;
	i = 0;
	ptr1 = (unsigned char *)dst;
	while (i < n)
	{
		if (*(ptr2 + i) == (unsigned char)c)
		{
			*(ptr1 + i) = *(ptr2 + i);
			return (ptr1 + i + 1);
		}
		*(ptr1 + i) = *(ptr2 + i);
		i++;
	}
	return (NULL);
}
