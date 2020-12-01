/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 12:37:57 by fsarbout          #+#    #+#             */
/*   Updated: 2020/12/01 13:23:12 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collect_data.h"

int exiit(int key, void *param)
{
    printf("exit working1\n");
    param = NULL;
    printf("%d\n", key);
    ///if case of error
    // mlx_clear_window(g_data.mlx, g_data.window);
    mlx_destroy_window(g_data.mlx, g_data.window);
    
    exit(0);
    printf("exit working\n");

}

int    hooking(void *param)
{
    mlx_hook(g_data.window, 2, 0, keypressed , param);
    mlx_hook(g_data.window, 3, 0,keyreleased , param);
    mlx_hook(g_data.window, 17, 0,exiit, param);
    update();
    return (1);
    
}
int     keypressed(int key, void *param)
{
        printf("%d\n", key);
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
        printf("keypressed working\n");
        return (0);
}


int keyreleased(int key, void *param)
{
    printf("%d a key is released \n", key);
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
    // printf("keyreleased working\n");
    return (0);
}

// stop command z     
// calcule j with the player angle

void    update()
{
    float movestep;
    float angle;
    
    mlx_destroy_image(g_data.mlx, g_data.imgmlx);
    mlx_clear_window(g_data.mlx, g_data.window);
    if (g_mv.walkdir == 0)
         movestep = g_mv.walkdirsd * g_mv.mvspd;
    if (g_mv.walkdirsd == 0)
        movestep = g_mv.walkdir * g_mv.mvspd;
        
    // float movestep = g_mv.walkdir * g_mv.mvspd;
    g_data.imgmlx  = mlx_new_image(g_data.mlx, g_data.long_l * TILE, g_data.nbr_lines * TILE);
	g_data.addrmlx = (int*)mlx_get_data_addr(g_data.imgmlx, &g_data.bpp, &g_data.size_l,
                                 &g_data.endian);
    draw_map();
    mlx_put_image_to_window(g_data.mlx, g_data.window, g_data.imgmlx, 0, 0);
    g_mv.rtnangl += g_mv.turndir * g_mv.rtnspd;

    ///////
    g_data.pos_x = g_data.pos_x + cos(g_mv.rtnangl) * movestep;
    g_data.pos_y = g_data.pos_y + sin(g_mv.rtnangl) * movestep;
    ///////

    // if (g_mv.walkdir == 0)
    // {   
    //      angle = g_mv.rtnangl - M_PI;
    //      g_data.pos_x = g_data.pos_x + cos(g_mv.rtnangl) * movestep;
    //      g_data.pos_y = g_data.pos_y + sin(g_mv.rtnangl) * movestep;
         
    // }
}

void    dda()
{
    float angle;
     
    if (g_data.ifdda == 1)  
        angle = g_mv.rtnangl;
    else
        angle = g_data.plyr_angl;
    g_data.ifdda = 1;  
    double  y1;
    double  x1;
    int     i;
    i = 0;
    x1 = g_data.pos_x ;
    y1 = g_data.pos_y ;
    
    while (i < 30)
    {
        g_data.addrmlx[(int)( y1) * (g_data.long_l * TILE) + (int)( x1)] = 0xFF4500;
        x1 = x1 + cos(angle);
        y1 = y1 + sin(angle);
        i++;
    }
}