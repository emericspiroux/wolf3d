/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_transf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espiroux <espiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 16:41:26 by espiroux          #+#    #+#             */
/*   Updated: 2015/03/03 19:35:24 by espiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		calc_transf(t_env *e, t_dpoint *transf, t_dpoint spr)
{
	double		inv_det;
	double		cal_det;

	cal_det = (e->move.planex * e->move.diry - e->move.dirx * e->move.planey);
	inv_det = 1.0 / cal_det;
	transf->x = inv_det * (e->move.diry * spr.x - e->move.dirx * spr.y);
	transf->y = inv_det * (-e->move.planey * spr.x + e->move.planex * spr.y);
}
