/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 17:44:44 by fsarbout          #+#    #+#             */
/*   Updated: 2019/11/04 10:11:51 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *dst1;
	unsigned char *src1;
	unsigned char tmp[len];

	if (dst == src)
		return (dst);
	if (len >= (128 * 1024 * 1024))
		return (NULL);
	src1 = (unsigned char*)src;
	dst1 = (unsigned char*)dst;
	ft_memcpy(tmp, src1, len);
	ft_memcpy(dst1, tmp, len);
	return (dst);
}
