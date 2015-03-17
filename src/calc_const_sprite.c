/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_const_sprite.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espiroux <espiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 16:41:26 by espiroux          #+#    #+#             */
/*   Updated: 2015/03/03 19:49:53 by espiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		calc_const_sprite(t_dpoint transf, t_calspr *spr)
{
	spr->scx = (int)((WINWIDTH / 2) * (1 + transf.x / transf.y));
	spr->h = abs((int)(WINHEIGHT / (transf.y)));
	spr->w = abs((int)(WINWIDTH / (transf.y)));
}
