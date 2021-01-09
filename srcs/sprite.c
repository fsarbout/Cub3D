/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 06:14:27 by fsarbout          #+#    #+#             */
/*   Updated: 2021/01/06 11:42:46 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


void    treat_sprite(char **element_data)
{
    if (!(g_txt.sp_txt = (int*)mlx_xpm_file_to_image(g_dt.mlx, element_data[1]
        ,&g_dt.width, &g_dt.height)))
        print_error("   path of sprite texture invlid!\n");
    g_txt.sprite_txt = (int*)mlx_get_data_addr(g_txt.sp_txt, &g_dt.bpp, &g_dt.size_line, &g_dt.endian);
    
}

