/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 00:12:10 by fsarbout          #+#    #+#             */
/*   Updated: 2020/12/20 01:27:19 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    treat_rsltn(char **element_data)
{
    g_dt.r = 1;
    if (!str_of_num(element_data[1]))
        print_error("   wrong resolution width value!\n");
    g_dt.rsltn_w = ft_atoi(element_data[1]);
    g_dt.rsltn_w > MAX_WIDTH ? g_dt.rsltn_w =  MAX_WIDTH : 0;
    if (!str_of_num(element_data[2]))
       print_error("   wrong resolution height value!\n");
   g_dt.rsltn_h = ft_atoi(element_data[2]);
   g_dt.rsltn_h > MAX_HEIGHT ? g_dt.rsltn_h =  MAX_HEIGHT : 0;
}

void    treat_flr(char **element_data)
{
    char **rgb;

    g_dt.f = 1;
    rgb = ft_split(element_data[1], ',');
    if (lenght(rgb) != 3)
        print_error("  wrong data in floor rgb values!\n");
    if (!str_of_num(rgb[0]) || !str_of_num(rgb[0]) || !str_of_num(rgb[0]))
        print_error("  wrong data in floor rgb values!\n");
    g_dt.flr_r = ft_atoi(rgb[0]);
    g_dt.flr_g = ft_atoi(rgb[1]);
    g_dt.flr_b = ft_atoi(rgb[2]);
    if ((g_dt.flr_r < 0 || g_dt.flr_r > 255) 
        || (g_dt.flr_g < 0 || g_dt.flr_g > 255) 
            || (g_dt.flr_b < 0 || g_dt.flr_b > 255))
             print_error("  wrong data in floor rgb values!\n");
}

void    treat_cllng(char **element_data)
{
    char **rgb;
  
    g_dt.c = 1;
    rgb = ft_split(element_data[1], ',');
    if (lenght(rgb) != 3)
       print_error("  wrong data in ceilling rgb values!\n");
    if (!str_of_num(rgb[0]) || !str_of_num(rgb[1]) || !str_of_num(rgb[2]))
       print_error("  wrong data in ceilling rgb values!\n");
    g_dt.cllng_r = ft_atoi(rgb[0]);
    g_dt.cllng_g = ft_atoi(rgb[1]);
    g_dt.cllng_b = ft_atoi(rgb[2]);
    if ((g_dt.cllng_r < 0 || g_dt.cllng_r > 255) 
        || (g_dt.cllng_g < 0 || g_dt.cllng_g > 255) 
            || (g_dt.cllng_b < 0 || g_dt.cllng_b > 255) )
       print_error("  wrong data in ceilling rgb values!\n");
}