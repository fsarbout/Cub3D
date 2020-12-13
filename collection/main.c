/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 18:20:39 by fsarbout          #+#    #+#             */
/*   Updated: 2020/12/13 06:45:09 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collect_data.h"
#include <float.h>

int main(int ac, char **av)
{
    printf("number of arguments = %d\n", ac);
    char *line;
    void    *param;

    line = NULL;
    param = NULL;
    if (ac != 2)
    {
        printf("ERROR IN ARGUMENTS OF MAIN");
        return (0);
    }
    else
        collect_data(line, av);
    // g_dt.numrays =  g_dt.rsltn_w / WALL_S_W;
    g_dt.numrays = g_dt.long_l * TILE ;
    mlxs();
    perror("Error: ");
    free(g_dt.mmp);
    return (0);
}


//         t_dt *data;
// # define MALLOC(p) p = malloc(sizeof(*(p)))
//         MALLOC(data);
    
//         data = malloc(sizeof(t_d


void    render3d(t_dt *dt, t_mv *mv)
{
    int i;
    int y;
    float   perpDistance;
    float   distanceProjPlane;
    float   projectedWallHeight;
    int   wallStripHeight;
    int   wallTopPixel;
    int   wallBottomPixel;
    distanceProjPlane = ((g_dt.long_l * TILE) / 2) / tan(FOV / 2);
    i = 0;
    while (i < g_dt.numrays)
    {
        perpDistance = dt[i].distance * cos(mv[i].rayangle - g_dt.plyr_angl);
        projectedWallHeight = (TILE/ perpDistance) * distanceProjPlane;
        wallStripHeight = (int)projectedWallHeight;
        wallTopPixel = ((g_dt.nbr_lines * TILE) / 2) - (wallStripHeight / 2);
        wallTopPixel = wallTopPixel < 0 ? 0 : wallTopPixel;
        wallBottomPixel = ((g_dt.nbr_lines * TILE) / 2) + (wallStripHeight /2);
        wallBottomPixel = wallBottomPixel > (g_dt.nbr_lines * TILE) ? (g_dt.nbr_lines * TILE) : wallBottomPixel;
        y = 0;
        while (y < wallTopPixel)
        {
            if (((g_dt.size_l * (g_dt.nbr_lines * TILE)) / 4) > (y * (g_dt.long_l * TILE) + i))
                g_dt.addrmlx[y * (g_dt.long_l * TILE) + i] = 0x0002FA;
            y++;
        }
        y = wallTopPixel;
        while (y < wallBottomPixel)
        {
            if (((g_dt.size_l * (g_dt.nbr_lines * TILE)) / 4) > (y * (g_dt.long_l * TILE) + i))
                g_dt.addrmlx[y * (g_dt.long_l * TILE) + i] = 0x808080;
            y++;
        }
        y = wallBottomPixel;
        while (y < (g_dt.nbr_lines * TILE))
        {
            if (((g_dt.size_l * (g_dt.nbr_lines * TILE)) / 4) > (y * (g_dt.long_l * TILE) + i))
            g_dt.addrmlx[y * (g_dt.long_l * TILE) + i] = 	0xADD8E6;
            y++;
        }
        i++;
    }
}