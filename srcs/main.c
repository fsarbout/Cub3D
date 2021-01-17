/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 18:20:39 by fsarbout          #+#    #+#             */
/*   Updated: 2021/01/17 11:32:37 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		main(int ac, char **av)
{
	char *line;

	line = NULL;
	if (ac == 1 || ac > 3)
		print_error("	wrong number of arguments... !\n");
	check_extension(av[1]);
	struct_intialize();
	collect_data(line, av, 0, 0);
	g_dt.numrays = g_dt.rsltn_w;
	if (ac == 3)
	{
		check_save(av[2]);
		g_dt.save = 1;
	}
	mlxs();
	freee(g_dt.mmp);
	return (0);
}

void	mlxs(void)
{
	g_dt.window = mlx_new_window(g_dt.mlx, g_dt.rsltn_w
			, g_dt.rsltn_h, "Hello!");
	g_dt.imgmlx = mlx_new_image(g_dt.mlx, g_dt.rsltn_w, g_dt.rsltn_h);
	g_dt.addrmlx = (int*)mlx_get_data_addr(g_dt.imgmlx, &g_dt.bpp, &g_dt.size_l,
			&g_dt.endian);
	update();
	mlx_put_image_to_window(g_dt.mlx, g_dt.window, g_dt.imgmlx, 0, 0);
	hooking();
	mlx_loop(g_dt.mlx);
}

void	check_save(char *ptr)
{
	if ((!ft_strncmp(ptr, "--save", 7)))
		return ;
	else
		print_error("	3rd arg wrong!\n");
}
