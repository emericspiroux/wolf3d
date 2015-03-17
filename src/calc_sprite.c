/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espiroux <espiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 16:41:26 by espiroux          #+#    #+#             */
/*   Updated: 2015/03/03 19:50:17 by espiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		calc_sprite_place(t_draw *draw, t_calspr *spr)
{
	draw->start.y = -spr->h / 2 + WINHEIGHT / 2;
	if (draw->start.y < 0)
		draw->start.y = 0;
	draw->end.y = spr->h / 2 + WINHEIGHT / 2;
	if (draw->end.y >= WINHEIGHT)
		draw->end.y = WINHEIGHT - 1;
	draw->start.x = -spr->w / 2 + spr->scx;
	if (draw->start.x < 0)
		draw->start.x = 0;
	draw->end.x = spr->w / 2 + spr->scx;
	if (draw->end.x >= WINWIDTH)
		draw->end.x = WINWIDTH - 1;
}
