/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 06:26:39 by fsarbout          #+#    #+#             */
/*   Updated: 2020/12/13 06:03:35 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collect_data.h"

void    render3d(t_dt *dt, t_mv *mv)
{
    int i;
    int wallheight;
    float distpplane;
    float projwllhght;
    int walltop;
    int wallbttm;
    float perpdist;
    int j;
    // t_dt dt[g_dt.numrays];
    // t_mv mv[g_dt.numrays];
    
    distpplane = 0;
    wallheight = 0;
    projwllhght = 0;
    walltop = 0;
    wallbttm = 0;
    perpdist = 0;
    i = 0;
    j = 0;
    // g_dt.numrays =  g_dt.rsltn_w / WALL_S_W;
    
    while (i < g_dt.numrays)
    {
        perpdist = dt[i].distance * cos(mv[i].rayangle - g_dt.plyr_angl);
        distpplane = ((g_dt.long_l * TILE) / 2) / tan(FOV / 2);
        projwllhght =  (TILE / perpdist) * distpplane;
        wallheight = (int)projwllhght;
        walltop = ((g_dt.nbr_lines * TILE) / 2) - (wallheight / 2 );
        walltop = walltop < 0 ? 0 : walltop;
        
        wallbttm = ((g_dt.nbr_lines * TILE) / 2) + (wallheight / 2 );
        wallbttm = wallbttm > (g_dt.nbr_lines * TILE) ? (g_dt.nbr_lines * TILE) : wallbttm;

        j = walltop;
        while (j < wallbttm)
        {
            // printf("%d\n" ,(j * (g_dt.long_l * TILE) + i));
            if (((g_dt.size_l * (g_dt.nbr_lines * TILE)) / 4) > (j * (g_dt.long_l * TILE) + i))
                g_dt.addrmlx[j * (g_dt.long_l * TILE) + i] = dt[i].verthit ? 0x0002FA : 0x0002FA;
                // g_dt.addrmlx[j * (g_dt.long_l * TILE) + i] = 0x0002FA;
            j++;
        }
        i++;
        // printf("%d\n" , i);
        // printf(" big render 3d loop is running\n");
    }
    // printf("render 3d kinda works\n");
}

