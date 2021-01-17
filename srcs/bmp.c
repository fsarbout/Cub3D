/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 09:38:57 by fsarbout          #+#    #+#             */
/*   Updated: 2021/01/17 11:07:46 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	bmp_initialize(t_bmp *bmp)
{
	int i;

	i = 0;
	bmp->bitcount = 32;
	bmp->imagesize = g_dt.rsltn_w * g_dt.rsltn_h * 4;
	bmp->bisize = 40;
	bmp->bfoff_bits = 54;
	bmp->filesize = 54 + bmp->imagesize;
	bmp->bi_planes = 1;
	while (i < 54)
		bmp->header[i++] = 0;
	ft_memcpy(bmp->header, "BM", 2);
	ft_memcpy(bmp->header + 2, &bmp->filesize, 4);
	ft_memcpy(bmp->header + 10, &bmp->bfoff_bits, 4);
	ft_memcpy(bmp->header + 14, &bmp->bisize, 4);
	ft_memcpy(bmp->header + 18, &g_dt.rsltn_w, 4);
	ft_memcpy(bmp->header + 22, &g_dt.rsltn_h, 4);
	ft_memcpy(bmp->header + 26, &bmp->bi_planes, 2);
	ft_memcpy(bmp->header + 28, &bmp->bitcount, 2);
	ft_memcpy(bmp->header + 34, &bmp->imagesize, 4);
}

void	create_bmp_file(void)
{
	t_bmp			bmp;
	int				i;
	int				j;
	int				*pixel;

	i = 0;
	bmp_initialize(&bmp);
	j = g_dt.rsltn_h - 1;
	bmp.fd = open("cub3d.bmp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	write(bmp.fd, bmp.header, 54);
	while (j > -1)
	{
		i = 0;
		while (i < g_dt.rsltn_w)
		{
			bmp.pos = (i + g_dt.rsltn_w * j);
			pixel = (int *)(g_dt.addrmlx) + bmp.pos;
			write(bmp.fd, pixel, 4);
			i++;
		}
		j--;
	}
	close(bmp.fd);
	exit(EXIT_SUCCESS);
}

void	render_bmp_img(void)
{
	create_bmp_file();
}
