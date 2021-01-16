/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 17:48:53 by fsarbout          #+#    #+#             */
/*   Updated: 2021/01/16 12:52:37 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    print_error(char *string)
{
    ft_putstr("Error :\n");
    ft_putstr(string);
    ft_putstr("         the program detects the first error it faced\n");
    freee(g_dt.mmp);
    exit(EXIT_FAILURE);
}