/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_data.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 19:33:08 by fsarbout          #+#    #+#             */
/*   Updated: 2020/12/11 01:22:51 by fsarbout         ###   ########.fr       */
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
# define TILE 64
# define STEP 20
# define UP 13
# define DOWN 1
# define ESC 53
# define LEFT 0
# define RIGHT 2
# define T_RIGHT 124
# define T_LEFT 123
# define FOV 60 * (M_PI / 180)
# define WALL_S_W 0.5

typedef struct s_dt
{
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
	float pos_xsd;
	float pos_ysd;
	int 	side;
	
	int 	nbr_lines;
	int 	endian;
	int		long_l;
	int		size_l;
	int		*addrmlx;
	void	*window;
	void	*imgmlx;
	int		bpp;
	float	horwllhitx;
	float	horwllhity;
	float	verwllhitx;
	float	verwllhity;
	float	wallhitx;
	float	wallhity;
	float 	distance;
	float 	hhitdis;
	float 	vhitdis;
	float 	verthit;
	float 	horzhit;
}			t_dt;

///////////
typedef struct  s_mv
{
	float	turndir;
	float	walkdir;
	float 	walkdirsd;
	float	mvspd;
	float	rtnspd;
	float newxplyr;
    float newyplyr;
	int raydown;
    int rayup;
    int rayleft;
    int rayright;
	float raydist;
	float rayangle;
}				t_mv;
t_mv	g_mv;
t_dt		g_dt;

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
void		dda();
int 		keyreleased(int key, void *param);
int         hit_wall(float x, float y);
void    	cast_rays();
float    	normalize_angle();
void 		print_line (int x1, int y1);
void    	ray_castintg();
void    	fix_cast_angle();
void    	move_playeer();
void    	draw_ray(float x1 , float y1);
float    	calculate_dist(float x2, float y2);
void    	horizontal_inter(float xstep, float ystep, float intrceptx, float intrcepty);
void    	vertical_inter(float xstep, float ystep, float intrceptx, float intrcepty);
void    	horizontal_loop(float xstep,float ystep,float nxthorzhitx, float nxthorzhity);
void    	vertical_loop(float xstep,float ystep,float nxtverhitx, float nxtverhity);

#endif