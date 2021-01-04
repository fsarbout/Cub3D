/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 11:37:07 by fsarbout          #+#    #+#             */
/*   Updated: 2021/01/04 09:46:08 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_coor    get_center_coor(float spx, float spy)
{   
    t_coor center;
    t_list *list;
    
    list = malloc(sizeof(t_list));
    if(g_mv.rayup && g_dt.verthit)
         spy -= 1;
    if (!g_mv.rayright && g_dt.verthit)
        spx -= 1;
    
    center.x = (int)(spx / TILE);
    list->sp.center.x = (int)(center.x * TILE + (TILE / 2));
    center.y = (int)(spy / TILE);
    list->sp.center.y = (int)(center.y * TILE + (TILE / 2));
    // printf("%f  %f\n", center.x ,center.y );
    return (list->sp.center);
}

// t_coor    get_center_coor(float spx, float spy)
// {   
//     t_coor center;
//     t_list *list;
    
//     list = malloc(sizeof(t_list));
//     if(g_mv.rayup && g_dt.verthit)
//          spy -= 1;
//     if (!g_mv.rayright && g_dt.verthit)
//         spx -= 1;
    
//     center.x = (int)(spx / TILE);
//     list->sp.center.x = (int)(center.x * TILE + (TILE / 2));
//     center.y = (int)(spy / TILE);
//     list->sp.center.y = (int)(center.y * TILE + (TILE / 2));
//     // printf("%f  %f\n", center.x ,center.y );
//     return (list->sp.center);
// }