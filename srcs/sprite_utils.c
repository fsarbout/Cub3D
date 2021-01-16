/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 11:37:07 by fsarbout          #+#    #+#             */
/*   Updated: 2021/01/16 10:35:26 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_coor    get_center_coor(float spx, float spy)
{   
    t_coor center;

    center.x = (int)(spx / TILE) * TILE + (TILE / 2);
    center.y = (int)(spy / TILE) * TILE + (TILE / 2);
    return (center);
}

int     check_exists(t_list *lst, float x, float y)
{
    while (lst)
    {
        if (lst->sp.center.x == x && lst->sp.center.y == y)
            return (1);
        lst = lst->next;
    }
    return (0);
}

void    check_sprite(int i, int j)
{
    if ( g_dt.mmp[i][j + 1] == 32 ||  g_dt.mmp[i][j - 1] == 32 
        ||  g_dt.mmp[i - 1][j] == 32
                    ||  g_dt.mmp[i + 1][j] == 32)
                        print_error("map invalid ,sprite next to space!\n");
    g_dt.nb_sprite++;
}