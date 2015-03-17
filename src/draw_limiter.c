/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_limiter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espiroux <espiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 16:41:26 by espiroux          #+#    #+#             */
/*   Updated: 2015/03/03 19:43:17 by espiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		draw_limiter(t_env *e)
{
	e->ray.drawstart = -e->ray.lineheight / 2 + WINHEIGHT / 2;
	if (e->ray.drawstart < 0)
		e->ray.drawstart = 0;
	e->ray.drawend = e->ray.lineheight / 2 + WINHEIGHT / 2;
	if (e->ray.drawend >= WINHEIGHT)
		e->ray.drawend = WINHEIGHT - 1;
}
