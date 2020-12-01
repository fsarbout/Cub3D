/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 15:59:07 by fsarbout          #+#    #+#             */
/*   Updated: 2019/11/05 19:18:48 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_start(char const *str1, char const *str2, int i, int j)
{
	while ((str1[i] != '\0') && (str2[j] != '\0'))
	{
		if (str1[i] == str2[j])
		{
			i++;
			j = 0;
		}
		else
			j++;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int				indexi;
	int				indexf;
	int				i;
	unsigned int	len;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	indexf = ft_strlen(s1) - 1;
	indexi = ft_start(s1, set, 0, 0);
	while (indexf >= 0 && set[i] != '\0')
	{
		if (s1[indexf] == set[i])
		{
			indexf--;
			i = 0;
		}
		else
			i++;
	}
	if ((indexf - indexi + 1) <= 0)
		len = 0;
	else
		len = indexf - indexi + 1;
	return (ft_substr(s1, indexi, len));
}
