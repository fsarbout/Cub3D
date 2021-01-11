
#ifndef FUNCTIONS_H
# define FUNCTIONS_H

#include "cub3d.h"

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
void    	cast_rays(t_dt *dt, t_list **list);
float    	normalize_angle(float angle);
void 		print_line (int x1, int y1);
void    	ray_casting(t_dt *dt , int i,t_list **list);
void    	fix_cast_angle();
void    	move_playeer();
void    	draw_ray(float x1 , float y1);
float    	calculate_dist(float x2, float y2);
void    	vertical_inter(t_list **list, t_dt *dt, int i);
void    	horizontal_loop(t_list **list, t_dt *dt, int i);
void    	vertical_loop(t_list **list, t_dt *dt, int i);
void    	render3d(t_dt *dt, t_list **list);
void    	horizontal_inter(t_list **list, t_dt *dt, int i);
void    	treat_txt(char **element_data, void **img, int *flag);
int 		check_txt_name(char **element, char *txt, int flag);
void		print_error(char *string);
void    	calc_render3d(t_dt *dt, int *i, int *j);
void        draw_circle_s(int xstart, int ystart);
t_coor    	get_center_coor(float spx, float spy);
/* void        sprite_calc(t_list **list); */
void    sprite_calc(t_list **list, t_dt *t , int i);
void        lst_add_back(t_list **head, t_sp spr);
float       normalize_sp_angle(float angle);
void        sort_list(t_list *lst);
void        clear_list(t_list **lst);
void        render_sprite(t_dt *dt, t_list **list);
int         check_exists(t_list *lst, float x, float y);
void        draw_sprite(t_list **list, t_dt *dt);
void        render_one_sprite(t_dt *dt, t_list **list);

#endif