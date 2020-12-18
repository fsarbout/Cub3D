/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 06:26:39 by fsarbout          #+#    #+#             */
/*   Updated: 2020/12/18 02:04:52 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collect_data.h"
 
void    render3d(t_dt *dt, t_mv *mv)
{
    int i = 0;
    int y;
    int j;
    float   perpdist;
    float   distpplane;
    float   prjctwallheight;
    int   wallstripheight;
    int   walltop;
    int   wallbttm;
    int size_line;    
    int color;
    int dist_from_top;
    j = 0;

     
    g_txt.addr_txt[0] = (int*)mlx_get_data_addr(g_txt.no_txt ,&g_dt.bpp, &size_line , &g_dt.endian); 
    g_txt.addr_txt[2] = (int*)mlx_get_data_addr(g_txt.so_txt ,&g_dt.bpp, &size_line , &g_dt.endian);
    g_txt.addr_txt[3] = (int*)mlx_get_data_addr(g_txt.we_txt ,&g_dt.bpp, &size_line , &g_dt.endian);
    g_txt.addr_txt[1] = (int*)mlx_get_data_addr(g_txt.ea_txt ,&g_dt.bpp, &size_line , &g_dt.endian);


       
    distpplane = ((g_dt.long_l * TILE) / 2) / tan(FOV / 2);
    while (i < g_dt.numrays)
    {
        g_txt.txt_offsetx = dt[i].verthit ? (int)dt[i].wallhity % 64 
                : (int)dt[i].wallhitx % 64;
        perpdist = dt[i].distance * cos(mv[i].rayangle - g_dt.plyr_angl);
        prjctwallheight = (TILE/ perpdist) * distpplane;
        wallstripheight = (int)prjctwallheight;
        walltop = ((g_dt.nbr_lines * TILE) / 2) - (wallstripheight / 2);
        walltop = walltop < 0 ? 0 : walltop;
        wallbttm = ((g_dt.nbr_lines * TILE) / 2) + (wallstripheight /2);
        wallbttm = wallbttm > (g_dt.nbr_lines * TILE) ? (g_dt.nbr_lines * TILE) : wallbttm;
        y = 0;
        if (mv[i].rayup && !dt[i].verthit)
                j = 1;
        if (!mv[i].rayup && !dt[i].verthit)
                j = 0;
        if (mv[i].rayright && dt[i].verthit)
                j = 3;
        if (!mv[i].rayright && dt[i].verthit)
                j = 2;
        while (y < walltop)/////ceilling
        {
            if (i < 0 || i > g_dt.rsltn_w * TILE || y < 0 || y > g_dt.rsltn_h  * TILE
                || i > g_dt.long_l * TILE || y > g_dt.nbr_lines * TILE)
                break;
            if (((g_dt.size_l * (g_dt.nbr_lines * TILE)) / 4) > (y * (g_dt.long_l * TILE) + i))
                g_dt.addrmlx[y * (g_dt.long_l * TILE) + i] = 0x808080;
            y++;
        }
        y = walltop;

        while (y < wallbttm)////wall loop
        {
            if (i < 0 || i > g_dt.rsltn_w * TILE || y < 0 || y > g_dt.rsltn_h  * TILE
                || i > g_dt.long_l * TILE || y > g_dt.nbr_lines * TILE)
                break;
            dist_from_top = y + (wallstripheight /  2) - ((g_dt.nbr_lines * TILE) / 2);
            g_txt.txt_offsety = dist_from_top * ((float)64 / wallstripheight);
            
            color = (int)g_txt.addr_txt[j][(int)(64 * g_txt.txt_offsety + g_txt.txt_offsetx)];
            
            //////////////////////////////
            if (((g_dt.size_l * (g_dt.nbr_lines * TILE)) / 4) > (y * (g_dt.long_l * TILE) + i))
                g_dt.addrmlx[y * (g_dt.long_l * TILE) + i] = color;
            y++;
        }
        y = wallbttm;
        while (y < (g_dt.nbr_lines * TILE)) ///floor loop
        {
            if (i < 0 || i > g_dt.rsltn_w * TILE || y < 0 || y > g_dt.rsltn_h  * TILE
                || i > g_dt.long_l * TILE || y > g_dt.nbr_lines * TILE )
                
                break;
                
            if (((g_dt.size_l * (g_dt.nbr_lines * TILE)) / 4) > (y * (g_dt.long_l * TILE) + i))
                g_dt.addrmlx[y * (g_dt.long_l * TILE) + i] = 0xFFFFFF;
            y++;
        }
        i++;
    }
}