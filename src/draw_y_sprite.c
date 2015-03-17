/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_y_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espiroux <espiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 16:41:26 by espiroux          #+#    #+#             */
/*   Updated: 2015/03/03 19:49:07 by espiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		on_shoot_sprite(t_env *e, t_point pt, int *spriteorder, int i)
{
	if (pt.x == WINWIDTH / 2
	&& pt.y == WINHEIGHT / 2
	&& e->move.step_shoot == 2
	&& e->sprite[spriteorder[i]].rip == 0)
		hit_sprite(e, &e->sprite[spriteorder[i]]);
	else if (e->move.step_shoot != 2)
		e->sprite[spriteorder[i]].hit = 0;
}

void			dy(t_env *e, t_point *te, t_calspr *o, t_dpoint *t)
{
	int			di;
	t_point		pt;
	t_color		c_spr;

	pt.x = e->draw.start.x;
	while (pt.x < e->draw.end.x)
	{
		te->x = (int)(256 * (pt.x - (-o->w / 2 + o->scx))
		* e->tex[e->sprite[e->spriteorder[e->draw.i]].texture].width / o->w)
		/ 256;
		pt.y = e->draw.start.y;
		while (pt.y < e->draw.end.y
				&& t->y > 0
				&& pt.x > 0 && pt.x < WINWIDTH && t->y < e->zbuffer[pt.x])
		{
			di = pt.y * 256 - WINHEIGHT * 128 + o->h * 128;
			te->y = ((di * e->tex[e->draw.sprite_state].height) / o->h) / 256;
			get_img_color(&e->tex[e->draw.sprite_state], te->x, te->y, &c_spr);
			if (c_spr.red != 0 || c_spr.green != 0 || c_spr.blue != 0)
				pixel_coord_img(&e->image, pt.x, pt.y, &c_spr);
			on_shoot_sprite(e, pt, e->spriteorder, e->draw.i);
			pt.y++;
		}
		pt.x++;
	}
}
