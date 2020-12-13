/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_calc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 00:34:37 by fsarbout          #+#    #+#             */
/*   Updated: 2020/12/13 06:05:09 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collect_data.h"
#include <float.h>

void    cast_rays(t_dt *dt, t_mv *mv)
{
    // int numrays;
    int i; 
    // g_dt.numrays = g_dt.rsltn_w / WALL_S_W;
    g_mv.rayangle = g_dt.plyr_angl - (FOV / 2);
    i = 0;
    while (i < g_dt.numrays)
    {
        fix_cast_angle();
        ray_castintg(dt, mv, i);
        print_line(g_dt.wallhitx * MINIM, g_dt.wallhity * MINIM);
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

void    ray_castintg(t_dt *dt , t_mv *mv, int i)
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
    mv[i].rayangle = g_mv.rayangle;
    
    
    
    g_dt.hhitdis = (g_dt.horzhit) ? calculate_dist(g_dt.horwllhitx,g_dt.horwllhity) : FLT_MAX;
    g_dt.vhitdis = (g_dt.verthit) ? calculate_dist(g_dt.verwllhitx,g_dt.verwllhity) : FLT_MAX;

    // g_dt.hhitdis = calculate_dist(g_dt.horwllhitx,g_dt.horwllhity);
    // g_dt.vhitdis = calculate_dist(g_dt.verwllhitx,g_dt.verwllhity);

  g_dt.wallhitx = (g_dt.hhitdis < g_dt.vhitdis) ? g_dt.horwllhitx : g_dt.verwllhitx;
    g_dt.wallhity = (g_dt.hhitdis < g_dt.vhitdis) ? g_dt.horwllhity : g_dt.verwllhity;
    g_dt.distance = (g_dt.hhitdis < g_dt.vhitdis) ? g_dt.hhitdis : g_dt.vhitdis;

    // if (g_dt.vhitdis < g_dt.hhitdis)
    // {   
    //     dt[i].distance = g_dt.vhitdis;
    //     dt[i].wallhitx = g_dt.verwllhitx;
    //     dt[i].wallhity = g_dt.verwllhity;
    //     dt[i].wllhitcnt = g_dt.ho
    //     dt[i]



    // }
  
    



    
    dt[i].distance = g_dt.distance;
    dt[i].verthit = g_dt.verthit;
}
float    calculate_dist(float x2, float y2)
{
    int x1;
    int y1;

    x1 = g_dt.pos_x;
    y1 = g_dt.pos_y;
    return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}
