/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shoot_animation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espiroux <espiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 16:41:26 by espiroux          #+#    #+#             */
/*   Updated: 2015/03/03 18:43:40 by espiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void						shoot_animation(t_env *e)
{
	static unsigned int		i;
	static unsigned int		mem_anim;

	if (i++ >= TIME_SHOOT_ANIM)
	{
		if ((mem_anim == 0) && e->move.shoot == 1)
			e->move.step_shoot = 1;
		if (mem_anim == 1 && e->move.shoot == 1)
			e->move.step_shoot += 1;
		if (mem_anim == 1 && e->move.shoot == 0)
			e->move.step_shoot = 0;
		if (mem_anim == 2 && e->move.shoot == 1)
			e->move.step_shoot -= 1;
		if (mem_anim == 2 && e->move.shoot == 0)
			e->move.step_shoot = 1;
		if (e->move.shoot == 0)
			e->move.step_shoot = 0;
		mem_anim = e->move.step_shoot;
	}
	if (i > TIME_SHOOT_ANIM)
		i = 0;
}
