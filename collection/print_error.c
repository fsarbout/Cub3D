/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 17:48:53 by fsarbout          #+#    #+#             */
/*   Updated: 2020/12/18 02:02:16 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collect_data.h"

void    print_error(int err_nmbr)
{
    if (err_nmbr == 2)
        ft_putstr("Error\n Map invalid!");
    else if (err_nmbr == 3)
        ft_putstr("Error\n The path invalid!");
    else if (err_nmbr == 4)
        ft_putstr("Error\n The player doesn't exist!");
    else if (err_nmbr == 7)
        ft_putstr("Error\n Map not surrounded by walls!");
    else if (err_nmbr == 9)
        ft_putstr("Error\n invalid file");  
    else if (err_nmbr == 10)
        ft_putstr("Error\n double/invalid element or element info or number");
    else if (err_nmbr == 11)
        ft_putstr("Error\n double element type");
    else if (err_nmbr == 12)
        ft_putstr("Error\n map not surrounded by ones");
    else if (err_nmbr == 14)
        ft_putstr("Error\n more than one player!");
    else if (err_nmbr == 15)
        ft_putstr("Error\n invalid character in the map!");
    // exit(0);
    exit(EXIT_FAILURE);
}