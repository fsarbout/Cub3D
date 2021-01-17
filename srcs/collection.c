/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 00:12:10 by fsarbout          #+#    #+#             */
/*   Updated: 2021/01/16 17:39:29 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	treat_rsltn(char **element_data)
{
	g_dt.r = 1;
	if (check_rsltn(element_data[1]) >= 9)
		g_dt.rsltn_w = MAX_WIDTH;
	if (!g_dt.rsltn_w)
	{
		if (!str_of_num(element_data[1]))
			print_error("   wrong resolution width value!\n");
		g_dt.rsltn_w = ft_atoi(element_data[1]);
		g_dt.rsltn_w > MAX_WIDTH ? g_dt.rsltn_w = MAX_WIDTH : 0;
	}
	if (check_rsltn(element_data[2]) >= 9)
		g_dt.rsltn_h = MAX_HEIGHT;
	if (!g_dt.rsltn_h)
	{
		if (!str_of_num(element_data[2]))
			print_error("   wrong resolution height value!\n");
		g_dt.rsltn_h = ft_atoi(element_data[2]);
		g_dt.rsltn_h > MAX_HEIGHT ? g_dt.rsltn_h = MAX_HEIGHT : 0;
	}
}

void	treat_flr(char **element_data)
{
	char	**rgb;

	g_dt.f = 1;
	if (commas(element_data[1]) != 2)
		print_error("   commas problem rgb!\n");
	rgb = ft_split(element_data[1], ',');
	if (lenght(rgb) != 3)
		print_error("  wrong data in floor rgb values!\n");
	if (!str_of_num(rgb[0]) || !str_of_num(rgb[1]) || !str_of_num(rgb[2]))
		print_error("  wrong data in floor rgb values!\n");
	g_dt.flr_r = ft_atoi(rgb[0]);
	g_dt.flr_g = ft_atoi(rgb[1]);
	g_dt.flr_b = ft_atoi(rgb[2]);
	g_dt.flr_color = create_trgb(0, g_dt.flr_r, g_dt.flr_g, g_dt.flr_b);
	if ((g_dt.flr_r < 0 || g_dt.flr_r > 255)
		|| (g_dt.flr_g < 0 || g_dt.flr_g > 255)
			|| (g_dt.flr_b < 0 || g_dt.flr_b > 255))
		print_error("  wrong data in floor rgb values!\n");
	freee(rgb);
}

void	treat_cllng(char **element_data)
{
	char	**rgb;

	g_dt.c = 1;
	if (commas(element_data[1]) != 2)
		print_error("   commas problem rgb!\n");
	rgb = ft_split(element_data[1], ',');
	if (lenght(rgb) != 3)
		print_error("  wrong data in ceilling rgb values!\n");
	if (!str_of_num(rgb[0]) || !str_of_num(rgb[1]) || !str_of_num(rgb[2]))
		print_error("  wrong data in ceilling rgb values!\n");
	g_dt.cllng_r = ft_atoi(rgb[0]);
	g_dt.cllng_g = ft_atoi(rgb[1]);
	g_dt.cllng_b = ft_atoi(rgb[2]);
	g_dt.cllng_color = create_trgb(0, g_dt.cllng_r, g_dt.cllng_g, g_dt.cllng_b);
	if ((g_dt.cllng_r < 0 || g_dt.cllng_r > 255)
		|| (g_dt.cllng_g < 0 || g_dt.cllng_g > 255)
			|| (g_dt.cllng_b < 0 || g_dt.cllng_b > 255))
		print_error("  wrong data in ceilling rgb values!\n");
	freee(rgb);
}

int		commas(char *ptr)
{
	int		j;
	int		i;
	char	c;

	c = ',';
	i = 0;
	j = 0;
	while (ptr[i])
	{
		if (ptr[i] == c)
			j++;
		i++;
	}
	return (j);
}

int		check_rsltn(char *resolution)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (resolution[i])
	{
		if (i == 0)
			while (resolution[i] == '0')
				i++;
		if (!ft_isdigit(resolution[i]))
			print_error("   wrong resolution value!\n");
		j++;
		i++;
	}
	return (j);
}
