/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 17:48:53 by fsarbout          #+#    #+#             */
/*   Updated: 2021/01/17 07:16:58 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	print_error(char *string)
{
	ft_putstr("Error\n");
	ft_putstr(string);
	if (g_dt.mmp)
		freee(g_dt.mmp);
	exit(EXIT_FAILURE);
}
