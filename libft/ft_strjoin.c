/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 00:59:26 by fsarbout          #+#    #+#             */
/*   Updated: 2019/11/05 20:48:41 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		s2len;
	int		s1len;
	char	*sj;

	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	sj = (char*)malloc(sizeof(char) * (s2len + s1len + 1));
	if (!sj)
		return (NULL);
	ft_strlcpy(sj, s1, s1len + 1);
	ft_strlcat(sj + s1len, s2, s2len + 1);
	return (sj);
}
