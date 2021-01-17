/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 06:26:39 by fsarbout          #+#    #+#             */
/*   Updated: 2021/01/16 18:38:27 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	render3d(t_dt *dt, t_mv *mv)
{
	int	i;
	int	y;
	int	j;

	j = 7;
	i = 0;
	get_texture();
	g_dt.distpplane = ((g_dt.rsltn_w) / 2) / tan(FOV / 2);
	while (i < g_dt.numrays)
	{
		calc_render3d(dt, mv, &i, &j);
		y = 0;
		while (y < g_dt.walltop)
		{
			if (i < 0 || i > g_dt.rsltn_w || y < 0 || y > g_dt.rsltn_h
					|| i > g_dt.rsltn_w || y > g_dt.rsltn_h)
				break ;
			if (((g_dt.size_l * g_dt.rsltn_h) / 4) > (y * (g_dt.rsltn_w) + i))
				g_dt.addrmlx[y * (g_dt.rsltn_w) + i] = g_dt.cllng_color;
			y++;
		}
		y = g_dt.walltop;
		wall_floor(y, i, j);
		i++;
	}
}

void	calc_render3d(t_dt *dt, t_mv *mv, int *i, int *j)
{
	g_txt.txt_offsetx = dt[*i].verthit ? (int)dt[*i].wallhity % 64
		: (int)dt[*i].wallhitx % 64;
	g_dt.perpdist = dt[*i].distance * cos(mv[*i].rayangle - g_dt.plyr_angl);
	g_dt.prjctwallheight = (TILE / g_dt.perpdist) * g_dt.distpplane;
	g_dt.wallstripheight = (int)g_dt.prjctwallheight;
	g_dt.walltop = ((g_dt.rsltn_h) / 2) - (g_dt.wallstripheight / 2);
	g_dt.walltop = g_dt.walltop < 0 ? 0 : g_dt.walltop;
	g_dt.wallbttm = ((g_dt.rsltn_h) / 2) + (g_dt.wallstripheight / 2);
	g_dt.wallbttm = g_dt.wallbttm > (g_dt.rsltn_h) ? (g_dt.rsltn_h)
		: g_dt.wallbttm;
	if (mv[*i].rayup && !dt[*i].verthit)
		*j = 2;
	if (!mv[*i].rayup && !dt[*i].verthit)
		*j = 0;
	if (mv[*i].rayright && dt[*i].verthit)
		*j = 1;
	if (!mv[*i].rayright && dt[*i].verthit)
		*j = 3;
}

void	draw_sprite(t_list **list, t_dt *dt)
{
	t_list *disp;

	disp = *list;
	while (disp)
	{
		render_one_sprite(dt, &disp);
		disp = disp->next;
	}
}

void	wall_floor(int y, int i, int j)
{
	while (y < g_dt.wallbttm)
	{
		if (i < 0 || i > g_dt.rsltn_w || y < 0 || y > g_dt.rsltn_h
				|| i > g_dt.rsltn_w || y > g_dt.rsltn_h)
			break ;
		g_dt.top = y + (g_dt.wallstripheight / 2) - ((g_dt.rsltn_h) / 2);
		g_txt.txt_offsety = g_dt.top * ((float)64 / g_dt.wallstripheight);
		g_dt.color = (int)g_txt.addr_txt[j][(int)(64 * g_txt.txt_offsety
				+ g_txt.txt_offsetx)];
		if (((g_dt.size_l * g_dt.rsltn_h) / 4) > (y * (g_dt.rsltn_w) + i))
			g_dt.addrmlx[y * (g_dt.rsltn_w) + i] = g_dt.color;
		y++;
	}
	y = g_dt.wallbttm;
	while (y < (g_dt.rsltn_h))
	{
		if (i < 0 || i > g_dt.rsltn_w || y < 0 || y > g_dt.rsltn_h
				|| i > (g_dt.rsltn_w) || y > g_dt.rsltn_h)
			break ;
		if (((g_dt.size_l * g_dt.rsltn_h) / 4) > (y * (g_dt.rsltn_w) + i))
			g_dt.addrmlx[y * (g_dt.rsltn_w) + i] = g_dt.flr_color;
		y++;
	}
}

void	get_texture(void)
{
	g_txt.addr_txt[0] = (int*)mlx_get_data_addr(g_txt.no_txt, &g_dt.bpp
			, &g_dt.size_line, &g_dt.endian);
	g_txt.addr_txt[2] = (int*)mlx_get_data_addr(g_txt.so_txt, &g_dt.bpp
			, &g_dt.size_line, &g_dt.endian);
	g_txt.addr_txt[1] = (int*)mlx_get_data_addr(g_txt.we_txt, &g_dt.bpp
			, &g_dt.size_line, &g_dt.endian);
	g_txt.addr_txt[3] = (int*)mlx_get_data_addr(g_txt.ea_txt, &g_dt.bpp
			, &g_dt.size_line, &g_dt.endian);
}
