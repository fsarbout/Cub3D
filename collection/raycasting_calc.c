/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_calc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 00:34:37 by fsarbout          #+#    #+#             */
/*   Updated: 2021/01/01 14:39:18 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <float.h>

// t_sprite    get_sprite_position(int x, int y)
// {
//     t_sprite        sp;

//     sp.x = x;
//     sp.y = y;
//     return (sp);
// // }
// int     hit_wall_h(t_dt dt, t_mv mv)
// {
//     int mapx;
//     int mapy;
//     if(mv.rayup && !dt.verthit)
//          dt.wallhity -= 1;
//     if (!mv.rayright && dt.verthit)
//         dt.wallhitx -= 1;
//     //printf("%f\n", mv.rayangle);
//     mapx = floor(dt.wallhitx / TILE);
//     mapy = floor(dt.wallhity / TILE);
//     if (g_dt.mmp[mapy][mapx] == '2')
//     {
//          rect(mapx, mapy, 0xFF00FA);
//         // append(&g_lst, get_sprite_position(mapx, mapy));
//         return (1);
//     }
//     else 
//         return (0);
// }

//////should be wihtout global variable 
// void    get_center_coor(t_list *sp)
// {   
//     int x;
//     int y;
    
//     x = (int)(g_sp.x / TILE);
//     g_sp.center_x = (int)(x * TILE + (TILE / 2)) ;
//     y = (int)(g_sp.y / TILE);
//     g_sp.center_y = (int)(y * TILE + (TILE / 2)) ;
// }



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
        // if (hit_wall_h(dt[i], mv[i]))
        // {
        //     dt[i].sp = 1;
        // }
        // printf("%d %d \n" , g_sp.x , g_sp.y);
        g_mv.rayangle += FOV / g_dt.numrays;
        i++;
    }
    // t_list *lst = g_lst;
    // while (lst)
    // {
    //         printf("%d %d\n", lst->sp.x, lst->sp.y);
    //         lst = lst->next;
    // }
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

void    ray_casting( t_dt *dt , t_mv *mv, int i)
{
    
    float xstep;
    float ystep;
    // t_list *sprite;
    
    xstep = 0;
    ystep = 0;
    horizontal_inter(xstep, ystep);
    vertical_inter(xstep, ystep);
 
    g_dt.hhitdis = (g_dt.horzhit) ? calculate_dist(g_dt.horwllhitx,g_dt.horwllhity) : FLT_MAX;
    g_dt.vhitdis = (g_dt.verthit) ? calculate_dist(g_dt.verwllhitx,g_dt.verwllhity) : FLT_MAX;

    ///check if sprite
    /*////////////////sp////////////////*/
    // g_sp.hhitdis = (g_sp.horzhit) ? calculate_dist(g_sp.sp_horhitx ,g_sp.sp_horhity) : FLT_MAX;
    // g_sp.vhitdis = (g_sp.verthit) ? calculate_dist(g_sp.sp_verhitx ,g_sp.sp_verhity) : FLT_MAX;
     /*////////////////sp////////////////*/
    

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
    //////////////////////////////////////////////////////
     /*////////////////sp////////////////*/
    // if (g_sp.vhitdis < g_sp.hhitdis)
    // {   
    //     g_sp.dist_plyr_sp = g_sp.vhitdis;
    //     g_sp.x = g_sp.sp_verhitx;
    //     g_sp.y = g_sp.sp_verhity;
    //     // dt[i].wllhitcnt = g_dt.verwllcnt;
    //     ///
    //     g_sp.verthit = 1;
    // }
    // else 
    // {
    //     g_sp.dist_plyr_sp = g_sp.hhitdis;
    //     g_sp.x = g_sp.sp_horhitx;
    //     g_sp.y = g_sp.sp_horhity;
    //     // dt[i].wllhitcnt = g_dt.verwllcnt;
    //     ///
    //     g_sp.verthit = 0;
    // }
 /*////////////////sp////////////////*/
    
    mv[i].rayangle = g_mv.rayangle;
    mv[i].raydown = g_mv.raydown;
    mv[i].rayup = g_mv.rayup;
    mv[i].rayleft = g_mv.rayleft;
    mv[i].rayright = g_mv.rayright;

    // get_center_coor();
    
    // printf("%d  %d\n", g_sp.x, g_sp.y );
    // printf("%d  %d\n",g_sp.center_x ,g_sp.center_y ); 
   
}
float    calculate_dist(float x2, float y2)
{
    int x1;
    int y1;

    x1 = g_dt.pos_x;
    y1 = g_dt.pos_y;
    return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}
