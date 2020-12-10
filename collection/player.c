/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 12:37:57 by fsarbout          #+#    #+#             */
/*   Updated: 2020/12/10 01:37:59 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collect_data.h"

int exiit(int key, void *param)
{
    printf("exit working1\n");
    param = NULL;
    printf("%d\n", key);
    mlx_destroy_window(g_data.mlx, g_data.window);
    exit(0);
}

int    hooking(void *param)
{
    mlx_hook(g_data.window, 2, 0, keypressed, param);
    mlx_hook(g_data.window, 3, 0, keyreleased, param);
    mlx_hook(g_data.window, 17, 0, exiit, param);
    update();
    return (1);
    
}

int     keypressed(int key, void *param)
{
        printf("%d\n", key);
        g_data.side = 0;
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
 
void    dda()
{ 
    double  y1;
    double  x1;
    int     i;
    
    i = 0;
    x1 = g_data.pos_x;
    y1 = g_data.pos_y; 

    while (i < TILE)
    {
        g_data.addrmlx[(int)( y1) * (g_data.long_l * TILE) + (int)( x1)] = 0x00FF00;
        x1 = x1 + cos(g_data.plyr_angl);
        y1 = y1 + sin(g_data.plyr_angl);
        i++;
    }
    printf("draw single line working\n");

}

void    update()
{
    mlx_destroy_image(g_data.mlx, g_data.imgmlx);
    mlx_clear_window(g_data.mlx, g_data.window);
    g_data.imgmlx  = mlx_new_image(g_data.mlx, g_data.long_l * TILE, g_data.nbr_lines * TILE);
	g_data.addrmlx = (int*)mlx_get_data_addr(g_data.imgmlx, &g_data.bpp, &g_data.size_l,
                                 &g_data.endian);
    move_playeer();
    // cast_rays();       
    draw_map();
    cast_rays();
    mlx_put_image_to_window(g_data.mlx, g_data.window, g_data.imgmlx, 0, 0); 
}

void    move_playeer()
{
    float movestep;
    float movesteps;

    movestep = g_mv.walkdir * g_mv.mvspd;
    movesteps = g_mv.walkdirsd * g_mv.mvspd;
    
    g_data.plyr_angl += g_mv.turndir * g_mv.rtnspd;
    g_mv.newxplyr = g_data.pos_x + cos(g_data.plyr_angl) * movestep;
    g_mv.newyplyr = g_data.pos_y + sin(g_data.plyr_angl) * movestep;
    if (movesteps != 0)
    {
        g_mv.newxplyr = g_data.pos_x + (cos(g_data.plyr_angl  + (90 * (M_PI / 180))) * movesteps);
        g_mv.newyplyr = g_data.pos_y + (sin(g_data.plyr_angl  + (90 * (M_PI / 180))) * movesteps);
    }
    if (!hit_wall(g_mv.newxplyr, g_mv.newyplyr))
    {
        g_data.pos_x = g_mv.newxplyr; 
        g_data.pos_y = g_mv.newyplyr;
    }
    // cast_rays();
}


// void    castallrays()
// {
//     float rayangle;
//     int stripid;

//     stripid = 0;
//     rayangle = g_data.plyr - ( FOV / 2);
//     while (stripid < NUM_RAYS)
//     {
//         ray_castintg(rayangle);
//         rayangle += FOV / NUM_RAYS;
//         stripid++; 
//     }

// }




int     hit_wall(float x, float y)
{
    int mapx;
    int mapy;
    // if (((int)x < 0) || (int)x > g_data.rsltn_w  || (int)y < 0 || (int)y > g_data.rsltn_h)
    //     return (1);
    // if (x < 0 || x > g_data.rsltn_w || y < 0 || y > g_data.rsltn_h 
    //     || x >= (g_data.long_l * TILE)|| y >= (g_data.nbr_lines * TILE) )
    //     return (1);
    
    if (x < 0 || x >= (g_data.long_l * TILE)|| y < 0 || (y >= g_data.nbr_lines * TILE))
        return (1);
    
    mapx = floor(x / TILE);
    mapy = floor(y / TILE);
    return g_data.mmp[mapy][mapx] == '1' ? 1 : 0;
}