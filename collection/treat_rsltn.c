/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_rsltn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 14:45:35 by fsarbout          #+#    #+#             */
/*   Updated: 2020/11/29 10:14:23 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collect_data.h"

void    treat_rsltn(char **element_data)
{
    if (g_data.r == 1)
        print_error(11);
    g_data.r = 1;
    if ((ft_strncmp(element_data[0], "R" ,2)))
        print_error(10);
    if (lenght(element_data) != 3)
        print_error(10);
    if (!str_of_num(element_data[1]))
        print_error(10);
   g_data.rsltn_w = ft_atoi(element_data[1]);
    g_data.rsltn_w > MAX_WIDTH ? g_data.rsltn_w =  MAX_WIDTH : 0;
    if (!str_of_num(element_data[2]))
        print_error(10);
   g_data.rsltn_h = ft_atoi(element_data[2]);
   g_data.rsltn_h > MAX_HEIGHT ? g_data.rsltn_h =  MAX_HEIGHT : 0;
}