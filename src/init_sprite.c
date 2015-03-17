/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espiroux <espiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/11 11:34:03 by espiroux          #+#    #+#             */
/*   Updated: 2015/03/03 18:37:25 by espiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void			init_sprite_coord(t_sprite *s, double x, double y, int life)
{
	s->x = x;
	s->y = y;
	s->life = life;
}

static void			init_sprite_texture(t_sprite *s, int tex, int ted, int teh)
{
	s->texture = tex;
	s->texture_death = ted;
	s->texture_hit = teh;
	s->rip = 0;
	s->hit = 0;
}

void				init_sprite(t_env *e)
{
	init_sprite_coord(&e->sprite[0], 11, 11, 100);
	init_sprite_texture(&e->sprite[0], 4, 6, 7);
	init_sprite_coord(&e->sprite[1], 10, 10, 100);
	init_sprite_texture(&e->sprite[1], 4, 6, 7);
	init_sprite_coord(&e->sprite[2], 1.5, 1.5, 100);
	init_sprite_texture(&e->sprite[2], 4, 6, 7);
	init_sprite_coord(&e->sprite[3], 17.5, 2, 100);
	init_sprite_texture(&e->sprite[3], 5, 12, 11);
	init_sprite_coord(&e->sprite[4], 17.5, 3, 100);
	init_sprite_texture(&e->sprite[4], 5, 12, 11);
	init_sprite_coord(&e->sprite[5], 17.5, 4, 100);
	init_sprite_texture(&e->sprite[5], 5, 12, 11);
	init_sprite_coord(&e->sprite[6], 20, 3, 1000);
	init_sprite_texture(&e->sprite[6], 8, 10, 9);
}
