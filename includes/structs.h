
#ifndef STRUCTS_H
#define STRUCTS_H


typedef struct s_dt
{
	float   perpdist;
    float   distpplane;
    float   prjctwallheight;
    int     wallstripheight;
    int     walltop;
    int     wallbttm;
    int     dist_from_top;
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
	void	*mlx;
	int		plyr;
	float	plyr_angl;
	float 	pos_x;
	float 	pos_y;
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
	/////////////////////////////
	float 	angle_plyr;
	int 	nb_sprite;
	float 	xstep;
	float 	ystep;
}			t_dt;


typedef struct  s_mv
{
	float	turndir;
	float	walkdir;
	float 	walkdirsd;
	float	mvspd;
	float	rtnspd;
	float 	newxplyr;
    float 	newyplyr;
	int 	raydown;
    int 	rayup;
    int 	rayleft;
    int 	rayright;
	float 	raydist;
	float 	rayangle;
}			t_mv;

typedef struct	s_txt
{
	int 	*addr_txt[4];
	int		*sprite_txt;
	void	*so_txt;
	void	*no_txt;
	void	*ea_txt;
	void	*we_txt;
	int 	txt_offsetx;
    int 	txt_offsety;
	int 	size_l_sp;
	void	*sp_txt;
}				t_txt;

typedef struct s_coor
{
	float x;
	float y;
}	t_coor;

typedef struct s_sp
{
	int x;
	int y;
	t_coor center;
	float sp_hordist;
	float sp_verdist;
	float dist_plyr_sp;
	float angle;
	int 	horzhit;	
	int verthit;
	int height;
	int height_s;
	int height_e;
	int width_s;
	int width_e;
}	t_sp;

typedef struct	s_list
{
	t_sp 	sp;
	struct	s_list *next;
}				t_list;

t_txt 	g_txt;
t_mv	g_mv;
t_dt	g_dt;


#endif