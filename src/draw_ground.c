/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ground.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espiroux <espiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 16:41:26 by espiroux          #+#    #+#             */
/*   Updated: 2015/03/03 19:47:35 by espiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		floor_calc(t_env *e, t_dpoint *floorw, t_point *floortex)
{
	t_dpoint	currentfloor;
	double		currentdist;
	double		weight;

	currentdist = WINHEIGHT / (2.0 * e->ray.y - WINHEIGHT);
	weight = (currentdist - e->move.distp) / (e->move.distw - e->move.distp);
	currentfloor.x = weight * floorw->x + (1.0 - weight) * e->move.posx;
	currentfloor.y = weight * floorw->y + (1.0 - weight) * e->move.posy;
	floortex->x = (int)(currentfloor.x * e->tex[3].width) % e->tex[3].width;
	floortex->y = (int)(currentfloor.y * e->tex[3].height) % e->tex[3].height;
}

static void		draw_celling(t_env *e, t_point *floortex, t_color *c_fl)
{
	if (e->map.sky == 1)
	{
		get_img_color(&e->tex[3], floortex->x, floortex->y, c_fl);
		pixel_coord_img(&e->image, e->ray.x, (WINHEIGHT - e->ray.y), c_fl);
	}
}

static void		dir_wall_calc(t_env *e, t_dpoint *floorwall)
{
	if (e->ray.side == 0 && e->ray.raydirx > 0)
	{
		floorwall->x = e->map.mapx;
		floorwall->y = e->map.mapy + e->ray.wallx;
	}
	else if (e->ray.side == 0 && e->ray.raydirx < 0)
	{
		floorwall->x = e->map.mapx + 1.0;
		floorwall->y = e->map.mapy + e->ray.wallx;
	}
	else if (e->ray.side == 1 && e->ray.raydiry > 0)
	{
		floorwall->x = e->map.mapx + e->ray.wallx;
		floorwall->y = e->map.mapy;
	}
	else
	{
		floorwall->x = e->map.mapx + e->ray.wallx;
		floorwall->y = e->map.mapy + 1.0;
	}
}

void			draw_ground(t_env *e)
{
	t_dpoint	floorwall;
	t_point		floortex;
	t_color		c_fl;

	e->zbuffer[e->ray.x] = e->ray.perpwalldist;
	dir_wall_calc(e, &floorwall);
	if (e->ray.drawend < 0)
		e->ray.drawend = WINHEIGHT;
	e->move.distw = e->ray.perpwalldist;
	e->move.distp = 0.0;
	e->ray.y++;
	while (e->ray.y < WINHEIGHT)
	{
		floor_calc(e, &floorwall, &floortex);
		get_img_color(&e->tex[3], floortex.x, floortex.y, &c_fl);
		pixel_coord_img(&e->image, e->ray.x, e->ray.y, &c_fl);
		draw_celling(e, &floortex, &c_fl);
		e->ray.y++;
	}
}
