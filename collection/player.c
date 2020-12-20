/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 12:37:57 by fsarbout          #+#    #+#             */
/*   Updated: 2020/12/20 01:46:50 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int exiit(int key, void *param)
{
    param = NULL;
    key = 53;
    mlx_destroy_window(g_dt.mlx, g_dt.window);
    exit(EXIT_SUCCESS);
}

int    hooking(void *param)
{
    mlx_hook(g_dt.window, 2, 0, keypressed, param);
    mlx_hook(g_dt.window, 3, 0, keyreleased, param);
    mlx_hook(g_dt.window, 17, 0, exiit, param);
    update();
    return (1);
    
}

int    keypressed(int key, void *param)
{
    if (key == DOWN)
        g_mv.walkdir = -1;
    if (key == UP)
        g_mv.walkdir = 1;
    if (key == LEFT)  
        g_mv.walkdirsd = -1;
    if (key == RIGHT)
        g_mv.walkdirsd = 1;
    if (key == T_RIGHT)
        g_mv.turndir = 1;
    if (key == T_LEFT)
        g_mv.turndir = -1;
    if (key == ESC)
         exiit(key,&param);
    update();
    return (0);
}

int keyreleased(int key, void *param)
{
    if (key == DOWN)
        g_mv.walkdir = 0;
    if (key == UP)
        g_mv.walkdir = 0;
    if (key == LEFT)
        g_mv.walkdirsd = 0;
    if (key == RIGHT)
        g_mv.walkdirsd = 0;
    if (key == T_RIGHT)
        g_mv.turndir = 0;
    if (key == T_LEFT)
            g_mv.turndir = 0;
    if (key == ESC)
            exiit(key,&param);
    update();
    return (0);
}

void    update()
{
    t_dt dt[g_dt.numrays];
    t_mv mv[g_dt.numrays];

    mlx_destroy_image(g_dt.mlx, g_dt.imgmlx);
    // mlx_clear_window(g_dt.mlx, g_dt.window);
    g_dt.imgmlx  = mlx_new_image(g_dt.mlx, g_dt.long_l * TILE, g_dt.nbr_lines * TILE);
	g_dt.addrmlx = (int*)mlx_get_data_addr(g_dt.imgmlx, &g_dt.bpp, &g_dt.size_l,
                                 &g_dt.endian);
                            
    move_playeer();
    cast_rays(dt,mv);
    render3d(dt,mv);
     draw_map();
     cast_rays(dt,mv);
    mlx_put_image_to_window(g_dt.mlx, g_dt.window, g_dt.imgmlx, 0, 0); 
}

void    move_playeer()
{
    float movestep;
    float movesteps;

    movestep = g_mv.walkdir * g_mv.mvspd;
    movesteps = g_mv.walkdirsd * g_mv.mvspd;
    
    g_dt.plyr_angl += g_mv.turndir * g_mv.rtnspd;
    g_mv.newxplyr = g_dt.pos_x + cos(g_dt.plyr_angl) * movestep;
    g_mv.newyplyr = g_dt.pos_y + sin(g_dt.plyr_angl) * movestep;
    if (movesteps != 0)
    {
        g_mv.newxplyr = g_dt.pos_x + (cos(g_dt.plyr_angl  + (90 * (M_PI / 180))) * movesteps);
        g_mv.newyplyr = g_dt.pos_y + (sin(g_dt.plyr_angl  + (90 * (M_PI / 180))) * movesteps);
    }
    if (!hit_wall(g_mv.newxplyr, g_mv.newyplyr))
    {
        g_dt.pos_x = g_mv.newxplyr; 
        g_dt.pos_y = g_mv.newyplyr;
    }
}

int     hit_wall(float x, float y)
{
    int mapx;
    int mapy;
    if (x < 0 || x >= (g_dt.long_l * TILE)|| y < 0 || (y >= g_dt.nbr_lines * TILE))
        return (1);
    mapx = floor(x / TILE);
    mapy = floor(y / TILE);
    if (g_dt.mmp[mapy][mapx] == '1' || g_dt.mmp[mapy][mapx] == '2')
        return (1);
    else 
        return (0);
}