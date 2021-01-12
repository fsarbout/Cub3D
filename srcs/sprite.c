/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 06:14:27 by fsarbout          #+#    #+#             */
/*   Updated: 2021/01/12 12:49:13 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


void    treat_sprite(char **element_data)
{
    if (!(g_txt.sp_txt = (int*)mlx_xpm_file_to_image(g_dt.mlx, element_data[1]
        ,&g_dt.width, &g_dt.height)))
        print_error("   path of sprite texture invlid!\n");
    g_txt.sprite_txt = (int*)mlx_get_data_addr(g_txt.sp_txt, &g_dt.bpp, &g_dt.size_line, &g_dt.endian);
}

void    sprite_calc(/* t_list **list,  */t_dt *dt, int i)
{
    t_sp sp;
    // float plyr_angle;
    float rays;
    
    sp.x = g_dt.checkx;
    sp.y = g_dt.checky;
    sp.center = get_center_coor(sp.x, sp.y);
    sp.dist_plyr_sp = calculate_dist(sp.x, sp.y);
    sp.dist_plyr_sp_c = calculate_dist(sp.center.x, sp.center.y);
    /*   all points of player circle which hit sprite */
    sp.points_center_x = g_dt.pos_x + (cos(dt[i].rayangle) * sp.dist_plyr_sp_c);
    sp.points_center_y = g_dt.pos_y + (sin(dt[i].rayangle) * sp.dist_plyr_sp_c);
    
    sp.angle = atan2((sp.center.y - g_dt.pos_y) , (sp.center.x - g_dt.pos_x));
    // lst_add_back(list, sp);
    g_sprite[i] = sp; 
}

void    render_one_sprite(t_dt *dt, int i)
{
    int offs_x;
    int offs_y;
    int j;   //b
    int y;      
    float projectheight;
    float strip_height;
    float top;
    float bottom;
    int dist_from_top;
    int color;

    i = 0;
    if (dt[i].spr)
    {
        g_dt.distpplane = (g_dt.rsltn_w / 2) / tan(FOV / 2);
        g_dt.perpdist = dt[i].distance * cos(dt[i].rayangle - g_dt.plyr_angl);
        projectheight = (TILE/ g_dt.perpdist) * g_dt.distpplane;
        strip_height = (int)projectheight;
        top = (g_dt.rsltn_h / 2) - (strip_height / 2);
        top = top < 0 ?  0 : top;
        
        bottom = (g_dt.rsltn_h / 2) + (strip_height / 2);
        bottom = bottom > g_dt.rsltn_h ?  g_dt.rsltn_h : bottom;
        offs_x = calc_sp(g_sprite[i], i, dt);
        y = top;
        if (offs_x >= 0 && offs_x < TILE)
        {
            while (y < top)
            {
                dist_from_top = y + (strip_height / 2) - (g_dt.rsltn_h / 2);
                offs_y = dist_from_top * ((float)64 / strip_height);
                color = (int)(g_txt.sprite_txt[(int)(64 * offs_y + offs_x)]);
                if (color)
                    g_dt.addrmlx[(g_dt.rsltn_w * y) + i] = color;
                y++;                
            }
        }
    }
}

int     calc_sp(t_sp sp, int i, t_dt *dt)
{
    int dist;
    int offs_x;
    //first
    if (g_dt.pos_y >= sp.center.y - 32 && g_dt.pos_y <= sp.center.y + 32 && dt[i].rayleft)
    {
        if (sp.points_center_y > sp.center.y)
        {
            dist = distance_2pts(sp.points_center_x, sp.points_center_y, sp.center.x ,sp.center.y);
            offs_x = 32 - dist;
        }
        else
        {
            dist = distance_2pts(sp.points_center_x, sp.points_center_y, sp.center.x ,sp.center.y);
            offs_x = 32 + dist;
        }    
    }
    //2
    else if(g_dt.pos_y >= sp.center.x - 32 && g_dt.pos_y <= sp.center.y + 32)
    {
        if (sp.points_center_y < sp.center.y)
        {
             dist = distance_2pts(sp.points_center_x, sp.points_center_y, sp.center.x ,sp.center.y);
              offs_x = 32 - dist;
        }
        else
        {
             dist = distance_2pts(sp.points_center_x, sp.points_center_y, sp.center.x ,sp.center.y);
              offs_x = 32 + dist;
        } 
            
    }
    //3
     else if(dt[i].rayup)
    {
        if (sp.points_center_x > sp.center.x)
        {
             dist = distance_2pts(sp.points_center_x, sp.points_center_y, sp.center.x ,sp.center.y);
              offs_x = 32 + dist;
        }
        else
        {
             dist = distance_2pts(sp.points_center_x, sp.points_center_y, sp.center.x ,sp.center.y);
             offs_x = 32 - dist;
        }
            
    }
    //4
     else if(dt[i].raydown)
    {
        if (sp.points_center_x > sp.center.x)
        {
             dist = distance_2pts(sp.points_center_x, sp.points_center_y, sp.center.x ,sp.center.y);
             dist = 32 - dist;
        }
        else
        {
             dist = distance_2pts(sp.points_center_x, sp.points_center_y, sp.center.x ,sp.center.y);
             offs_x = 32 + dist;
        } 
            
    }
    return offs_x;
}

float distance_2pts(int x1, int y1, int x2 , int y2)
{
    return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}











 
/* void    render_one_sprite(t_dt *dt, t_list **list)
{
    int start;
    int x_offs;
    int y_offs;
    int y;
    int d;
    t_list *disp;

    disp = *list;
    start = disp->sp.width_s;
    while (start < disp->sp.width_e && disp->sp.width_s < g_dt.rsltn_w)
    {
        x_offs = ((64 * (start - disp->sp.width_s) * TILE / disp->sp.height) / 64);
        y = disp->sp.height_s;
        if (start >= 0 && start <= g_dt.rsltn_w)
        {
            if (disp->sp.dist_plyr_sp < dt[start].distance)
            {
                while (y < disp->sp.height_e)
                {
                    d = y + (disp->sp.height / 2) - (g_dt.rsltn_h / 2);
                    y_offs = d * ((TILE * 1.0) / disp->sp.height);
                        g_dt.color = (int)(g_txt.sprite_txt[(int)(64 * y_offs + x_offs)]);
                        if (g_dt.color != 0)
                            g_dt.addrmlx[y * g_dt.rsltn_w + start] = g_dt.color;
                    y++;
                }
            }
        }
        start++;
    }
} */