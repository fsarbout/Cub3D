/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 17:06:33 by fsarbout          #+#    #+#             */
/*   Updated: 2019/11/05 15:31:53 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_words(const char *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (!s)
		return (0);
	if (s[0] != c)
		count++;
	while (s[i] != '\0')
	{
		if ((s[i] == c) && (s[i + 1] != c && s[i + 1] != '\0'))
			count++;
		i++;
	}
	return (count);
}

static size_t	wlen(const char *p, char c, size_t k)
{
	size_t		lenght;

	lenght = 0;
	while (p[k] != c && p[k] != '\0')
	{
		lenght++;
		k++;
	}
	return (lenght);
}

static char		**free_tab(char **dst, int i)
{
	while (i > 0)
	{
		i--;
		free(dst[i]);
	}
	free(dst);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	int			i;
	int			j;
	char		**dst;
	int			l;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	l = count_words(s, c);
	if (!(dst = (char **)malloc(sizeof(char *) * (l + 1))))
		return (NULL);
	while (j < l && s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (!(dst[j] = ft_substr(s, i, wlen(s, c, i))))
			return (free_tab(dst, j));
		while (s[i] != c && s[i])
			i++;
		j++;
	}
	dst[j] = NULL;
	return (dst);
}
