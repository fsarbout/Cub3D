/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 18:56:21 by fsarbout          #+#    #+#             */
/*   Updated: 2019/10/26 22:58:29 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		numb(int nb)
{
	if (nb == 0)
		return (0);
	return (1 + numb(nb / 10));
}

char	*affect(char *s, int num, int i)
{
	unsigned int l;

	l = 0;
	if (num == 0)
		*s = num + 48;
	else if (num < 0)
	{
		*s = '-';
		l = num * (-1);
	}
	else
		l = num;
	s[i + 1] = '\0';
	while (l != 0)
	{
		s[i] = l % 10 + 48;
		l = l / 10;
		i--;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*dst;

	if (n > 0)
		len = numb(n);
	else
		len = numb(n) + 1;
	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (dst == NULL)
		return (NULL);
	return (affect(dst, n, len - 1));
}
