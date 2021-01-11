/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_intialize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:43:12 by fsarbout          #+#    #+#             */
/*   Updated: 2021/01/11 19:36:22 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    struct_intialize()
{
    g_dt = (t_dt){0};
    g_txt = (t_txt){0};
    g_dt.mlx = mlx_init();
    g_dt.mvspd  = 8;
    g_dt.rtnspd = 8 * RAD;
}