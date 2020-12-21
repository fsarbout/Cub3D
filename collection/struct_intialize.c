/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_intialize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:43:12 by fsarbout          #+#    #+#             */
/*   Updated: 2020/12/21 05:29:39 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    struct_intialize()
{
    g_dt.r = 0;
    g_dt.rsltn_h = 0;
    g_dt.rsltn_w = 0;
    g_dt.f = 0;
    g_dt.flr_r = 0;
    g_dt.flr_g = 0;
    g_dt.flr_b = 0;
    g_dt.c = 0;
    g_dt.cllng_b = 0;
    g_dt.cllng_g = 0;
    g_dt.cllng_r = 0;
    g_dt.n = 0;
    g_dt.so = 0;
    g_dt.e = 0;
    g_dt.w = 0;
    g_dt.width = 84;
    g_dt.height = 84;
    g_dt.spi  = 0;
    g_dt.spj  = 0;
    g_dt.plyr = 0;
    g_dt.n_path = NULL;
    g_dt.e_path = NULL;
    g_dt.w_path = NULL;
    g_dt.so_path = NULL;
    // g_dt.img = (type) {.x = dfvdfg, .x}
    g_dt.mmp = NULL;
    g_dt.size_l = 0;
    g_dt.mlx = mlx_init();
    g_dt.nbr_lines = 0;
	g_dt.endian = 0;
	g_dt.long_l = 0;
	g_dt.bpp = 0;
    /////////////////////////////////////////////
    g_mv.turndir = 0;
    g_mv.walkdir = 0;
    g_mv.mvspd  = 6;
    g_mv.rtnspd = 2 * (M_PI / 180);
    g_dt.pos_x = 0;
    g_dt.pos_y = 0;
    g_mv.newxplyr = 0;
    g_mv.newyplyr = 0;
    g_mv.raydown = 0;
    g_mv.rayup = 0;
    g_mv.rayleft = 0;
    g_mv.rayright = 0;
    g_mv.raydist = 0;
    g_dt.horwllhitx = 0;
    g_dt.horwllhity = 0;
    g_dt.verwllhitx = 0;
    g_dt.verwllhity = 0;
    g_dt.wallhitx = 0;
    g_dt.wallhity = 0;
    g_dt.distance = 0;
    g_dt.hhitdis = 0;
    g_dt.vhitdis = 0;
    g_mv.rayangle = 0;
    g_dt.horzhit = 0;
    g_dt.verthit = 0;
    g_dt.numrays = 0;
    g_dt.checkx = 0;
    g_dt.checky = 0;
    g_txt.txt_offsetx = 0;
    g_txt.txt_offsetx = 0;
    g_dt.color = 0;
    g_dt.size_l = 0;
    g_dt.perpdist = 0;
    g_dt.distpplane = 0;
    g_dt.prjctwallheight = 0;
    g_dt.wallstripheight = 0;
    g_dt.walltop = 0;
    g_dt.wallbttm = 0;
    g_dt.dist_from_top = 0;
    g_sprite.size_l_sp = 0;
    g_txt.sp_txt = NULL;
}
