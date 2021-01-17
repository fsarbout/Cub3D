/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 19:18:29 by fsarbout          #+#    #+#             */
/*   Updated: 2021/01/17 12:10:48 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "cub3d.h"

int		str_of_num(char *str);
void	struct_intialize(void);
void	collect_data(char *line, char **av, int fd, int i);
void	treat_rsltn(char **element);
void	treat_flr(char **element);
void	treat_cllng(char **element);
int		lenght(char **str);
void	check_map(char *mp);
void	treat_sprite(char **element_data);
int		keypressed(int key);
int		hooking(void);
int		exiit(void);
void	update(void);
void	mlxs(void);
void	che_ck_map(int i, int fd, char *line, char *map);
void	check_elements(char **element);
void	player(char **map, int i, int j);
void	check_sprite(int i, int j);
void	parse_map(char **map, int i, int j);
void	fill_maplines(char **map);
void	if_dif_one(char **map, int i, int j);
int		keyreleased(int key);
int		hit_wall(float x, float y);
void	cast_rays(t_dt *dt, t_mv *mv, t_list **list);
float	normalize_angle(float angle);
void	ray_casting(t_dt *dt, t_mv *mv, int i, t_list **list);
void	fix_cast_angle(void);
void	move_playeer(void);
float	calc_dist(float x2, float y2);
void	vertical_inter(t_list **list);
void	horizontal_loop(t_list **list);
void	vertical_loop(t_list **list);
void	render3d(t_dt *dt, t_mv *mv);
void	horizontal_inter(t_list **list);
void	treat_txt(char **element_data, void **img, int *flag);
int		check_txt_name(char **element, char *txt, int flag);
void	print_error(char *string);
void	calc_render3d(t_dt *dt, t_mv *mv, int *i, int *j);
void	draw_circle_s(int xstart, int ystart);
t_coor	get_center_coor(float spx, float spy);
void	sprite_calc(t_list **list);
void	lst_add_back(t_list **head, t_sp spr);
void	sort_list(t_list *lst);
void	clear_list(t_list **lst);
void	render_sprite(t_dt *dt, t_list **list);
int		check_exists(t_list *lst, float x, float y);
void	draw_sprite(t_list **list, t_dt *dt);
void	render_one_sprite(t_dt *dt, t_list **list);
int		commas(char *ptr);
int		create_trgb(int t, int r, int g, int b);
int		check_rsltn(char *resolution);
void	wall_floor(int y, int i, int j);
void	get_texture(void);
float	angle(float sp_angle);
void	print_it(int y, int start, t_list **list);
void	freee(char **tab);
void	bmp_initialize(t_bmp *bmp);
void	create_bmp_file(void);
size_t	ft_strlen_point(const char *s);
void	check_extension(char *s);
void	check_save(char *ptr);
void	render_bmp_img(void);
int		reversecheck(char *s, char *str);

#endif
