/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 22:20:42 by fsarbout          #+#    #+#             */
/*   Updated: 2019/11/04 03:57:26 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t l;

	if (!(*s2))
		return ((char*)s1);
	if ((s1 == NULL) && (n == 0))
		return (NULL);
	while (*s1 && n > 0)
	{
		if (*s1 == *s2)
		{
			i = 0;
			l = n;
			while ((*s2) && *(s1 + i) == *(s2 + i) && l > 0)
			{
				i++;
				if (*(s2 + i) == '\0')
					return ((char*)s1);
				l--;
			}
		}
		s1++;
		n--;
	}
	return (0);
}
