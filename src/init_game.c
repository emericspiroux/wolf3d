/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espiroux <espiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/11 11:34:03 by espiroux          #+#    #+#             */
/*   Updated: 2015/03/13 15:58:24 by espiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		init_player(t_env *e)
{
	e->score = 0;
	e->move.planex = 0;
	e->move.planey = 0.66;
	e->move.posx = 12;
	e->move.posy = 12;
	e->move.dirx = 1;
	e->move.diry = 0;
	e->move.movespeed = 0.3;
	e->move.rotspeed = 0.05;
	e->move.weapon = 0;
	e->move.step_shoot = 0;
}

static void		init_weapon(t_env *e)
{
	e->weap_info[0].power = 10;
	e->weap_info[1].power = 30;
}

void			init_game(t_env *e)
{
	init_player(e);
	init_weapon(e);
	init_sprite(e);
}
