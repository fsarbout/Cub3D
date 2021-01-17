/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 12:37:57 by fsarbout          #+#    #+#             */
/*   Updated: 2021/01/17 10:58:00 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		hooking(void)
{
	mlx_hook(g_dt.window, 2, 1L << 0, keypressed, 0);
	mlx_hook(g_dt.window, 3, 1L << 1, keyreleased, 0);
	mlx_hook(g_dt.window, 17, 0L, exiit, 0);
	update();
	return (1);
}

int		keypressed(int key)
{
	if (key == DOWN)
		g_mv.walkdir = -1;
	if (key == UP)
		g_mv.walkdir = 1;
	if (key == LEFT)
		g_mv.walkdirsd = -1;
	if (key == RIGHT)
		g_mv.walkdirsd = 1;
	if (key == T_RIGHT)
		g_mv.turndir = 1;
	if (key == T_LEFT)
		g_mv.turndir = -1;
	if (key == ESC)
		exiit();
	update();
	return (0);
}

int		keyreleased(int key)
{
	if (key == DOWN)
		g_mv.walkdir = 0;
	if (key == UP)
		g_mv.walkdir = 0;
	if (key == LEFT)
		g_mv.walkdirsd = 0;
	if (key == RIGHT)
		g_mv.walkdirsd = 0;
	if (key == T_RIGHT)
		g_mv.turndir = 0;
	if (key == T_LEFT)
		g_mv.turndir = 0;
	if (key == ESC)
		exiit();
	update();
	return (0);
}

void	update(void)
{
	t_dt	dt[g_dt.numrays];
	t_mv	mv[g_dt.numrays];
	t_list	*list;

	list = NULL;
	mlx_destroy_image(g_dt.mlx, g_dt.imgmlx);
	g_dt.imgmlx = mlx_new_image(g_dt.mlx, g_dt.rsltn_w, g_dt.rsltn_h);
	g_dt.addrmlx = (int*)mlx_get_data_addr(g_dt.imgmlx,
			&g_dt.bpp, &g_dt.size_l, &g_dt.endian);
	move_playeer();
	cast_rays(dt, mv, &list);
	render3d(dt, mv);
	if (list)
	{
		sort_list(list);
		draw_sprite(&list, dt);
	}
	clear_list(&list);
	if (g_dt.save)
	{
		render_bmp_img();
		exit(EXIT_SUCCESS);
	}
	mlx_put_image_to_window(g_dt.mlx, g_dt.window, g_dt.imgmlx, 0, 0);
}

int		exiit(void)
{
	mlx_destroy_window(g_dt.mlx, g_dt.window);
	free(g_dt.mmp);
	exit(EXIT_SUCCESS);
	return (1);
}
