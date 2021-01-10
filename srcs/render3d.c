/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 06:26:39 by fsarbout          #+#    #+#             */
/*   Updated: 2021/01/10 18:59:46 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
 
void    render3d(t_dt *dt, t_mv *mv, t_list **list)
{
    int i;
    int y;
    int j;

    j = 7;
    i = 0;
         
    g_txt.addr_txt[0] = (int*)mlx_get_data_addr(g_txt.no_txt ,&g_dt.bpp, &g_dt.size_line , &g_dt.endian);
    g_txt.addr_txt[2] = (int*)mlx_get_data_addr(g_txt.so_txt ,&g_dt.bpp, &g_dt.size_line , &g_dt.endian);
    g_txt.addr_txt[3] = (int*)mlx_get_data_addr(g_txt.we_txt ,&g_dt.bpp, &g_dt.size_line , &g_dt.endian);
    g_txt.addr_txt[1] = (int*)mlx_get_data_addr(g_txt.ea_txt ,&g_dt.bpp, &g_dt.size_line , &g_dt.endian);
    
    g_dt.distpplane = ((g_dt.long_l * TILE) / 2) / tan(FOV / 2);
    while (i < g_dt.numrays)
    {
        calc_render3d(dt, mv, &i, &j);
        y = 0;
        while (y < g_dt.walltop)/////ceilling
        {
             if (i < 0 || i > g_dt.long_l * TILE || y < 0 || y > g_dt.nbr_lines  * TILE
                || i > g_dt.long_l * TILE|| y >  g_dt.nbr_lines * TILE)
                break;
            if (((g_dt.size_l * (g_dt.nbr_lines * TILE)) / 4) > (y * (g_dt.long_l * TILE) + i))
                g_dt.addrmlx[y * (g_dt.long_l * TILE) + i] = 0x808080;
            y++;
        }
        y = g_dt.walltop;
        while (y < g_dt.wallbttm)////wall
        {
            if (i < 0 || i > g_dt.long_l * TILE || y < 0 || y > g_dt.nbr_lines  * TILE
                || i > g_dt.long_l * TILE|| y >  g_dt.nbr_lines  * TILE)
                break;
            g_dt.dist_from_top = y + (g_dt.wallstripheight /  2) - ((g_dt.rsltn_h) / 2);
            g_txt.txt_offsety = g_dt.dist_from_top * ((float)64 / g_dt.wallstripheight);
            g_dt.color = (int)g_txt.addr_txt[j][(int)(64 * g_txt.txt_offsety + g_txt.txt_offsetx)];
            if (((g_dt.size_l * (g_dt.nbr_lines * TILE)) / 4) > (y * (g_dt.long_l * TILE) + i))
                g_dt.addrmlx[y * (g_dt.long_l * TILE) + i] = g_dt.color;
            y++;
        }
        y = g_dt.wallbttm;
        while (y < (g_dt.rsltn_h)) ///floor loop
        {
            if (i < 0 || i > g_dt.long_l* TILE || y < 0 || y > g_dt.nbr_lines  * TILE
                || i > (g_dt.long_l * TILE)|| y > (g_dt.nbr_lines * TILE) )
                
                break;
                
            if (((g_dt.size_l * (g_dt.nbr_lines * TILE)) / 4) > (y * (g_dt.long_l * TILE) + i))
                g_dt.addrmlx[y * (g_dt.long_l * TILE) + i] = 0xFFFFFF;
            y++;
        }
        i++;
    }
}

void    calc_render3d(t_dt *dt, t_mv *mv, int *i, int *j)
{
    g_txt.txt_offsetx = dt[*i].verthit ? (int)dt[*i].wallhity % 64 
       : (int)dt[*i].wallhitx % 64; //scale the size of wall
    g_dt.perpdist = dt[*i].distance * cos(mv[*i].rayangle - g_dt.plyr_angl);
    g_dt.prjctwallheight = (TILE/ g_dt.perpdist) * g_dt.distpplane;// camera plane
    g_dt.wallstripheight = (int)g_dt.prjctwallheight; //also forgoten
    g_dt.walltop = ((g_dt.rsltn_h) / 2) - (g_dt.wallstripheight / 2);
    g_dt.walltop = g_dt.walltop < 0 ? 0 : g_dt.walltop;
    g_dt.wallbttm = ((g_dt.rsltn_h) / 2) + (g_dt.wallstripheight /2);
    g_dt.wallbttm = g_dt.wallbttm > (g_dt.rsltn_h) ? (g_dt.rsltn_h) : g_dt.wallbttm;
    if (mv[*i].rayup && !dt[*i].verthit)
        *j = 1;
    if (!mv[*i].rayup && !dt[*i].verthit)
        *j = 0;
    if (mv[*i].rayright && dt[*i].verthit)
        *j = 3;
    if (!mv[*i].rayright && dt[*i].verthit)
        *j = 2;
}

void    render_sprite(t_dt *dt, t_list **list)
{
    int start;
    int x_offs;
    int y_offs;
    int y;
    int d;
    t_list *disp;

    
    disp = *list;
    start = disp->sp.width_s;
    printf(" start %d\n ", start);
    int pass = g_dt.nb_sprite;
    while (pass)
    {

        while (start < disp->sp.width_e && disp->sp.width_s < (g_dt.long_l * TILE))
        {
            x_offs = ((64 * (start - disp->sp.width_s) * TILE / disp->sp.height) / 64);
            y = disp->sp.height_s;
            if (start >= 0 && start <= (g_dt.long_l * 64)  && disp->sp.dist_plyr_sp < dt[start].distance)
            {
                // printf("distance player from wall %f\n" , disp->sp.dist_plyr_sp);
                // printf("distance player from sprite %f\n" , dt[start].distance);
                while (y < disp->sp.height_e)
                {
                    d = y + (disp->sp.height / 2) - ((g_dt.nbr_lines * TILE) / 2);
                    y_offs = d * ((TILE * 1.0) / disp->sp.height);
                        g_dt.color = (int)(g_txt.sprite_txt[(int)(64 * y_offs + x_offs)]);
                        if (g_dt.color != 0)
                            g_dt.addrmlx[y * (g_dt.long_l * TILE) + start] = g_dt.color;
                    y++;
                }
            }
            start++;
        }
    pass--;
    }
}