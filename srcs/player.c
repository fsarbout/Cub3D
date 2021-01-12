/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 12:37:57 by fsarbout          #+#    #+#             */
/*   Updated: 2021/01/12 11:30:29 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int exiit(int key, void *param)
{
    param = NULL;
    mlx_destroy_window(g_dt.mlx, g_dt.window);
    exit(EXIT_SUCCESS);
    return (1);
}

int    hooking(void *param)
{
    mlx_hook(g_dt.window, 2, 1L<<0,  keypressed, param);
    mlx_hook(g_dt.window, 3, 1L<<1, keyreleased, param);
    mlx_hook(g_dt.window, 17, 0L , exiit, param);
    
    // g_dt.key = 3;
    update();
    return (1); 
}

int    keypressed(int key, void *param)
{
    // printf("%d\n" , key);
    if (key == DOWN)
        g_dt.walkdir = -1;
    if (key == UP)
        g_dt.walkdir = 1;
    if (key == LEFT)  
        g_dt.walkdirsd = -1;
    if (key == RIGHT)
        g_dt.walkdirsd = 1;
    if (key == T_RIGHT)
        g_dt.turndir = 1;
    if (key == T_LEFT)
        g_dt.turndir = -1;
    if (key == ESC)
         exiit(key,&param);
    update();
    return (0);
}

int keyreleased(int key, void *param)
{
    if (key == DOWN)
    if (key == DOWN)
        g_dt.walkdir = 0;
    if (key == UP)
        g_dt.walkdir = 0;
    if (key == LEFT)
        g_dt.walkdirsd = 0;
    if (key == RIGHT)
        g_dt.walkdirsd = 0;
    if (key == T_RIGHT)
        g_dt.turndir = 0;
    if (key == T_LEFT)
            g_dt.turndir = 0;
    if (key == ESC)
            exiit(key,&param);
    update();
    return (0);
}



void    update()
{
    t_dt dt[g_dt.numrays];
    t_list *list;

    list = NULL;
    g_sprite = malloc(sizeof(t_sp) * g_dt.numrays);
    mlx_destroy_image(g_dt.mlx, g_dt.imgmlx);
    // mlx_clear_window(g_dt.mlx, g_dt.window);
    
    g_dt.imgmlx  = mlx_new_image(g_dt.mlx, g_dt.rsltn_w , g_dt.rsltn_h);
	g_dt.addrmlx = (int*)mlx_get_data_addr(g_dt.imgmlx, &g_dt.bpp, &g_dt.size_l,
                                 &g_dt.endian);       
    move_playeer();
    cast_rays(dt);
    render3d(dt);
    draw_map();
    cast_rays(dt);
    if (list)
    {
        sort_list(list);
        draw_sprite( dt);
    }
    clear_list(&list);
    mlx_put_image_to_window(g_dt.mlx, g_dt.window, g_dt.imgmlx, 0, 0); 
    free(g_sprite);
}

void    move_playeer()
{
    float movestep;
    float movesteps;

    movestep = g_dt.walkdir * g_dt.mvspd;
    movesteps = g_dt.walkdirsd * g_dt.mvspd;
    
    g_dt.plyr_angl += g_dt.turndir * g_dt.rtnspd;
    g_dt.newxplyr = g_dt.pos_x + cos(g_dt.plyr_angl) * movestep;
    g_dt.newyplyr = g_dt.pos_y + sin(g_dt.plyr_angl) * movestep;
    if (movesteps != 0)
    {
        g_dt.newxplyr = g_dt.pos_x + (cos(g_dt.plyr_angl  + (90 * RAD)) * movesteps);
        g_dt.newyplyr = g_dt.pos_y + (sin(g_dt.plyr_angl  + (90 * RAD)) * movesteps);
    }
    if (hit_wall(g_dt.newxplyr, g_dt.newyplyr) != '1' && hit_wall(g_dt.newxplyr, g_dt.newyplyr) != '2' )
    {
        g_dt.pos_x = g_dt.newxplyr; 
        g_dt.pos_y = g_dt.newyplyr;
    }
}

int     hit_wall(float x, float y)
{
    int mapx;
    int mapy;
    if (x < 0 || x >= g_dt.rsltn_w || y < 0 || (y >= g_dt.rsltn_h))
        return (1);
    if (x < 0 || x >= (g_dt.long_l * TILE) || y < 0 
        || (y >= (g_dt.nbr_lines * TILE)))
        return (1);
    mapx = floor(x / TILE);
    mapy = floor(y / TILE);
   
    return (g_dt.mmp[mapy][mapx]);
}