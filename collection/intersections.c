/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 23:39:30 by fsarbout          #+#    #+#             */
/*   Updated: 2020/12/24 18:48:30 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    horizontal_inter(float xstep, float ystep)
{
    float nxthorzhitx;
    float nxthorzhity;
    
    g_dt.hhitdis = 0;
    g_dt.horwllhitx = 0;
    g_dt.horwllhity = 0;
    g_dt.horzhit = 0;
    g_dt.intery = (int)(g_dt.pos_y / TILE) * TILE;
    g_dt.intery += g_mv.raydown ? TILE : 0;
    g_dt.interx = g_dt.pos_x + (g_dt.intery - g_dt.pos_y) / tan(g_mv.rayangle);
    ystep = TILE;
    ystep *= g_mv.rayup ? -1 : 1;
    xstep = ystep / tan(g_mv.rayangle);
    xstep *= (g_mv.rayleft && xstep > 0) ? -1 : 1;
    xstep *= (g_mv.rayright && xstep < 0) ? -1 : 1;
    nxthorzhitx = g_dt.interx;
    nxthorzhity = g_dt.intery;
    horizontal_loop(xstep, ystep, nxthorzhitx, nxthorzhity);   
}

void    horizontal_loop(float xstep,float ystep,float nxthorzhitx, float nxthorzhity)
{    
    while (nxthorzhitx >= 0 && nxthorzhitx <= (g_dt.long_l * TILE)  
        && nxthorzhity >= 0 && nxthorzhity <= (g_dt.nbr_lines * TILE))
    {
        g_dt.checkx = nxthorzhitx;
        g_dt.checky = nxthorzhity + (g_mv.rayup ? -1 : 0 );

        if (hit_wall(g_dt.checkx, g_dt.checky ) == '2')
        {
            g_sp.x = g_dt.checkx;
            g_sp.y = g_dt.checky;
            g_sp.sp_horhitx = nxthorzhitx;
            g_sp.sp_horhity = nxthorzhity;
            g_sp.horzhit = 1;
            // printf("%d  %d\n", g_sp.x, g_sp.y );
            // printf("%d  %d\n",g_sp.center_x ,g_sp.center_y );
            
        }
        if (hit_wall(g_dt.checkx, g_dt.checky ) == '1')
        {
            g_dt.horzhit = 1;
            g_dt.horwllhitx = nxthorzhitx;
            g_dt.horwllhity = nxthorzhity;
            break;
        }
        else
        {
            nxthorzhitx +=  xstep;
            nxthorzhity +=  ystep;
        }
        
    }
}

void    vertical_inter(float xstep, float ystep)
{
    float nxtverhitx;
    float nxtverhity;

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
    nxtverhitx = g_dt.interx;
    nxtverhity = g_dt.intery;
    vertical_loop(xstep, ystep, nxtverhitx, nxtverhity);
}

void    	vertical_loop(float xstep,float ystep,float nxtverhitx, float nxtverhity)
{
    while (nxtverhitx >= 0 && nxtverhitx <= (g_dt.long_l * TILE)  
        && nxtverhity >= 0 && nxtverhity <= (g_dt.nbr_lines * TILE))
    {
        g_dt.checkx = nxtverhitx + (g_mv.rayleft ? -1 :0);
        g_dt.checky = nxtverhity ;

        if (hit_wall(g_dt.checkx, g_dt.checky ) == '2')
        {
            g_sp.x = g_dt.checkx;
            g_sp.y = g_dt.checky;
            g_sp.sp_verhitx = nxtverhitx;
            g_sp.sp_verhity = nxtverhity;
            g_sp.verthit = 1;
        } 
        if (hit_wall(g_dt.checkx, g_dt.checky) == '1')
        {
            g_dt.verthit = 1;
            g_dt.verwllhitx = nxtverhitx;
            g_dt.verwllhity = nxtverhity;
            break;
        }
        else
        {
            nxtverhitx +=  xstep;
            nxtverhity +=  ystep;
        }
    }
}