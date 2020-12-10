/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 20:26:35 by fsarbout          #+#    #+#             */
/*   Updated: 2020/12/10 06:02:30 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collect_data.h"
#include <float.h>

void    cast_rays()
{
    // int column;
    float rayangle;
    // int ray;
    int numrays;
    int i;
    
    // column = 0;
    numrays = g_data.rsltn_w / WALL_S_W ;
    rayangle = g_data.plyr_angl - (FOV / 2);
    i = 0;
    
    while (i < numrays)
    {
        // dda_ray(rayangle);
        fix_cast_angle(rayangle);
        ray_castintg(rayangle);
        print_line(g_data.wallhitx, g_data.wallhity);
        rayangle += FOV / numrays;
        i++;
        // column++;
    }
   
}

void    dda_ray(double rayangle)
{ 
    double  y1;
    double  x1;
    int     i;
    
    i = 0;
    x1 = g_data.pos_x ;
    y1 = g_data.pos_y ; 
    while (i < TILE)
    {
        g_data.addrmlx[(int)( y1) * (g_data.long_l * TILE) + (int)( x1)] = 0x0CFCD0;
        x1 = x1 + cos(rayangle);
        y1 = y1 + sin(rayangle);
        i++;
    }
}
// i just a counter

// x1 the point from where to start

///////    new work 

float   normalize_angle(float angle)
{
    angle = remainder(angle , (2 * M_PI));
    // angle = angle % (2 * M_PI));
    if (angle < 0)
        angle = (2 * M_PI) + angle;
        return (angle);
}

void    fix_cast_angle(float rayangle)
{
    rayangle = normalize_angle(rayangle);
    g_mv.raydown = rayangle > 0 && rayangle < M_PI;
    g_mv.rayup = !g_mv.raydown;
    g_mv.rayright = rayangle < 0.5 * M_PI || rayangle > 1.5 * M_PI;
    g_mv.rayleft = !g_mv.rayright;
}

void    ray_castintg(float rayangle) //castRay with pikuma
{

    /////calculate if the next coordinate of player will hit a wall
    
    //////////
    float hhitdis;
    float xstep;
    float ystep;
     float intrceptx;
    float intrcepty;
    ///////////////////////////////////////////
    // HORIZONTAL RAY-GRID INTERSECTION CODE
    ///////////////////////////////////////////
    int horzhit;
    // float checkx;
    // float checky;
    float nxthorzhitx;
    float nxthorzhity;
    //////the main idea is that we check the intersection of the ray with 
    //the borders of the cubs in the map and check if it hits a wall or not to check the next intersection
  
    hhitdis = 0;
    g_data.horwllhitx = 0;
    g_data.horwllhity = 0;
    // checkx = 0;
    // checky = 0;
    horzhit = 0;
    // find the y-coordinate of the closest horizontal grid intersenct
    //// if i.e the tile is 32 the y inter well be a multiple of 32, the floor function well give as this number
    intrcepty = floor(g_data.pos_y / TILE) * TILE;
    intrcepty += g_mv.raydown ? TILE : 0;
    // find the x-coordinate of the closest horizontal grid intersection
    //tan = (opposite/adjacent) ///opp = py - ay ///adj = px - ax ////so we get the equation below
    //p(x,y) player coordinate ///a(x,y) intersection point coordinate
    intrceptx = g_data.pos_x + (intrcepty - g_data.pos_y) / tan(rayangle);
    //////calculate the increment xstep and ystep , delta y and delta x are const so we have just 
    //to calculate the first intersection and the const value of each step
    ystep = TILE;
    ///check the angle of the ray to give negative or positive value
    ystep *= g_mv.rayup ? -1 : 1;
    ////tan(alpha) = TILE(which is the opposite) / xstep(which is the adjacent)
    xstep = TILE / tan(rayangle);
    /////////////untill the moment everything is clear
    xstep *= (g_mv.rayleft && xstep > 0) ? -1 : 1;
    xstep *= (g_mv.rayright && xstep < 0) ? -1 : 1;
    nxthorzhitx = intrceptx;
    nxthorzhity = intrcepty;
    /////the point gonna exactly on the line border so we forced to move one pixel inside the cub 
    if (g_mv.rayup)
        nxthorzhity--;
    ////////////// 
    while (nxthorzhitx >= 0 && nxthorzhitx <= (g_data.long_l * TILE)  
        && nxthorzhity >= 0 && nxthorzhity <= (g_data.nbr_lines * TILE))
    {
        // checkx = nxthorzhitx;
        // checky = nxthorzhity + (g_mv.rayup ? -1 : 0);
        if (hit_wall(nxthorzhitx, nxthorzhity + (g_mv.rayup ? -1 : 0)))
        {
            horzhit = 1;
            g_data.horwllhitx = nxthorzhitx;
            g_data.horwllhity = nxthorzhity;
            // print_line(g_data.wallhitx, g_data.wallhitx);
            break;
        }
        else
        {
            nxthorzhitx +=  xstep;
            nxthorzhity +=  ystep;
        }
    }
    // ///////////////////////////////////////////
    // // VERTICAL RAY-GRID INTERSECTION CODE
    // ///////////////////////////////////////////
    int verthit;
    // float checkvx;
    // float checkvy;
    float vhitdis;
    float nxtverhitx;
    float nxtverhity;
  
    g_data.verwllhitx = 0;
    g_data.verwllhity = 0;
    // checkx = 0;
    // checky = 0;
    vhitdis = 0;
    verthit = 0;
    intrceptx = floor(g_data.pos_x / TILE) * TILE;
    intrceptx += g_mv.rayright ? TILE : 0;
    
    intrcepty = g_data.pos_y + (intrceptx - g_data.pos_x) * tan(rayangle);
    
    xstep = TILE;
    xstep *= g_mv.rayleft ? -1 : 1;
    
    ystep = TILE * tan(rayangle);
    ystep *= (g_mv.rayup && ystep > 0) ? -1 : 1;
    ystep *= (g_mv.raydown && ystep < 0) ? -1 : 1;
    
    nxtverhitx = intrceptx;
    nxtverhity = intrcepty;
    if (g_mv.rayleft)
        nxtverhitx--;
    ////////////// 
    while (nxtverhitx >= 0 && nxtverhitx <= (g_data.long_l * TILE)  
        && nxtverhity >= 0 && nxtverhity <= (g_data.nbr_lines * TILE))
    {
        // checkvx = nxtverhitx;
        // checkvy = nxtverhity + (g_mv.rayup ? -1 : 0);
        if (hit_wall(nxtverhitx, nxtverhity + (g_mv.rayup ? -1 : 0)))
        {
            verthit = 1;
            g_data.verwllhitx = nxtverhitx;
            g_data.verwllhity = nxtverhity;
            // print_line(g_data.wallhitx, g_data.wallhitx);
            break;
        }
        else
        {
            nxtverhitx +=  xstep;
            nxtverhity +=  ystep;
        }
    }
    //calculate both horizontal and vertical distances and chose the smallest value 
    hhitdis = (horzhit) ? calculate_dist(g_data.horwllhitx,g_data.horwllhity) : FLT_MAX;
    vhitdis = (horzhit) ? calculate_dist(g_data.verwllhitx,g_data.verwllhity) : FLT_MAX;

    g_data.wallhitx = (hhitdis < vhitdis) ? g_data.horwllhitx : g_data.verwllhitx;
    g_data.wallhity = (hhitdis < vhitdis) ? g_data.horwllhity : g_data.verwllhity;
    g_data.distance = (hhitdis < vhitdis) ? hhitdis : vhitdis;    
}
float    calculate_dist(float x2, float y2)
{
    int x1;
    int y1;

    x1 = g_data.pos_x;
    y1 = g_data.pos_y;
    return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void print_line (int x1, int y1)
{
  int x0 = floor(g_data.pos_x);
  int y0 = floor(g_data.pos_y);
  int dx =  abs (x1 - x0), sx = x0 < x1 ? 1 : -1;
  int dy = -abs (y1 - y0), sy = y0 < y1 ? 1 : -1; 
  int err = dx + dy, e2; /* error value e_xy */
  
  while (1)
  {  
    if ((int)x0 < 0 || (int)x0 > g_data.rsltn_w * TILE || (int)y0 < 0 || (int)y0 > g_data.rsltn_h  * TILE
        || (int)x0 > g_data.long_l * TILE || (int)y0 > g_data.nbr_lines * TILE)
        break;
        
    g_data.addrmlx[((int)(y0) * (g_data.long_l * TILE) + (int)(x0))] = 0x0CFCD0;
    if (x0 == x1 && y0 == y1) break;
    e2 = 2 * err;
    if (e2 >= dy) { err += dy; x0 += sx; } /* e_xy+e_x > 0 */
    if (e2 <= dx) { err += dx; y0 += sy; } /* e_xy+e_y < 0 */
  }
}

