/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_drctns.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 12:12:38 by fsarbout          #+#    #+#             */
/*   Updated: 2020/12/11 01:33:24 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collect_data.h"

void    treat_north(char **element_data)
{
    if ((ft_strncmp(element_data[0], "NO" ,3)))
        print_error(10);
    if (lenght(element_data) != 2)
        print_error(10);
    if(g_dt.n == 1)
        print_error(11);
    g_dt.n = 1;
   if (!(g_dt.img_no = mlx_xpm_file_to_image(g_dt.mlx, element_data[1]
    ,&g_dt.width, &g_dt.height)))
    {
        printf("|*%s*|" , element_data[1]);
        printf("|*%s*|" , g_dt.img_no);
        print_error(3);
    }
}
void    treat_south(char **element_data)
{
    if ((ft_strncmp(element_data[0], "SO" ,3)))
        print_error(10);
    if (lenght(element_data) != 2)
        print_error(10);
    if(g_dt.so == 1)
        print_error(11);
    g_dt.so = 1;
    if (!(g_dt.img_so = mlx_xpm_file_to_image(g_dt.mlx,
              element_data[1], &g_dt.width, &g_dt.height)))
    {
        printf("SOUTH||%s||\n" , element_data[1]);
        printf("SOUTH*%s*\n" , g_dt.img_so);
        print_error(3);
    }
}
void    treat_east(char **element_data)
{
    if ((ft_strncmp(element_data[0], "EA" ,3)))
        print_error(10);
    if (lenght(element_data) != 2)
        print_error(10);
    if(g_dt.e == 1)
        print_error(11);
    g_dt.e = 1;
     if (!(g_dt.img_ea = mlx_xpm_file_to_image(g_dt.mlx, element_data[1],
              &g_dt.width, &g_dt.height)))
          print_error(3);
}
void    treat_west(char **element_data)
{
    if ((ft_strncmp(element_data[0], "WE" ,3)))
        print_error(10);
    if (lenght(element_data) != 2)
        print_error(10);
    if(g_dt.w == 1)
        print_error(11);
    g_dt.w = 1;
    if (!(g_dt.img_ea = mlx_xpm_file_to_image(g_dt.mlx, element_data[1],
             &g_dt.width, &g_dt.height)))
         print_error(3);  
}