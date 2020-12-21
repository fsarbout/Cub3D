/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_calc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 00:34:37 by fsarbout          #+#    #+#             */
/*   Updated: 2020/12/21 06:11:14 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <float.h>

int     hit_wall_h(t_dt dt, t_mv mv)
{
    int mapx;
    int mapy;
    
    if(mv.rayup && !dt.verthit)
         dt.wallhity -= 1;
    if (!mv.rayright && dt.verthit)
        dt.wallhitx -= 1;
    //printf("%f\n", mv.rayangle);
    mapx = floor(dt.wallhitx / TILE);
    mapy = floor(dt.wallhity / TILE);
    if (g_dt.mmp[mapy][mapx] == '2')
        return (1);
    else 
        return (0);
}

void    cast_rays(t_dt *dt, t_mv *mv)
{
    // int numrays;
    int i; 
    // g_dt.numrays = g_dt.rsltn_w / WALL_S_W
    g_mv.rayangle = g_dt.plyr_angl - (FOV / 2);
    i = 0;
    while (i < g_dt.numrays)
    { 
        fix_cast_angle();
        ray_casting(dt, mv, i);
        dt[i].sp = 0;
        print_line(dt[i].wallhitx * MINIM, dt[i].wallhity * MINIM);
        if (hit_wall_h(dt[i], mv[i]))
            dt[i].sp = 1;
        g_mv.rayangle += FOV / g_dt.numrays;
        i++;
    }
}

float   normalize_angle()
{
    g_mv.rayangle = remainder(g_mv.rayangle , (2 * M_PI));
    if (g_mv.rayangle < 0)
        g_mv.rayangle = (2 * M_PI) + g_mv.rayangle;
    return (g_mv.rayangle);
}

void    fix_cast_angle()
{
    g_mv.rayangle = normalize_angle();
    g_mv.raydown = g_mv.rayangle > 0 && g_mv.rayangle < M_PI;
    g_mv.rayup = !g_mv.raydown;
    g_mv.rayright = g_mv.rayangle < 0.5 * M_PI || g_mv.rayangle > 1.5 * M_PI;
    g_mv.rayleft = !g_mv.rayright;
}

void    ray_casting(t_dt *dt , t_mv *mv, int i)
{
    
    float xstep;
    float ystep;
    float intrceptx;
    float intrcepty;
    
    xstep = 0;
    ystep = 0;
    intrceptx = 0;
    intrcepty = 0;
    horizontal_inter(xstep, ystep, intrceptx, intrcepty);
    vertical_inter(xstep, ystep, intrceptx, intrcepty);
    
    g_dt.hhitdis = (g_dt.horzhit) ? calculate_dist(g_dt.horwllhitx,g_dt.horwllhity) : FLT_MAX;
    g_dt.vhitdis = (g_dt.verthit) ? calculate_dist(g_dt.verwllhitx,g_dt.verwllhity) : FLT_MAX;

    if (g_dt.vhitdis < g_dt.hhitdis)
    {   
        dt[i].distance = g_dt.vhitdis;
        dt[i].wallhitx = g_dt.verwllhitx;
        dt[i].wallhity = g_dt.verwllhity;
        // dt[i].wllhitcnt = g_dt.verwllcnt;
        ///
        dt[i].verthit = 1;
    }
    else 
    {
        dt[i].distance = g_dt.hhitdis;
        dt[i].wallhitx = g_dt.horwllhitx;
        dt[i].wallhity = g_dt.horwllhity;
        ///
        // dt[i].wllhitcnt = g_dt.horwllcnt;
        dt[i].verthit = 0;
    }
    mv[i].rayangle = g_mv.rayangle;
    mv[i].raydown = g_mv.raydown;
    mv[i].rayup = g_mv.rayup;
    mv[i].rayleft = g_mv.rayleft;
    mv[i].rayright = g_mv.rayright;
}
float    calculate_dist(float x2, float y2)
{
    int x1;
    int y1;

    x1 = g_dt.pos_x;
    y1 = g_dt.pos_y;
    return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}
