/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espiroux <espiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 16:41:26 by espiroux          #+#    #+#             */
/*   Updated: 2015/03/03 19:37:07 by espiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		fish_eye_corrector(t_env *e, int bool_on)
{
	double calc;

	if (e->ray.side == 0 && bool_on)
	{
		calc = (e->map.mapx - e->ray.rayposx + (1 - e->ray.stepx) / 2);
		calc = calc / e->ray.raydirx;
		e->ray.perpwalldist = fabs(calc);
	}
	else if (bool_on)
	{
		calc = (e->map.mapy - e->ray.rayposy + (1 - e->ray.stepy) / 2);
		calc = calc / e->ray.raydiry;
		e->ray.perpwalldist = fabs(calc);
	}
	if (bool_on)
		e->ray.lineheight = abs((int)(WINHEIGHT / e->ray.perpwalldist));
	else
		e->ray.lineheight = abs((int)(WINHEIGHT / 1));
}