// void        rayspush(t_data *data, double x2, double y2)
// {
//     double        y1;
//     double        x1;
//     double        xinc;
//     double        yinc;
//     int            steps;

//     x1 = g_player.xplayer * MINIMAP_SCALE_FACTOR;
//     y1 = g_player.yplayer * MINIMAP_SCALE_FACTOR;
//     g_tilecolor = 0xFF4500;
//     steps = abs((int)x2 - (int)x1) > abs((int)y2 - (int)y1) ? abs((int)x2 - (int)x1) : abs((int)y2 - (int)y1);
//     xinc = (x2 - x1) / (double)steps;
//     yinc = (y2 - y1) / (double)steps;
//     x2 = -1;
//     while (++x2 <= steps)
//     {
//         data->addr[(int)y1 * WIN_WIDTH + (int)x1] = g_tilecolor;
//         x1 = x1 + xinc;
//         y1 = y1 + yinc;
//     }
//     return ;
// }

// void    draw_ray(float x1 , float y1)
// {
//     float x0;
//     float y0;
//     float xinc;
//     float yinc;
//     int steps;

//     x0 = g_data.pos_x;
//     y0 = g_data.pos_y;
//     steps = abs((int)x1 - (int)x0) > abs((int)y1 - (int)y0) 
//         ? abs((int)x1 - (int)x0) : abs((int)y1 - (int)y0);
//     xinc = (x1 - x0) / (float)steps;
//     yinc = (y1 - y0) / (float)steps;
//     // x1 = -1;
//     while (x1 <= steps)
//     {
//         // g_data.addrmlx[(int)y0 * TILE * g_data.long_l + (int)x0] = 0x0CFCD0;
//         g_data.addrmlx[((int)(y0) * (g_data.long_l * TILE) + (int)(x0))] = 0x0CFCD0;
//         x1 = x1 + xinc;
//         y1 = y1 + yinc;
//         x1++;
//         // printf("draw raaaaaaaaaaaay");
//     }
//     return ;
// }