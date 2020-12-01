/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_floor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 18:47:20 by fsarbout          #+#    #+#             */
/*   Updated: 2020/11/30 18:28:09 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collect_data.h"

void    treat_flr(char **element_data)
{
    char **rgb;
    int i;

    i = 2;
    if (g_data.f == 1)
        print_error(11);
    g_data.f = 1;
    if ((ft_strncmp(element_data[0], "F" ,2)))
        print_error(10);
    rgb = ft_split(element_data[1], ',');
    if (lenght(rgb) != 3)
        print_error(10);
    if ((!str_of_num(rgb[0])) || (!str_of_num(rgb[0])) || (!str_of_num(rgb[0])))
        print_error(10);
    g_data.flr_r = ft_atoi(rgb[0]);
    g_data.flr_g = ft_atoi(rgb[1]);
    g_data.flr_b = ft_atoi(rgb[2]);
    if ((g_data.flr_r < 0 || g_data.flr_r > 255) 
        || (g_data.flr_g < 0 || g_data.flr_g > 255) 
            || (g_data.flr_b < 0 || g_data.flr_b > 255) )
            print_error(10);
}