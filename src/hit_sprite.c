/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sprite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espiroux <espiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 16:41:26 by espiroux          #+#    #+#             */
/*   Updated: 2015/03/03 18:29:48 by espiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void hit_sprite(t_env *e, t_sprite *sprite)
{
	if (e->move.step_shoot == 2)
	{
		sprite->hit = 1;
		if (sprite->life > 0)
		{
			sprite->hit = 1;
			sprite->life -= e->weap_info[e->move.weapon].power;
		}
		else
			sprite->rip = 1;
	}
}
