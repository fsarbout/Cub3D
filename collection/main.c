/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 18:20:39 by fsarbout          #+#    #+#             */
/*   Updated: 2020/12/14 02:53:22 by fsarbout         ###   ########.fr       */
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
        while (y < wallTopPixel)/////ceilling
        {
            if (((g_dt.size_l * (g_dt.nbr_lines * TILE)) / 4) > (y * (g_dt.long_l * TILE) + i))
                g_dt.addrmlx[y * (g_dt.long_l * TILE) + i] = 0x0000FF;
                // g_dt.addrmlx[y * (g_dt.long_l * TILE) + i] = 0x0002FA;
            y++;
        }
        y = wallTopPixel;
        while (y < wallBottomPixel)////wall loop
        {
            if (((g_dt.size_l * (g_dt.nbr_lines * TILE)) / 4) > (y * (g_dt.long_l * TILE) + i))
             g_dt.addrmlx[y * (g_dt.long_l * TILE) + i] = dt[i].verthit ? 0x808080 : 0x896420;
                // g_dt.addrmlx[y * (g_dt.long_l * TILE) + i] = 0x808080;
            y++;
        }
        y = wallBottomPixel;
        while (y < (g_dt.nbr_lines * TILE)) ///floor loop
        {
            if (((g_dt.size_l * (g_dt.nbr_lines * TILE)) / 4) > (y * (g_dt.long_l * TILE) + i))
            g_dt.addrmlx[y * (g_dt.long_l * TILE) + i] = 0xFFFFFF;
            y++;
        }
        i++;
    }
}

void    rayCast(float rayangle, int stripId,t_dt *dt, t_mv *mv)
{
    float xstep;
    float ystep;
    float xintercept;
    float yintercept;
    int raydown;
    int rayright;
    int rayup;
    int rayleft;
    float nextHorzTouchX;
    float nextHorzTouchY;
    int horzhit;
    int horzWallContent;
    float horwllhitx;
    float horwllhity;
    float nextVertTouchX;
    float nextVertTouchY;
    int verthit;
    int vertWallContent;
    float verwllhitx;
    float verwllhity;
    horzhit = 0;
    horwllhitx = 0;
    horwllhity = 0;
    horzWallContent = 0;
    rayangle = normalize_angle(rayangle);
    rayup = rayangle > 0 && rayangle < M_PI;
    raydown = !rayup;
    rayleft = rayangle < (0.5 * M_PI) || rayangle > ( 1.5 * M_PI);
    rayright = !rayleft;
    yintercept = floor(g_dt.pos_y / TILE) * TILE;
    yintercept += raydown ? TILE : 0;
    xintercept = g_dt.pos_x + (yintercept - g_dt.pos_y) / tan(rayangle);
    ystep = TILE;
    ystep *= !raydown ? -1 : 1;
    xstep = TILE / tan(rayangle);
    xstep *= (!rayright && xstep > 0) ? -1 : 1;
    xstep *= (rayright && xstep < 0) ? -1 : 1;
    nextHorzTouchX = xintercept;
    nextHorzTouchY = yintercept;
    while (nextHorzTouchX >= 0 && nextHorzTouchX <= (g_dt.long_l * TILE) && nextHorzTouchY >= 0 && nextHorzTouchY <= (g_dt.nbr_lines * TILE))
    {
        float xToCheck = nextHorzTouchX;
        float yToCheck = nextHorzTouchY + (!raydown ? -1 : 0);
        if(hit_wall(xToCheck, yToCheck))
        {
            horzhit = 1;
            horwllhitx = nextHorzTouchX;
            horwllhity = nextHorzTouchY;
            horzWallContent = g_dt.mmp[(int)floor(yToCheck / TILE)][(int)floor(xToCheck / TILE)];
            break ;
        }
        else
        {
            nextHorzTouchX += xstep;
            nextHorzTouchY += ystep;
        }
    }
    verthit = 0;
    verwllhitx = 0;
    verwllhity = 0;
    vertWallContent = 0;
    xintercept = floor(g_dt.pos_x / TILE) * TILE;
    xintercept += rayright ? TILE : 0;
    yintercept = g_dt.pos_y + (xintercept - g_dt.pos_x) * tan(rayangle);
    xstep = TILE;
    xstep *= !rayright ? -1 : 1;
    ystep = TILE * tan(rayangle);
    ystep *= (!raydown && ystep > 0) ? -1 : 1;
    ystep *= (raydown && ystep < 0) ? -1 : 1;
    nextVertTouchX = xintercept;
    nextVertTouchY = yintercept;
    while (nextVertTouchX >= 0 && nextVertTouchX <= (g_dt.long_l * TILE) && nextVertTouchY >= 0 && nextVertTouchY <= (g_dt.nbr_lines * TILE))
    {
        float xToCheck = nextVertTouchX + (!rayright ? -1 : 0);
        float yToCheck = nextVertTouchY;
        if(hit_wall(xToCheck, yToCheck))
        {
            verthit = 1;
            verwllhitx = nextVertTouchX;
            verwllhity = nextVertTouchY;
            vertWallContent = g_dt.mmp[(int)floor(yToCheck / TILE)][(int)floor(xToCheck / TILE)];
            break ;
        }
        else
        {
            nextVertTouchX += xstep;
            nextVertTouchY += ystep;
        }
    }
    float horzHitDistance = horzhit
        ? distanceBetweenPoints(g_dt.pos_x, g_dt.pos_y, horwllhitx, horwllhity)
        : FLT_MAX;
    float vertHitDistance = verthit
        ? distanceBetweenPoints(g_dt.pos_x, g_dt.pos_y, verwllhitx, verwllhity)
        : FLT_MAX;
    if (vertHitDistance < horzHitDistance)
    {
        dt[stripId].distance = vertHitDistance;
        dt[stripId].wallhitx = verwllhitx;
        dt[stripId].wallhity = verwllhity;
        dt[stripId].wllhitcnt = vertWallContent;
        dt[stripId].verthit = 1;
    }
    else
    {
        dt[stripId].distance = horzHitDistance;
        dt[stripId].wallhitx = horwllhitx;
        dt[stripId].wallhity = horwllhity;
        dt[stripId].wllhitcnt = horzWallContent;
        dt[stripId].verthit = 0;
    }
        mv[stripId].rayangle = rayangle;
        mv[stripId].raydown = raydown;
        mv[stripId].rayup = rayup;
        mv[stripId].rayleft = rayleft;
        mv[stripId].rayright = rayright;
}

float distanceBetweenPoints(float x1, float y1, float x2, float y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}