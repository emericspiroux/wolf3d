/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wolf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espiroux <espiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 16:41:26 by espiroux          #+#    #+#             */
/*   Updated: 2015/03/04 11:51:34 by espiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	draw_math_dist(t_env *e, double *camerax)
{
	double calcx;
	double calcy;

	*camerax = 2 * e->ray.x / (double)(WINWIDTH) - 1;
	e->ray.rayposx = e->move.posx;
	e->ray.rayposy = e->move.posy;
	e->ray.raydirx = e->move.dirx + e->move.planex * *camerax;
	e->ray.raydiry = e->move.diry + e->move.planey * *camerax;
	calcx = (e->ray.raydirx * e->ray.raydirx);
	calcy = (e->ray.raydiry * e->ray.raydiry);
	e->map.mapx = (int)(e->ray.rayposx);
	e->map.mapy = (int)(e->ray.rayposy);
	e->ray.deltadistx = sqrt(1 + (e->ray.raydiry * e->ray.raydiry) / calcx);
	e->ray.deltadisty = sqrt(1 + (e->ray.raydirx * e->ray.raydirx) / calcy);
}

static void	draw_step_side_dist(t_env *e)
{
	double calc;

	if (e->ray.raydirx < 0)
	{
		e->ray.stepx = -1;
		e->ray.sidedistx = (e->ray.rayposx - e->map.mapx) * e->ray.deltadistx;
	}
	else
	{
		calc = e->map.mapx + 1.0 - e->ray.rayposx;
		e->ray.stepx = 1;
		e->ray.sidedistx = calc * e->ray.deltadistx;
	}
	if (e->ray.raydiry < 0)
	{
		e->ray.stepy = -1;
		e->ray.sidedisty = (e->ray.rayposy - e->map.mapy) * e->ray.deltadisty;
	}
	else
	{
		calc = (e->map.mapy + 1.0 - e->ray.rayposy);
		e->ray.stepy = 1;
		e->ray.sidedisty = calc * e->ray.deltadisty;
	}
}

static void draw_ray_hit(t_env *e)
{
	e->ray.hit = 0;
	while (e->ray.hit == 0)
	{
		if (e->ray.sidedistx < e->ray.sidedisty)
		{
			e->ray.sidedistx += e->ray.deltadistx;
			e->map.mapx += e->ray.stepx;
			e->ray.side = 0;
		}
		else
		{
			e->ray.sidedisty += e->ray.deltadisty;
			e->map.mapy += e->ray.stepy;
			e->ray.side = 1;
		}
		if (e->map.map[e->map.mapx][e->map.mapy] > 0)
			e->ray.hit = 1;
	}
}

void		draw_wolf(t_env *e)
{
	double				camerax;

	e->ray.x = 0;
	while (e->ray.x < WINWIDTH)
	{
		draw_math_dist(e, &camerax);
		draw_step_side_dist(e);
		draw_ray_hit(e);
		fish_eye_corrector(e, 1);
		draw_limiter(e);
		draw_sky(e);
		draw_wall(e);
		draw_ground(e);
		e->ray.x++;
	}
	draw_sprite(e);
	draw_weapon(e);
}
