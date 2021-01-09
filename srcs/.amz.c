
float	calc_sp_x_start(t_player plr, t_data info, t_crd sprite)
{
	float	x;
	float	sp_angle;
	float	pixel_num;

	sp_angle = norm_a(atan2((sprite.y) - plr.y,
			(sprite.x) - plr.x) * (180 / M_PI));
	plr.rotation_a = (int)norm_a(plr.rotation_a - 30);
	sp_angle = sp_angle - plr.rotation_a;
	sp_angle = norm_a(sp_angle);
	pixel_num = FOV_ANGLE / (float)info.wx;
	x = sp_angle / pixel_num;
	return (x);
}

/*
 ** Here trp means strip i've made it short just for the norm
*/

void	draw_sprite_texture(t_sprite sprt, t_data info, int i)
{
	int		trp;
	int		tex_x;
	int		tex_y;
	int		y;
	int		d;

	trp = sprt.wi_s;
	while (trp < sprt.wi_e && sprt.wi_s < info.wx)
	{
		tex_x = (256 * (trp - sprt.wi_s) * SQ_SZ / sprt.height) / 256;
		y = sprt.hi_s;
		if (trp >= 0 && trp <= info.wx &&
			g_sprite_distance[i] < g_wall_distance[trp])
		{
			while (y < sprt.hi_e)
			{
				d = y + (sprt.height / 2) - (info.wy / 2);
				tex_y = d * ((SQ_SZ * 1.0) / sprt.height);
				if (info.s[SQ_SZ * tex_y + tex_x] != 0)
					g_img_data[y * info.wx + trp] = info.s[64 * tex_y + tex_x];
				y++;
			}
		}
		trp++;
	}
}