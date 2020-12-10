/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_intialize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:43:12 by fsarbout          #+#    #+#             */
/*   Updated: 2020/12/10 05:40:15 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collect_data.h"

void    struct_intialize()
{
    g_data.r = 0;
    g_data.rsltn_h = 0;
    g_data.rsltn_w = 0;
    g_data.f = 0;
    g_data.flr_r = 0;
    g_data.flr_g = 0;
    g_data.flr_b = 0;
    g_data.c = 0;
    g_data.cllng_b = 0;
    g_data.cllng_g = 0;
    g_data.cllng_r = 0;
    g_data.n = 0;
    g_data.so = 0;
    g_data.e = 0;
    g_data.w = 0;
    g_data.width = 84;
    g_data.height = 84;
    g_data.spi  = 0;
    g_data.spj  = 0;
    g_data.plyr = 0;
    g_data.n_path = NULL;
    g_data.e_path = NULL;
    g_data.w_path = NULL;
    g_data.so_path = NULL;
	g_data.img_no = NULL;
	g_data.img_ea = NULL;
	g_data.img_we = NULL;
    g_data.img_so = NULL;
    g_data.mmp = NULL;
    g_data.size_l = 0;
    g_data.mlx = mlx_init();
    g_data.nbr_lines = 0;
	g_data.endian = 0;
	g_data.long_l = 0;
	g_data.bpp = 0;
    /////////////////////////////////////////////
    g_mv.turndir = 0;
    g_mv.walkdir = 0;
    g_mv.mvspd  = 2;
    g_mv.rtnspd = 2 * (M_PI / 180 );
    g_data.pos_x = 0;
    g_data.pos_y = 0;
    g_data.pos_xsd = 0;
    g_data.pos_ysd = 0;
    g_mv.newxplyr = 0;
    g_mv.newyplyr = 0;
    g_mv.raydown = 0;
    g_mv.rayup = 0;
    g_mv.rayleft = 0;
    g_mv.rayright = 0;
    g_mv.raydist = 0;
    g_data.horwllhitx = 0;
    g_data.horwllhity = 0;
    g_data.verwllhitx = 0;
    g_data.verwllhity = 0;
    g_data.wallhitx = 0;
    g_data.wallhity = 0;
    g_data.distance = 0;
}
