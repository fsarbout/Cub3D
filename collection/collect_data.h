/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_data.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 19:33:08 by fsarbout          #+#    #+#             */
/*   Updated: 2020/12/01 10:57:58 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLLECT_DATA_H
# define COLLECT_DATA_H


#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include "../libft/libft.h"
#include "../minilibx/mlx.h"
#include <math.h>

# define MAX_WIDTH	2560
# define MAX_HEIGHT	1440
# define W_WIDTH 1000
# define W_HEIGHT 1000
# define TILE 20
# define STEP 20
# define UP 13
# define DOWN 1
# define ESC 53
# define LEFT 0
# define RIGHT 2
# define T_RIGHT 124
# define T_LEFT 123

//#define  PI acos(-1.0)

///////////////



typedef struct s_data
{
	int 	ifdda;
	int		r;
	int		rsltn_w;
	int 	rsltn_h;
	int		f;
	char	**mmp;
	int		flr_r;
	int		flr_g;
	int 	flr_b;
	int		c;
	int 	cllng_r;
	int 	cllng_g;
	int 	cllng_b;
	int 	n;
	int		so;
	int		e;
	int		w;
	int 	spi;
	int 	spj;
	int		width;
	int		height;
	char	*n_path;
	char	*e_path;
	char	*w_path;
	char	*so_path;
	//char	*s_path;
	void	*mlx;
	void	*img_so;
	void	*img_no;
	void	*img_ea;
	void	*img_we;
	int		plyr;
	//int		img_s;
	float	plyr_angl;
	//////////
	float pos_x;
	float pos_y;
	int 	nbr_lines;
	int 	endian;
	int		long_l;
	int		size_l;
	int		*addrmlx;
	// char		*addrmlx;
	void	*window;
	void	*imgmlx;
	int		bpp;


}			t_data;
typedef struct  s_mv
{
    float	radius;
	float	turndir;
	float	walkdir;
	float 	walkdirsd;
	float	rtnangl;
	float	mvspd;
	float	rtnspd;
	int		plyr_walkdir;
}				t_mv;
t_mv	g_mv;
t_data		g_data;

void		print_error(int err_nmbr);
int			str_of_num(char *str);
void		struct_intialize();
void		collect_data(char *line, char **av);
void 		treat_west(char **element);
void 		treat_east(char **element);
void 		treat_north(char **element);
void 		treat_south(char **element);
void 		treat_rsltn(char **element);
void 		treat_flr(char **element);
void 		treat_cllng(char **element);
int			lenght(char **str);
void    	check_map(char *mp);
void		treat_sprite();
void        my_mlx_pixel_put(int x, int y, int color);
void    	draw_map();
void    	rect(int tilex, int tiley,int color);
void		draw_circle();
int    		keypressed(int key, void *param);
int    		hooking(void *param);
int 		exiit(int key, void *param);
void		draw_line(int dir);
void		update();
void   		mlxs();
void    	che_ck_map(int i, int fd, char *line, char *map);
void    	check_elements(char **element);
void    	player(char **map, int i, int j);
void    	check_sprite(int i, int j);
void   		parse_map(char **map, int i, int j);
void    	fill_maplines(char **map);
void    	if_dif_one(char **map, int i, int j);
// void    	dda1(double x1, double y1, double x0, double y0);
void	dda();
int keyreleased(int key, void *param);


#endif