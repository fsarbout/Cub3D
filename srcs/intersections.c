/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 23:39:30 by fsarbout          #+#    #+#             */
/*   Updated: 2021/01/16 17:59:49 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	horizontal_inter(t_list **list)
{
	g_dt.hhitdis = 0;
	g_dt.horwllhitx = 0;
	g_dt.horwllhity = 0;
	g_dt.horzhit = 0;
	g_dt.intery = (int)(g_dt.pos_y / TILE) * TILE;
	g_dt.intery += g_mv.raydown ? TILE : 0;
	g_dt.interx = g_dt.pos_x + (g_dt.intery - g_dt.pos_y)
		/ tan(g_mv.rayangle);
	g_dt.ystep = TILE;
	g_dt.ystep *= g_mv.rayup ? -1 : 1;
	g_dt.xstep = g_dt.ystep / tan(g_mv.rayangle);
	g_dt.xstep *= (g_mv.rayleft && g_dt.xstep > 0) ? -1 : 1;
	g_dt.xstep *= (g_mv.rayright && g_dt.xstep < 0) ? -1 : 1;
	g_dt.nxthorhitx = g_dt.interx;
	g_dt.nxthorhity = g_dt.intery;
	horizontal_loop(list);
}

void	horizontal_loop(t_list **list)
{
	while (g_dt.nxthorhitx >= 0 && g_dt.nxthorhitx <= (g_dt.long_l * TILE)
			&& g_dt.nxthorhity >= 0
			&& g_dt.nxthorhity <= (g_dt.nbr_lines * TILE))
	{
		g_dt.checkx = g_dt.nxthorhitx;
		g_dt.checky = g_dt.nxthorhity + (g_mv.rayup ? -1 : 0);
		if (hit_wall(g_dt.checkx, g_dt.checky) == '2')
			sprite_calc(list);
		if (hit_wall(g_dt.checkx, g_dt.checky) == '1')
		{
			g_dt.horzhit = 1;
			g_dt.horwllhitx = g_dt.nxthorhitx;
			g_dt.horwllhity = g_dt.nxthorhity;
			break ;
		}
		else
		{
			g_dt.nxthorhitx += g_dt.xstep;
			g_dt.nxthorhity += g_dt.ystep;
		}
	}
}

void	vertical_inter(t_list **list)
{
	g_dt.verwllhitx = 0;
	g_dt.verwllhity = 0;
	g_dt.vhitdis = 0;
	g_dt.verthit = 0;
	g_dt.interx = (int)(g_dt.pos_x / TILE) * TILE;
	g_dt.interx += g_mv.rayright ? TILE : 0;
	g_dt.intery = g_dt.pos_y + (g_dt.interx - g_dt.pos_x) * tan(g_mv.rayangle);
	g_dt.xstep = TILE;
	g_dt.xstep *= g_mv.rayleft ? -1 : 1;
	g_dt.ystep = TILE * tan(g_mv.rayangle);
	g_dt.ystep *= (g_mv.rayup && g_dt.ystep > 0) ? -1 : 1;
	g_dt.ystep *= (g_mv.raydown && g_dt.ystep < 0) ? -1 : 1;
	g_dt.nxtvrthitx = g_dt.interx;
	g_dt.nxtvrthity = g_dt.intery;
	vertical_loop(list);
}

void	vertical_loop(t_list **list)
{
	while (g_dt.nxtvrthitx >= 0 && g_dt.nxtvrthitx <= (g_dt.long_l * TILE)
			&& g_dt.nxtvrthity >= 0
			&& g_dt.nxtvrthity <= (g_dt.nbr_lines * TILE))
	{
		g_dt.checkx = g_dt.nxtvrthitx + (g_mv.rayleft ? -1 : 0);
		g_dt.checky = g_dt.nxtvrthity;
		if (hit_wall(g_dt.checkx, g_dt.checky) == '2')
			sprite_calc(list);
		if (hit_wall(g_dt.checkx, g_dt.checky) == '1')
		{
			g_dt.verthit = 1;
			g_dt.verwllhitx = g_dt.nxtvrthitx;
			g_dt.verwllhity = g_dt.nxtvrthity;
			break ;
		}
		else
		{
			g_dt.nxtvrthitx += g_dt.xstep;
			g_dt.nxtvrthity += g_dt.ystep;
		}
	}
}

int		hit_wall(float x, float y)
{
	int mapx;
	int mapy;

	if (x < 0 || x >= (g_dt.long_l * TILE) || y < 0
			|| (y >= (g_dt.nbr_lines * TILE)))
		return (1);
	mapx = floor(x / TILE);
	mapy = floor(y / TILE);
	return (g_dt.mmp[mapy][mapx]);
}
