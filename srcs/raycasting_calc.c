/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_calc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 00:34:37 by fsarbout          #+#    #+#             */
/*   Updated: 2021/01/30 08:43:55 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	cast_rays(t_dt *dt, t_mv *mv, t_list **list)
{
	int i;

	g_mv.rayangle = g_dt.plyr_angl - (FOV / 2);
	i = 0;
	while (i < g_dt.numrays)
	{
		fix_cast_angle();
		ray_casting(dt, mv, i, list);
		print_line(dt[i].wallhitx * MINIM, dt[i].wallhity * MINIM);
		g_mv.rayangle += FOV / g_dt.numrays;
		i++;
	}
}

void	ray_casting(t_dt *dt, t_mv *mv, int i, t_list **list)
{
	horizontal_inter(list);
	vertical_inter(list);
	g_dt.hhitdis = (g_dt.horzhit) ? calc_dist(g_dt.horwllhitx, g_dt.horwllhity)
		: BIG_NUM;
	g_dt.vhitdis = (g_dt.verthit) ? calc_dist(g_dt.verwllhitx, g_dt.verwllhity)
		: BIG_NUM;
	if (g_dt.vhitdis < g_dt.hhitdis)
	{
		dt[i].distance = g_dt.vhitdis;
		dt[i].wallhitx = g_dt.verwllhitx;
		dt[i].wallhity = g_dt.verwllhity;
		dt[i].verthit = 1;
	}
	else
	{
		dt[i].distance = g_dt.hhitdis;
		dt[i].wallhitx = g_dt.horwllhitx;
		dt[i].wallhity = g_dt.horwllhity;
		dt[i].verthit = 0;
	}
	mv[i].rayangle = g_mv.rayangle;
	mv[i].raydown = g_mv.raydown;
	mv[i].rayup = g_mv.rayup;
	mv[i].rayleft = g_mv.rayleft;
	mv[i].rayright = g_mv.rayright;
}

void	move_playeer(void)
{
	float	movestep;
	float	movesteps;

	movestep = g_mv.walkdir * g_mv.mvspd;
	movesteps = g_mv.walkdirsd * g_mv.mvspd;
	g_dt.plyr_angl += g_mv.turndir * g_mv.rtnspd;
	g_mv.newx = g_dt.pos_x + cos(g_dt.plyr_angl) * movestep;
	g_mv.newy = g_dt.pos_y + sin(g_dt.plyr_angl) * movestep;
	if (movesteps != 0)
	{
		g_mv.newx = g_dt.pos_x + (cos(g_dt.plyr_angl + (90 * RAD)) * movesteps);
		g_mv.newy = g_dt.pos_y + (sin(g_dt.plyr_angl + (90 * RAD)) * movesteps);
	}
	if (hit_wall(g_mv.newx, g_mv.newy) != '1'
			&& hit_wall(g_mv.newx, g_mv.newy) != '2'
			&& hit_wall(g_mv.newx, g_mv.newy) != ' ')
	{
		g_dt.pos_x = g_mv.newx;
		g_dt.pos_y = g_mv.newy;
	}
}
