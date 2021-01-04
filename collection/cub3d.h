/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 19:33:08 by fsarbout          #+#    #+#             */
/*   Updated: 2021/01/04 11:24:01 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef cub3d_H
# define cub3d_H

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
# define W_WIDTH 500
# define W_HEIGHT 500
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
# define MINIM 0.1
# define RAD (M_PI / 180)

typedef struct s_dt
{
	/////render3d
	float   perpdist;
    float   distpplane;
    float   prjctwallheight;
    int     wallstripheight;
    int     walltop;
    int     wallbttm;
    int     dist_from_top;
		
	//////
	int		color;
	int		size_line;
	int		sp;
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
	int		numrays;
	float  	checkx;
	float  	checky;
	float 	interx;
	float 	intery;
	float 	nxtvrthitx;
	float	nxtvrthity;
	float 	nxthorhitx;
	float	nxthorhity;
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
}			t_mv;

typedef struct	s_txt
{
	int 	*addr_txt[5];
	int 	*addr_sprite;
	void	*so_txt;
	void	*no_txt;
	void	*ea_txt;
	void	*we_txt;
	int 	txt_offsetx;
    int 	txt_offsety;
	void	*img_sprite;
	int 	size_l_sp;
	void	*sp_txt;
}				t_txt;
//////////////////////////////////
typedef struct s_coor
{
	float x;
	float y;
}	t_coor;

typedef struct s_sp
{
	int x;
	int y;
	////
	int center_x;
	int center_y;
	////
	t_coor center;
	float sp_hordist;
	float sp_verdist;
	float dist_plyr_sp;
	float sp_horhitx;
	float sp_horhity;
	float sp_verhitx;
	float sp_verhity;
	////
	float	hhitdis;
	float	vhitdis;
	///
	int horzhit;	
	int verthit;
	float angle;
}	t_sp;

typedef struct	s_list
{
	t_sp 	sp;
	struct	s_list *next;
}				t_list;


//  ,.

//////////////////////////////////
t_txt 	g_txt;
t_mv	g_mv;
t_dt	g_dt;


// void		print_error(int err_nmbr);
int			str_of_num(char *str);
void		struct_intialize();
void		collect_data(char *line, char **av);
void 		treat_rsltn(char **element);
void 		treat_flr(char **element);
void 		treat_cllng(char **element);
int			lenght(char **str);
void    	check_map(char *mp);
void		treat_sprite();
void    	treat_sprite(char **element_data);
void    	draw_map();
void    	rect(int tilex, int tiley,int color);
void		draw_circle(int color);
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
int 		keyreleased(int key, void *param);
int         hit_wall(float x, float y);
void    	cast_rays(t_dt *dt, t_mv *mv);
float    	normalize_angle(float angle);
void 		print_line (int x1, int y1);
void    	ray_casting(t_dt *dt , t_mv *mv, int i,  t_list **list);
void    	fix_cast_angle();
void    	move_playeer();
void    	draw_ray(float x1 , float y1);
float    	calculate_dist(float x2, float y2);
void    	vertical_inter(float xstep, float ystep, t_list **list);
void    	horizontal_loop(float xstep,float ystep,  t_list **list);
void    	vertical_loop(float xstep,float ystep,  t_list **list);
void    	render3d(t_dt *dt, t_mv *mv);
void    	horizontal_inter(float xstep, float ystep, t_list **list);
void    	treat_txt(char **element_data, void **img, int *flag);
int 		check_txt_name(char **element, char *txt, int flag);
void		print_error(char *string);
void    	calc_render3d(t_dt *dt, t_mv *mv, int *i, int *j);
void        draw_circle_s(int xstart, int ystart);
t_coor    	get_center_coor(float spx, float spy);
void    	sprite_calc_horz(t_list **list);
void    	sprite_calc_vert(t_list **list);
//linked_lst
void lst_add_back(t_list **lst, t_sp sp);
void append(t_list **lst, t_sp sp);
// void		append(t_list **lst, t_sprite sp);
// void		clear_list(t_list **lst);

#endif