/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 11:37:07 by fsarbout          #+#    #+#             */
/*   Updated: 2021/01/10 12:41:25 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_coor    get_center_coor(float spx, float spy)
{   
    t_coor center;

    center.x = (int)(spx / TILE) * TILE + (TILE / 2);
    center.y = (int)(spy / TILE) * TILE + (TILE / 2);
    return (center);
}

int     check_exists(t_list *lst, float x, float y)
{
    while (lst)
    {
        if (lst->sp.center.x == x && lst->sp.center.y == y)
            return (1);
        lst = lst->next;
    }
    return (0);
}

void    sprite_calc(t_list **list)
{
    t_sp sp;
    float plyr_angle;
    float rays;
    
  
    sp.x = g_dt.checkx;
    sp.y = g_dt.checky;
    sp.center = get_center_coor(sp.x, sp.y);
    sp.dist_plyr_sp = calculate_dist(sp.center.x, sp.center.y);
    printf("distance %f\n" ,  sp.dist_plyr_sp);
    
    ////////////////////////////////////////////////////////////////////////
    // sp.angle = atan2((sp.center.y - g_dt.pos_y) , (sp.center.x - g_dt.pos_x));
    sp.angle = atan2((sp.center.y - g_dt.pos_y) , (sp.center.x - g_dt.pos_x));
    // sp.angle = normalize_sp_angle(sp.angle);
    plyr_angle = g_dt.plyr_angl - (FOV / 2);
    sp.angle = sp.angle - plyr_angle;
    sp.angle = normalize_sp_angle(sp.angle);
    printf(" angle %f\n   " ,  sp.angle * (180 / M_PI) );
    ////////////////////////////////////////////////////////////////////////
    g_dt.distpplane = ((g_dt.long_l * TILE) / 2) / tan(FOV / 2);
    ////////////////////////////////////////////////////////////////////////
    sp.height = (TILE / sp.dist_plyr_sp) * g_dt.distpplane ;
    sp.height_s = -sp.height / 2 + (g_dt.nbr_lines * TILE) / 2;
    sp.height_s = sp.height_s < 0 ? 0 : sp.height_s;
    sp.height_e = sp.height / 2 +(g_dt.nbr_lines * TILE) / 2;
    sp.height_e = sp.height_e  > (g_dt.nbr_lines * TILE) ? (g_dt.nbr_lines * TILE) - 1 : sp.height_e;
    ////////////////////////////////////////////////////////////////////////
    rays = (FOV / (g_dt.long_l * TILE)) ;
    sp.width_s = (sp.angle / rays) ;
    sp.width_e = sp.width_s + sp.height;
    if (!check_exists(*list, sp.center.x, sp.center.y))
    {
        lst_add_back(list, sp);
//     //     printf("center x %f  center y %f\n", sp.center.x, sp.center.y);
    }
}

float		normalize_sp_angle(float angle)
{
	// sp_angle  = fmod(sp_angle, 2 * M_PI);
	// sp_angle += (sp_angle < 0) ? 2 * M_PI : 0;
    		if ((g_dt.plyr_angl - (FOV / 2)) - angle > M_PI)
			angle = angle + 2 * M_PI;
		if (angle - (g_dt.plyr_angl - (FOV / 2)) > M_PI)
			angle = angle - 2 * M_PI;
    return (angle);
}