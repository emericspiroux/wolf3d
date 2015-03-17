/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_weapon.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espiroux <espiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 16:41:26 by espiroux          #+#    #+#             */
/*   Updated: 2015/03/03 18:18:49 by espiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		calc_weapon_place(t_img *img, t_point *start, t_point *end)
{
	start->x = (WINWIDTH / 2) - (img->width / 2);
	end->x = start->x + img->width;
	start->y = WINHEIGHT - img->height;
	end->y = WINHEIGHT - TOPED_WEAPON;
}

void			draw_weapon(t_env *e)
{
	t_draw		draw;
	t_point		brush;
	t_point		put_c;
	t_color		c_wea;
	t_img		*wea_img;

	wea_img = &e->weap[e->move.weapon][e->move.step_shoot];
	calc_weapon_place(wea_img, &draw.start, &draw.end);
	brush.x = 0;
	while ((brush.x + draw.start.x) < draw.end.x)
	{
		brush.y = 0;
		while ((brush.y + draw.start.y) < draw.end.y)
		{
			put_c.y = brush.y + TOPED_WEAPON + draw.start.y;
			put_c.x = brush.x + LEFTED_WEAPON + draw.start.x;
			get_img_color(wea_img, brush.x, brush.y, &c_wea);
			if (c_wea.red != 0 && c_wea.green != 0 && c_wea.blue != 0)
				pixel_coord_img(&e->image, put_c.x, put_c.y, &c_wea);
			brush.y++;
		}
		brush.x++;
	}
}
