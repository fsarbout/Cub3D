/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 17:55:41 by fsarbout          #+#    #+#             */
/*   Updated: 2020/11/30 19:42:27 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collect_data.h"

void   mlxs()
{
    void *param;

    param = NULL;
    g_data.window = mlx_new_window(g_data.mlx, g_data.rsltn_w, g_data.rsltn_h, "Hello!");
    g_data.imgmlx  = mlx_new_image(g_data.mlx, g_data.long_l * TILE, g_data.nbr_lines * TILE);
	g_data.addrmlx = (int*)mlx_get_data_addr(g_data.imgmlx, &g_data.bpp, &g_data.size_l,
                                 &g_data.endian);
    draw_map();
    mlx_put_image_to_window(g_data.mlx, g_data.window, g_data.imgmlx, 0, 0);
    mlx_loop_hook(g_data.mlx , hooking, param);
    mlx_loop(g_data.mlx);
    printf("mlxs working\n");
}

void    draw_map()
{
	int		x;
	int		y;
    int tilex;
    int tiley;
    
	y = 0;
    tilex = 0 ;
    tiley = 0 ;
	while (y < g_data.nbr_lines)
    {
        x = 0;
        while (x < g_data.long_l)
        {
            tilex = x * TILE;
            tiley = y * TILE;
            if (g_data.mmp[y][x] == '1')
                rect(tilex, tiley , 0xFFFFFF);
            else if (g_data.mmp[y][x] == '0' || g_data.mmp[y][x] != ' ')
                rect(tilex, tiley, 0x990000);
            x++;
        }
        y++;
    }
    draw_circle();
    dda();
    // update();
    printf("draw map working\n");
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
             g_data.addrmlx[tiley * (g_data.long_l * TILE) + tilex] = color;
            // my_mlx_pixel_put(tilex, tiley, color);
            tilex++;
        }
        tilex -= TILE - 1;
        tiley++;
    }
}
void    draw_circle()
{
    int r;
    float angle;
    int i;
    int x;
    int y;

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
            x = (int)(g_data.pos_x + (r * cos(angle)));
            y = (int)(g_data.pos_y + (r * sin(angle)));
            g_data.addrmlx[y * (g_data.long_l * TILE) + x] = 0xddFFCC;
            // my_mlx_pixel_put(x , y ,0xFFFFFF);
            i++;
        }
    r++;
    }
    printf("draw circle working\n");
 }