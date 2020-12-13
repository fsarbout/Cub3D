/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 17:55:41 by fsarbout          #+#    #+#             */
/*   Updated: 2020/12/13 03:55:38 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collect_data.h"

void   mlxs()
{
    void *param;

    param = NULL;
    g_dt.window = mlx_new_window(g_dt.mlx, g_dt.rsltn_w, g_dt.rsltn_h, "Hello!");
    g_dt.imgmlx  = mlx_new_image(g_dt.mlx, g_dt.long_l * TILE, g_dt.nbr_lines * TILE);
	g_dt.addrmlx = (int*)mlx_get_data_addr(g_dt.imgmlx, &g_dt.bpp, &g_dt.size_l,
                                 &g_dt.endian);
    printf(" lllll %d\n" , ( (g_dt.size_l * (g_dt.nbr_lines * TILE)) / 4));
    // render3d();
    draw_map();
    mlx_put_image_to_window(g_dt.mlx, g_dt.window, g_dt.imgmlx, 0, 0);
    mlx_loop_hook(g_dt.mlx ,hooking, param);
    mlx_loop(g_dt.mlx);
    printf("mlxs working\n");
}

void        draw_map()
{
	int		x;
	int		y;
    int     tilex;
    int     tiley;
    
	y = 0;
    tilex = 0 ;
    tiley = 0 ;
	while (y < g_dt.nbr_lines)
    {
        x = 0;
        while (x < g_dt.long_l)
        {
            tilex = x * TILE;
            tiley = y * TILE;
            if (g_dt.mmp[y][x] == '1')
                rect(tilex * MINIM, tiley  * MINIM, 0xFFFFFF);
            else if (g_dt.mmp[y][x] == '0' || g_dt.mmp[y][x] != ' ')
                rect(tilex * MINIM, tiley * MINIM, 0xA0A0A0);
            x++;
        }
        y++;
    }
    draw_circle();
}

void    rect(int tilex, int tiley, int color)
{
    
    int x;
    int y;
    
    x = tilex + TILE;
    y = tiley + TILE;
    while (tiley < y - 1)
    {
        while (tilex < x)
        {
             g_dt.addrmlx[tiley * (g_dt.long_l * TILE) + tilex] = color;
            tilex++;
        }
        tilex -= TILE - 1;
        tiley++;
    }
}
void        draw_circle()
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
            angle = i * ( M_PI / 180); 
            x = (int)(g_dt.pos_x + (r * cos(angle))) * MINIM;
            y = (int)(g_dt.pos_y + (r * sin(angle))) * MINIM;
            g_dt.addrmlx[y * (g_dt.long_l * TILE) + x] = 0x0000FF;
            // my_mlx_pixel_put(x , y ,0xFFFFFF);
            i++;
        }
    r++;
    }
    // printf("draw circle working\n");
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
    if ((int)x0 < 0 || (int)x0 > g_dt.rsltn_w * TILE || (int)y0 < 0 || (int)y0 > g_dt.rsltn_h  * TILE
        || (int)x0 > g_dt.long_l * TILE || (int)y0 > g_dt.nbr_lines * TILE)
        break;
        
    g_dt.addrmlx[((int)(y0) * (g_dt.long_l * TILE) + (int)(x0))] = 0x0CFCD0;
    if (x0 == x1 && y0 == y1) break;
    e2 = 2 * err;
    if (e2 >= dy) { err += dy; x0 += sx; }
    if (e2 <= dx) { err += dx; y0 += sy; }
  }
}