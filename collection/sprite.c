/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 06:14:27 by fsarbout          #+#    #+#             */
/*   Updated: 2021/01/01 12:44:44 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void    treat_sprite(char **element_data)
{
    if (!(g_txt.sp_txt = (int*)mlx_xpm_file_to_image(g_dt.mlx, element_data[1]
        ,&g_dt.width, &g_dt.height)))
        print_error("   path of sprite texture invlid!\n");
}

// void    sprite_angle()
// {
//     float angle_centre;

//     angle_centre = atan()
    
    

// }