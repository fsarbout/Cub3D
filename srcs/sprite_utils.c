/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 11:37:07 by fsarbout          #+#    #+#             */
/*   Updated: 2021/01/12 17:52:39 by fsarbout         ###   ########.fr       */
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

float		normalize_sp_angle(float angle)
{
    if ((g_dt.plyr_angl - (FOV / 2)) - angle > M_PI)
		angle = angle + 2 * M_PI;
	if (angle - (g_dt.plyr_angl - (FOV / 2)) > M_PI)
		angle = angle - 2 * M_PI;
    return (angle);
}

void    render_sprites(t_dt *dt ,float checkx,float checky, int i)
{
    if (!dt[i].sprt)
    {
        
    }

}