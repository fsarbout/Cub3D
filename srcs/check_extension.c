/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 09:34:43 by fsarbout          #+#    #+#             */
/*   Updated: 2021/01/17 11:08:28 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_extension(char *s)
{
	if (!reversecheck(s, ".cub"))
		print_error("	File extention should be .cub!\n");
}

int		reversecheck(char *s, char *str)
{
	int i;
	int j;

	i = ft_strlen(s);
	j = ft_strlen(str);
	while (j != -1)
	{
		if (s[i] != str[j] || i < j)
			return (0);
		i--;
		j--;
	}
	return (1);
}
