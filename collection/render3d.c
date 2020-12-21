/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 06:26:39 by fsarbout          #+#    #+#             */
/*   Updated: 2020/12/21 05:39:45 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
 
void    render3d(t_dt *dt, t_mv *mv)
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
    g_txt.addr_txt[4] = (int*)mlx_get_data_addr(g_txt.sp_txt, &g_dt.bpp, &g_dt.size_line, &g_dt.endian);
    
    g_dt.distpplane = ((g_dt.long_l * TILE) / 2) / tan(FOV / 2);
    while (i < g_dt.numrays)
    {
        calc_render3d(dt, mv, &i, &j);
        y = 0;
        while (y < g_dt.walltop)/////ceilling
        {
             if (i < 0 || i > g_dt.long_l * TILE || y < 0 || y > g_dt.nbr_lines  * TILE
                || i > g_dt.long_l * TILE|| y >  g_dt.nbr_lines  * TILE)
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

            ///////////////////////////
            g_dt.color = (int)g_txt.addr_txt[j][(int)(64 * g_txt.txt_offsety + g_txt.txt_offsetx)];
            ///////////////////////////

            if (((g_dt.size_l * (g_dt.nbr_lines * TILE)) / 4) > (y * (g_dt.long_l * TILE) + i))
            ///////////////////////////
                g_dt.addrmlx[y * (g_dt.long_l * TILE) + i] = g_dt.color;
            ///////////////////////////
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
        : (int)dt[*i].wallhitx % 64;
    g_dt.perpdist = dt[*i].distance * cos(mv[*i].rayangle - g_dt.plyr_angl);
    g_dt.prjctwallheight = (TILE/ g_dt.perpdist) * g_dt.distpplane;
    g_dt.wallstripheight = (int)g_dt.prjctwallheight;
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
    if (dt[*i].sp)
        *j = 4; 
}