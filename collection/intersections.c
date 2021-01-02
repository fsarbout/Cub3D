/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 23:39:30 by fsarbout          #+#    #+#             */
/*   Updated: 2021/01/02 19:47:36 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    horizontal_inter(float xstep, float ystep)
{   
    g_dt.hhitdis = 0;
    g_dt.horwllhitx = 0;
    g_dt.horwllhity = 0;
    g_dt.horzhit = 0;
    g_dt.intery = (int)(g_dt.pos_y / TILE) * TILE;
    g_dt.intery += g_mv.raydown ? TILE : 0;
    g_dt.interx = g_dt.pos_x + (g_dt.intery - g_dt.pos_y) / tan(g_mv.rayangle);//
    ystep = TILE;
    ystep *= g_mv.rayup ? -1 : 1;
    xstep = ystep / tan(g_mv.rayangle);
    xstep *= (g_mv.rayleft && xstep > 0) ? -1 : 1;
    xstep *= (g_mv.rayright && xstep < 0) ? -1 : 1;
    g_dt.nxthorhitx = g_dt.interx;
    g_dt.nxthorhity = g_dt.intery;
    horizontal_loop(xstep, ystep);   
}

void    horizontal_loop(float xstep,float ystep)
{    
    t_list *list;

    list = malloc(sizeof(t_list));
    while (g_dt.nxthorhitx >= 0 && g_dt.nxthorhitx <= (g_dt.long_l * TILE)  
        && g_dt.nxthorhity >= 0 && g_dt.nxthorhity <= (g_dt.nbr_lines * TILE))
    {
        g_dt.checkx = g_dt.nxthorhitx;
        g_dt.checky = g_dt.nxthorhity + (g_mv.rayup ? -1 : 0 );

        if (hit_wall(g_dt.checkx, g_dt.checky ) == '2')
            sprite_calc(list);
            //    g_dt.sp = 1;
  
        if (hit_wall(g_dt.checkx, g_dt.checky ) == '1')
        {
            g_dt.horzhit = 1;
            g_dt.horwllhitx = g_dt.nxthorhitx;
            g_dt.horwllhity = g_dt.nxthorhity;
            break;
        }
        else
        {
            g_dt.nxthorhitx +=  xstep;
            g_dt.nxthorhity +=  ystep;
        }
        
    }
}

void    vertical_inter(float xstep, float ystep)
{
    g_dt.verwllhitx = 0;
    g_dt.verwllhity = 0;
    g_dt.vhitdis = 0;
    g_dt.verthit = 0;
    g_dt.interx = (int)(g_dt.pos_x / TILE) * TILE;
    g_dt.interx += g_mv.rayright ? TILE : 0;
    g_dt.intery = g_dt.pos_y + (g_dt.interx - g_dt.pos_x) * tan(g_mv.rayangle);
    xstep = TILE;
    xstep *= g_mv.rayleft ? -1 : 1;
    ystep = TILE * tan(g_mv.rayangle);
    ystep *= (g_mv.rayup && ystep > 0) ? -1 : 1;
    ystep *= (g_mv.raydown && ystep < 0) ? -1 : 1;
    g_dt.nxtvrthitx = g_dt.interx;
    g_dt.nxtvrthity = g_dt.intery;
    vertical_loop(xstep, ystep);
}

void    	vertical_loop(float xstep,float ystep)
{
    t_list *list;
    
    list = malloc(sizeof(t_list));
    while (g_dt.nxtvrthitx >= 0 && g_dt.nxtvrthitx <= (g_dt.long_l * TILE)  
        && g_dt.nxtvrthity >= 0 && g_dt.nxtvrthity <= (g_dt.nbr_lines * TILE))
    {
        g_dt.checkx = g_dt.nxtvrthitx + (g_mv.rayleft ? -1 :0);
        g_dt.checky = g_dt.nxtvrthity ;

        if (hit_wall(g_dt.checkx, g_dt.checky ) == '2')
          sprite_calc(list);
        if (hit_wall(g_dt.checkx, g_dt.checky) == '1')
        {
            g_dt.verthit = 1;
            g_dt.verwllhitx = g_dt.nxtvrthitx;
            g_dt.verwllhity = g_dt.nxtvrthity;
            break;
        }
        else
        {
            g_dt.nxtvrthitx +=  xstep;
            g_dt.nxtvrthity +=  ystep;
        }
    }
}

void    sprite_calc(t_list *list)
{
    list = malloc(sizeof(t_list));
    t_coor center;
    float angle;
    
    list->sp.x = g_dt.checkx;
    list->sp.y = g_dt.checky;
    list->sp.sp_verhitx = g_dt.nxtvrthitx;
    list->sp.sp_verhity = g_dt.nxtvrthity;
    list->sp.verthit = 1;
    center = get_center_coor(list->sp.x, list->sp.y);
    list->sp.dist_plyr_sp = calculate_dist(list->sp.center.x, list->sp.center.y);
    angle = atan((list->sp.center.y - g_dt.pos_y ) / (list->sp.center.x - g_dt.pos_x));
    list->next = list;
    printf("%f --- %f\n", list->sp.center.x ,list->sp.center.y);
    
}

      //    g_dt.sp = 1;
        
        // {
        //     g_sp.x = g_dt.checkx;
        //     g_sp.y = g_dt.checky;
        //     g_sp.sp_horhitx = nxthorzhitx;
        //     g_sp.sp_horhity = nxthorzhity;
        //     g_sp.horzhit = 1;
        //     // printf("%d  %d\n", g_sp.x, g_sp.y );
        //     // printf("%d  %d\n",g_sp.center_x ,g_sp.center_y );
            
        // }