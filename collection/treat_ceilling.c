/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_ceilling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:55:42 by fsarbout          #+#    #+#             */
/*   Updated: 2020/11/29 10:14:14 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collect_data.h"

void    treat_cllng(char **element_data)
{
    char **rgb;
    
    if (g_data.c == 1)
        print_error(11);
    g_data.c = 1;
    if ((ft_strncmp(element_data[0], "C" ,2)))
        print_error(10);
    if (lenght(element_data) != 2)
        print_error(10);
    rgb = ft_split(element_data[1], ',');
    if (lenght(rgb) != 3)
        print_error(10);
    if ((!str_of_num(rgb[0])) || (!str_of_num(rgb[1])) || (!str_of_num(rgb[2])))
        print_error(10);
    g_data.cllng_r = ft_atoi(rgb[0]);
    g_data.cllng_g = ft_atoi(rgb[1]);
    g_data.cllng_b = ft_atoi(rgb[2]);
    if ((g_data.cllng_r < 0 || g_data.cllng_r > 255) 
        || (g_data.cllng_g < 0 || g_data.cllng_g > 255) 
            || (g_data.cllng_b < 0 || g_data.cllng_b > 255) )
            print_error(10);
}