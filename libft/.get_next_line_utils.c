/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 05:25:12 by fsarbout          #+#    #+#             */
/*   Updated: 2020/11/05 18:30:53 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*sj;
	char	*ptr;

	if (!s1 || !s2)
		return (NULL);
	if (!(sj = (char*)malloc((ft_strlen(s2) + ft_strlen(s1) + 1))))
		return (NULL);
	ptr = sj;
	while (*s1)
	{
		*sj = *s1;
		sj++;
		s1++;
	}
	while (*s2)
	{
		*sj = *s2;
		sj++;
		s2++;
	}
	*sj = '\0';
	return (ptr);
}

char		*ft_strdup(const char *s1)
{
	int		i;
	char	*ptr;

	i = 0;
	while (*(s1 + i))
		i++;
	ptr = (char *)malloc((i + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (*(s1 + i))
	{
		*(ptr + i) = *(s1 + i);
		i++;
	}
	*(ptr + i) = '\0';
	return (ptr);
}

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

size_t		ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (*s)
	{
		i++;
		s++;
	}
	return (i);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start)
		len = 0;
	sub = (char*)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, s + start, len + 1);
	return (sub);
}
