/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 17:55:41 by fsarbout          #+#    #+#             */
/*   Updated: 2021/01/15 17:43:51 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void        draw_map()
{
	int		x;
	int		y;
    int     tilex;
    int     tiley;
    
	y = 0;
    tilex = 0 ;
    tiley = 0 ;
	while (y < g_dt.nbr_lines && y < g_dt.rsltn_h)
    {
        x = 0;
        while (x < g_dt.long_l && x < g_dt.rsltn_w)
        {
            tilex = x * TILE;
            tiley = y * TILE;
            if (g_dt.mmp[y][x] == '1')
                rect(tilex * MINIM, tiley  * MINIM, 0xFFFFFF);
            else if (g_dt.mmp[y][x] == '0' || g_dt.mmp[y][x] != ' ')
                rect(tilex * MINIM, tiley * MINIM, 0xA0A0A0);
            if (g_dt.mmp[y][x] == '2')
                 rect(tilex * MINIM, tiley * MINIM, 0xD3Df4a);
            x++;
        }
        y++;
    }
    draw_circle(0x0000FF);
}

void    rect(int tilex, int tiley, int color)
{
    
    int x;
    int y;
    
    x = tilex + TILE;
    y = tiley + TILE;
    while (tiley < y -1)
    {
        while (tilex < x)
        {
            
            g_dt.addrmlx[tiley * g_dt.rsltn_w + tilex] = color;
            tilex++;
        }
        tilex -= TILE -1;
        tiley++;
    }
}

void        draw_circle(int color)
{
    int     r;
    float   angle;
    int     i;
    int     x;
    int     y;
 
    r = 1;
    i = 0;
    x = 0;
    y = 0;
    while(r < 5)
    {
        i = 0;
        while (i < 360)
        {
            angle = i * RAD; 
            x = (int)(g_dt.pos_x + (r * cos(angle))) * MINIM;
            y = (int)(g_dt.pos_y + (r * sin(angle))) * MINIM;
            if (x >= 0 && x < g_dt.rsltn_w && y >= 0 && y < g_dt.rsltn_h)
                g_dt.addrmlx[y * g_dt.rsltn_w + x] = color;
            i++;
        }
    r++;
    }
 }
 
 void    print_line(int x1, int y1)
{
  int x0 = floor(g_dt.pos_x) * MINIM;
  int y0 = floor(g_dt.pos_y) * MINIM;
  int dx =  abs (x1 - x0), sx = x0 < x1 ? 1 : -1;
  int dy = -abs (y1 - y0), sy = y0 < y1 ? 1 : -1; 
  int err = dx + dy, e2;
  
  while (1)
  {  
    if ((int)x0 < 0 || (int)x0 > g_dt.rsltn_w * TILE || (int)y0 < 0 || (int)y0 > g_dt.rsltn_h
        || (int)x0 > g_dt.rsltn_w || (int)y0 > g_dt.rsltn_h)
        break;
        
    g_dt.addrmlx[((int)(y0) * g_dt.rsltn_w + (int)(x0))] = 0x0CFCD0;
    if (x0 == x1 && y0 == y1) break;
    e2 = 2 * err;
    if (e2 >= dy) { err += dy; x0 += sx; }
    if (e2 <= dx) { err += dx; y0 += sy; }
  }
}