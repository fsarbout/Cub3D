/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 06:14:27 by fsarbout          #+#    #+#             */
/*   Updated: 2021/01/15 18:07:04 by fsarbout         ###   ########.fr       */
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

void    sprite_calc(t_list **list)
{
     t_sp sp;
     float plyr_angle;
    float rays;
    
    sp.x = g_dt.checkx;
    sp.y = g_dt.checky;
    sp.center = get_center_coor(sp.x, sp.y);
    sp.dist_plyr_sp = calc_dist(sp.center.x, sp.center.y);
    sp.angle = atan2((sp.center.y - g_dt.pos_y) , (sp.center.x - g_dt.pos_x));
    plyr_angle = g_dt.plyr_angl - (FOV / 2);
    sp.angle = sp.angle - plyr_angle;
     if (sp.angle > (180 * RAD))
        sp.angle -= (360 * RAD);
    else if (sp.angle < (-180 * RAD))
        sp.angle += (360 * RAD);
    g_dt.distpplane = (g_dt.rsltn_w / 2) / tan(FOV / 2.3);
    sp.height = (TILE / sp.dist_plyr_sp) * g_dt.distpplane ;
    sp.height_s = -sp.height / 2 + (g_dt.rsltn_h) / 2;
    sp.height_s = sp.height_s < 0 ? 0 : sp.height_s;
    sp.height_e = sp.height / 2 +(g_dt.rsltn_h) / 2;
    sp.height_e = sp.height_e  > (g_dt.rsltn_h) ? (g_dt.rsltn_h) - 1 : sp.height_e;
    rays = (FOV / g_dt.rsltn_w) ;
     sp.width_s = (sp.angle / rays) - (sp.height / 2);
    sp.width_e = sp.width_s + sp.height;
    if (!check_exists(*list, sp.center.x, sp.center.y))
        lst_add_back(list, sp);
}

void    render_one_sprite(t_dt *dt, t_list **list)
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
}