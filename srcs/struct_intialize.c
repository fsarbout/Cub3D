/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_intialize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:43:12 by fsarbout          #+#    #+#             */
/*   Updated: 2021/01/10 10:09:11 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    struct_intialize()
{
    g_dt = (t_dt){0};
    g_mv = (t_mv){0};
    g_txt = (t_txt){0};
    g_dt.mlx = mlx_init();
    g_mv.mvspd  = 6;
    g_mv.rtnspd = 2 * RAD;
}