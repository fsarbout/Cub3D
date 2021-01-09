/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 17:48:53 by fsarbout          #+#    #+#             */
/*   Updated: 2020/12/20 01:41:09 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    print_error(char *string)
{
    ft_putstr("Error :\n");
    ft_putstr(string);
    ft_putstr("         the program detects the first error it faced\n");
    exit(EXIT_FAILURE);
}