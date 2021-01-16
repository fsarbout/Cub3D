/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 11:41:17 by fsarbout          #+#    #+#             */
/*   Updated: 2021/01/16 12:18:56 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    struct_intialize()
{
    g_dt = (t_dt){0};
    g_mv = (t_mv){0};
    g_txt = (t_txt){0};
    g_dt.mlx = mlx_init();
    g_mv.mvspd  = 15;
    g_mv.rtnspd = 10 * RAD;
}

int     lenght(char **str)
{
    int n;

    n = 0;
    while (str[n])
        n++;
    return(n);
}

int    str_of_num(char *str)
{   
    int i;

    i = 0;
    while (str[i])
    {
        if (!(ft_isdigit(str[i])))
            return (0);
        i++;
    }
    return (1);
}



float    calc_dist(float x2, float y2)
{
    int x1;
    int y1;

    x1 = g_dt.pos_x;
    y1 = g_dt.pos_y;
    return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void    fix_cast_angle()
{
    g_mv.rayangle = remainder(g_mv.rayangle , (2 * M_PI));
    if (g_mv.rayangle < 0)
        g_mv.rayangle = (2 * M_PI) + g_mv.rayangle;
    g_mv.raydown = g_mv.rayangle > 0 && g_mv.rayangle < M_PI;
    g_mv.rayup = !g_mv.raydown;
    g_mv.rayright = g_mv.rayangle < 0.5 * M_PI || g_mv.rayangle > 1.5 * M_PI;
    g_mv.rayleft = !g_mv.rayright;
}