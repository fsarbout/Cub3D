/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 18:20:39 by fsarbout          #+#    #+#             */
/*   Updated: 2021/01/15 19:03:14 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int main(int ac, char **av)
{
    char *line;

    line = NULL;
    if (ac != 2)
    {
        printf("ERROR IN ARGUMENTS OF MAIN");
        return (0);
    }
    // else
    collect_data(line, av);
    g_dt.numrays = g_dt.rsltn_w ;
    mlxs();
   free (g_dt.mmp);
    return (0);
}

void   mlxs()
{
    void *param;

    param = NULL;
    g_dt.window = mlx_new_window(g_dt.mlx, g_dt.rsltn_w, g_dt.rsltn_h, "Hello!");
    g_dt.imgmlx  = mlx_new_image(g_dt.mlx, g_dt.rsltn_w , g_dt.rsltn_h);
	g_dt.addrmlx = (int*)mlx_get_data_addr(g_dt.imgmlx, &g_dt.bpp, &g_dt.size_l,
                                 &g_dt.endian);
    update();
    mlx_put_image_to_window(g_dt.mlx, g_dt.window, g_dt.imgmlx, 0, 0);
    hooking();
    mlx_loop(g_dt.mlx);
}