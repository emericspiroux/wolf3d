/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espiroux <espiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/11 10:20:00 by espiroux          #+#    #+#             */
/*   Updated: 2015/03/04 10:20:07 by espiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct			s_move {
	double				posx;
	double				posy;
	double				dirx;
	double				diry;
	double				planex;
	double				planey;
	double				rotspeed;
	double				movespeed;
	int					weapon;
	int					left;
	int					right;
	int					top;
	int					bottom;
	int					sprint;
	int					shoot;
	int					step_shoot;
	double				distw;
	double				distp;
}						t_move;

typedef struct			s_ray{
	double				rayposx;
	double				rayposy;
	double				raydirx;
	double				raydiry;
	double				sidedistx;
	double				sidedisty;
	double				deltadistx;
	double				deltadisty;
	int					stepx;
	int					stepy;
	int					hit;
	int					side;
	double				wallx;
	int					lineheight;
	int					drawstart;
	int					drawend;
	double				perpwalldist;
	int					y;
	int					x;
}						t_ray;

typedef struct			s_map{
	int					mapx;
	int					mapy;
	int					**map;
	unsigned int		longu;
	unsigned int		larg;
	int					sky;
}						t_map;

typedef struct			s_img{
	int					bpp;
	int					sline;
	int					endi;
	int					width;
	int					height;
	char				*pimg;
	void				*img;
	int					px;
	int					py;
}						t_img;

typedef struct			s_sprite {
	double				x;
	double				y;
	int					texture;
	int					texture_death;
	int					texture_hit;
	int					life;
	int					rip;
	int					hit;
}						t_sprite;

typedef struct			s_calspr {
	int					scx;
	int					h;
	int					w;
	int					s;
}						t_calspr;

typedef struct			s_color{
	int					red;
	int					green;
	int					blue;
}						t_color;

typedef struct			s_wea{
	char				*name;
	int					power;
}						t_wea;

typedef struct			s_point
{
	int					x;
	int					y;
}						t_point;

typedef struct			s_dpoint
{
	double				x;
	double				y;
}						t_dpoint;

typedef struct			s_draw
{
	t_point				start;
	t_point				end;
	int					sprite_state;
	int					i;
}						t_draw;

typedef struct			s_env {
	void				*mlx;
	void				*win;
	double				zbuffer[WINWIDTH];
	int					score;
	double				time;
	double				oldtime;
	long int			frametime;
	int					debbug;
	int					spriteorder[NUMSPRITES];
	struct s_move		move;
	struct s_ray		ray;
	struct s_img		image;
	struct s_map		map;
	struct s_img		sky;
	struct s_img		tex[13];
	struct s_img		weap[NUMWEAPON][5];
	struct s_wea		weap_info[NUMWEAPON];
	struct s_sprite		sprite[NUMSPRITES];
	struct s_draw		draw;
}						t_env;

#endif
