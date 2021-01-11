/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 23:39:30 by fsarbout          #+#    #+#             */
/*   Updated: 2021/01/11 19:34:14 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    horizontal_inter(t_list **list, t_dt *dt, int i)
{   
    g_dt.hhitdis = 0;
    g_dt.horwllhitx = 0;
    g_dt.horwllhity = 0;
    g_dt.horzhit = 0;
    g_dt.intery = (int)(g_dt.pos_y / TILE) * TILE;
    g_dt.intery += g_dt.raydown ? TILE : 0;
    g_dt.interx = g_dt.pos_x + (g_dt.intery - g_dt.pos_y) / tan(g_dt.rayangle);//
    g_dt.ystep = TILE;
    g_dt.ystep *= g_dt.rayup ? -1 : 1;
    g_dt.xstep = g_dt.ystep / tan(g_dt.rayangle);
    g_dt.xstep *= (g_dt.rayleft && g_dt.xstep > 0) ? -1 : 1;
    g_dt.xstep *= (g_dt.rayright && g_dt.xstep < 0) ? -1 : 1;
    g_dt.nxthorhitx = g_dt.interx;
    g_dt.nxthorhity = g_dt.intery;
    horizontal_loop(list , dt, i);   
}

void    horizontal_loop(t_list **list, t_dt *dt, int i )
{    
    while (g_dt.nxthorhitx >= 0 && g_dt.nxthorhitx <= g_dt.rsltn_w  
        && g_dt.nxthorhity >= 0 && g_dt.nxthorhity <= g_dt.rsltn_h)
    {
        g_dt.checkx = g_dt.nxthorhitx;
        g_dt.checky = g_dt.nxthorhity + (g_dt.rayup ? -1 : 0 );
        /////
        if (hit_wall(g_dt.checkx, g_dt.checky) == '2')
        {
            // dt[i].spr = 1;
            // g_dt.sp_hitx = g_dt.checkx;
            // g_dt.sp_hity = g_dt.checky;
            sprite_calc(list, dt , i);
        }
        if (hit_wall(g_dt.checkx, g_dt.checky ) == '1')
        {
            g_dt.horzhit = 1;
            g_dt.horwllhitx = g_dt.nxthorhitx;
            g_dt.horwllhity = g_dt.nxthorhity;
            break;
        }
        else
        {
            g_dt.nxthorhitx +=  g_dt.xstep;
            g_dt.nxthorhity +=  g_dt.ystep;
        }
    }
}

void    vertical_inter(t_list **list,  t_dt *dt, int i)
{
    g_dt.verwllhitx = 0;
    g_dt.verwllhity = 0;
    g_dt.vhitdis = 0;
    g_dt.verthit = 0;
    g_dt.interx = (int)(g_dt.pos_x / TILE) * TILE;
    g_dt.interx += g_dt.rayright ? TILE : 0;
    g_dt.intery = g_dt.pos_y + (g_dt.interx - g_dt.pos_x) * tan(g_dt.rayangle);
    g_dt.xstep = TILE;
    g_dt.xstep *= g_dt.rayleft ? -1 : 1;
    g_dt.ystep = TILE * tan(g_dt.rayangle);
    g_dt.ystep *= (g_dt.rayup && g_dt.ystep > 0) ? -1 : 1;
    g_dt.ystep *= (g_dt.raydown && g_dt.ystep < 0) ? -1 : 1;
    g_dt.nxtvrthitx = g_dt.interx;
    g_dt.nxtvrthity = g_dt.intery;
    vertical_loop(list, dt, i);
}

void    	vertical_loop(t_list **list, t_dt *dt, int i)
{
    while (g_dt.nxtvrthitx >= 0 && g_dt.nxtvrthitx <= g_dt.rsltn_w  
        && g_dt.nxtvrthity >= 0 && g_dt.nxtvrthity <= g_dt.rsltn_h)
    {
        
        g_dt.checkx = g_dt.nxtvrthitx + (g_dt.rayleft ? -1 :0);
        g_dt.checky = g_dt.nxtvrthity ;
        if (hit_wall(g_dt.checkx, g_dt.checky) == '2')
        {
            // dt[i].spr = 1;
            // g_dt.sp_hitx = g_dt.checkx;
            // g_dt.sp_hity = g_dt.checky;
             sprite_calc(list, dt , i);
        }
        if (hit_wall(g_dt.checkx, g_dt.checky) == '1')
        {
            g_dt.verthit = 1;
            g_dt.verwllhitx = g_dt.nxtvrthitx;
            g_dt.verwllhity = g_dt.nxtvrthity;
            break;
        }
        else
        {
            g_dt.nxtvrthitx +=  g_dt.xstep;
            g_dt.nxtvrthity +=  g_dt.ystep;
        }
    }
}