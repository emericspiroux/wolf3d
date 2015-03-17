/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espiroux <espiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 16:41:26 by espiroux          #+#    #+#             */
/*   Updated: 2015/03/03 19:33:27 by espiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int			text_cur_anim(t_env *e, int *spriteorder, int i)
{
	if (e->sprite[spriteorder[i]].rip == 0
		&& e->sprite[spriteorder[i]].hit == 1)
		return (e->sprite[spriteorder[i]].texture_hit);
	else if (e->sprite[spriteorder[i]].rip == 1)
		return (e->sprite[spriteorder[i]].texture_death);
	else
		return (e->sprite[spriteorder[i]].texture);
}

void				draw_sprite(t_env *e)
{
	t_dpoint		spr;
	t_dpoint		transf;
	t_point			tex;
	t_calspr		ospr;

	sprite_order(e, e->spriteorder);
	e->draw.i = 0;
	while (e->draw.i < NUMSPRITES)
	{
		spr.x = e->sprite[e->spriteorder[e->draw.i]].x - e->move.posx;
		spr.y = e->sprite[e->spriteorder[e->draw.i]].y - e->move.posy;
		calc_transf(e, &transf, spr);
		calc_const_sprite(transf, &ospr);
		calc_sprite_place(&e->draw, &ospr);
		e->draw.sprite_state = text_cur_anim(e, e->spriteorder, e->draw.i);
		dy(e, &tex, &ospr, &transf);
		e->draw.i++;
	}
}
