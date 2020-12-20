/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 23:39:30 by fsarbout          #+#    #+#             */
/*   Updated: 2020/12/20 00:09:48 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    horizontal_inter(float xstep, float ystep, float intrceptx, float intrcepty)
{
    float nxthorzhitx;
    float nxthorzhity;
    
    g_dt.hhitdis = 0;
    g_dt.horwllhitx = 0;
    g_dt.horwllhity = 0;
    g_dt.horzhit = 0;
    intrcepty = (int)(g_dt.pos_y / TILE) * TILE;
    intrcepty += g_mv.raydown ? TILE : 0;
    intrceptx = g_dt.pos_x + (intrcepty - g_dt.pos_y) / tan(g_mv.rayangle);
    ystep = TILE;
    ystep *= g_mv.rayup ? -1 : 1;
    xstep = ystep / tan(g_mv.rayangle);
    xstep *= (g_mv.rayleft && xstep > 0) ? -1 : 1;
    xstep *= (g_mv.rayright && xstep < 0) ? -1 : 1;
    nxthorzhitx = intrceptx;
    nxthorzhity = intrcepty;
    horizontal_loop(xstep, ystep, nxthorzhitx, nxthorzhity);   
}

void    horizontal_loop(float xstep,float ystep,float nxthorzhitx, float nxthorzhity)
{    
    while (nxthorzhitx >= 0 && nxthorzhitx <= (g_dt.long_l * TILE)  
        && nxthorzhity >= 0 && nxthorzhity <= (g_dt.nbr_lines * TILE))
    {
        g_dt.checkx = nxthorzhitx;
        g_dt.checky = nxthorzhity + (g_mv.rayup ? -1 : 0 );
        if (hit_wall(g_dt.checkx, g_dt.checky ))
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

void    vertical_inter(float xstep, float ystep, float intrceptx, float intrcepty)
{
    float nxtverhitx;
    float nxtverhity;

    g_dt.verwllhitx = 0;
    g_dt.verwllhity = 0;
    g_dt.vhitdis = 0;
    g_dt.verthit = 0;
    intrceptx = (int)(g_dt.pos_x / TILE) * TILE;
    intrceptx += g_mv.rayright ? TILE : 0;
    intrcepty = g_dt.pos_y + (intrceptx - g_dt.pos_x) * tan(g_mv.rayangle);
    xstep = TILE;
    xstep *= g_mv.rayleft ? -1 : 1;
    ystep = TILE * tan(g_mv.rayangle);
    ystep *= (g_mv.rayup && ystep > 0) ? -1 : 1;
    ystep *= (g_mv.raydown && ystep < 0) ? -1 : 1;
    nxtverhitx = intrceptx;
    nxtverhity = intrcepty;
    vertical_loop(xstep, ystep, nxtverhitx, nxtverhity);
}

void    	vertical_loop(float xstep,float ystep,float nxtverhitx, float nxtverhity)
{
    while (nxtverhitx >= 0 && nxtverhitx <= (g_dt.long_l * TILE)  
        && nxtverhity >= 0 && nxtverhity <= (g_dt.nbr_lines * TILE))
    {
        g_dt.checkx = nxtverhitx + (g_mv.rayleft ? -1 :0);
        g_dt.checky = nxtverhity ;
         if (hit_wall(g_dt.checkx, g_dt.checky))
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