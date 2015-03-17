/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espiroux <espiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0013/10/08 18:00:50 by espiroux          #+#    #+#             */
/*   Updated: 2015/03/04 11:50:34 by espiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "libft.h"
# include "get_next_line.h"
# include "mlx.h"
# define MAPWIDTH 24
# define MAPHEIGH 24
# define WINWIDTH 1080
# define WINHEIGHT 700
# define HEIGH 64
# define WIDTH 64
# define HEIGHPLAY 32
# define NUMSPRITES 7
# define LEFTED_WEAPON 300
# define TOPED_WEAPON 100
# define NUMWEAPON 2
# define SLEEP_FRAMETIME_CPU 1
# define TIME_SHOOT_HIT 10
# define TIME_SHOOT_ANIM 3
# include "struct.h"

/*
** Key andd expose features
*/

int				move_player(t_env *e);
void			move_walk(t_env *e, char s);
void			move_side(t_env *e, char s);
void			move_key(int keycode, t_env *e, int etat);
int				key_press(int keycode, t_env *e);
int				key_release(int keycode, t_env *e);

/*
** init Feature
*/

void			init_game(t_env *e);
void			init_sprite(t_env *e);
void			load_texture(t_env *e);

/*
** Draw Feature
*/

int				draw(t_env *e);
void			draw_wolf(t_env *e);
void			draw_limiter(t_env *e);
void			draw_sky(t_env *e);
void			draw_wall(t_env *e);
void			draw_ground(t_env *e);
void			draw_sprite(t_env *e);
void			relive_sprite(t_env *e);
void			pixel_coord_img(t_img *img, int x, int y, t_color *c);
void			get_img_color(t_img *img, int x, int y, t_color *c);

void			draw_weapon(t_env *e);
void			sprite_order(t_env *e, int *spriteorder);
void			calc_sprite_place(t_draw *draw, t_calspr *spr);
void			calc_const_sprite(t_dpoint transf, t_calspr *spr);
void			calc_transf(t_env *e, t_dpoint *transf, t_dpoint spr);
void			hit_sprite(t_env *e, t_sprite *sprite);
int				last_sprite(t_env *e, int *spriteorder, int current);
void			shoot_animation(t_env *e);

void			fish_eye_corrector(t_env *e, int bool_on);

void			ft_swap_double(double *a, double *b);
void			ft_swap_int(int *a, int *b);

int				read_file(char *file, t_env *e);

void			get_timeframe(t_env *e);
void			debbug_tool(t_env *e);
void			my_position(t_env *e);
void			dy(t_env *e, t_point *te, t_calspr *o, t_dpoint *t);
#endif
