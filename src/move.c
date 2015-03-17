/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espiroux <espiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/11 12:00:30 by espiroux          #+#    #+#             */
/*   Updated: 2015/03/03 19:35:26 by espiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int					move_player(t_env *e)
{
	if (e->move.top == 1)
		move_walk(e, 't');
	if (e->move.bottom == 1)
		move_walk(e, 'b');
	if (e->move.left == 1)
		move_side(e, 'l');
	if (e->move.right == 1)
		move_side(e, 'r');
	return (0);
}

void				move_side(t_env *e, char s)
{
	double	olddirx;
	double	oldplanex;
	double	rspd;

	olddirx = e->move.dirx;
	if (s == 'L' || s == 'l')
		rspd = -e->move.rotspeed;
	else
		rspd = e->move.rotspeed;
	e->move.dirx = e->move.dirx * cos(rspd) - e->move.diry * sin(rspd);
	e->move.diry = olddirx * sin(rspd) + e->move.diry * cos(rspd);
	oldplanex = e->move.planex;
	e->move.planex = e->move.planex * cos(rspd) - e->move.planey * sin(rspd);
	e->move.planey = oldplanex * sin(rspd) + e->move.planey * cos(rspd);
}

void				move_walk(t_env *e, char s)
{
	int	mapx;
	int	mapy;

	mapx = 0;
	mapy = 0;
	if (s == 'B' || s == 'b')
	{
		mapx = (int)(e->move.posx - e->move.dirx * e->move.movespeed);
		mapy = (int)(e->move.posy - e->move.diry * e->move.movespeed);
		if (e->map.map[mapx][(int)(e->move.posy)] == 0)
			e->move.posx -= e->move.dirx * e->move.movespeed;
		if (e->map.map[(int)(e->move.posx)][mapy] == 0)
			e->move.posy -= e->move.diry * e->move.movespeed;
	}
	else
	{
		mapx = (int)(e->move.posx + e->move.dirx * e->move.movespeed);
		mapy = (int)(e->move.posy + e->move.diry * e->move.movespeed);
		if (e->map.map[mapx][(int)(e->move.posy)] == 0)
			e->move.posx += e->move.dirx * e->move.movespeed;
		if (e->map.map[(int)(e->move.posx)][mapy] == 0)
			e->move.posy += e->move.diry * e->move.movespeed;
	}
}

void				move_key(int keycode, t_env *e, int etat)
{
	if (keycode == 65363 || keycode == 100)
		e->move.right = etat;
	else if (keycode == 65361 || keycode == 97)
		e->move.left = etat;
	if (keycode == 65364 || keycode == 115)
		e->move.bottom = etat;
	else if (keycode == 65362 || keycode == 119)
		e->move.top = etat;
}
