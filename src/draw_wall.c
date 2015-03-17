/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espiroux <espiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 16:41:26 by espiroux          #+#    #+#             */
/*   Updated: 2015/03/03 19:44:18 by espiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		wall_x_calc(t_ray *r, t_map *m, double *wallx)
{
	double		calc;

	if (r->side == 1)
	{
		calc = (m->mapy - r->rayposy + (1 - r->stepy) / 2) / r->raydiry;
		*wallx = r->rayposx + calc * r->raydirx;
	}
	else
	{
		calc = ((m->mapx - r->rayposx + (1 - r->stepx) / 2) / r->raydirx);
		*wallx = r->rayposy + calc * r->raydiry;
	}
}

static int		tex_x_coord(t_env *e, t_img *tex, double wallx)
{
	int			save_texx;

	wallx -= floor((wallx));
	e->ray.wallx = wallx;
	save_texx = (int)(wallx * (double)(tex->width));
	if ((e->ray.side == 0 && e->ray.raydirx > 0)
		|| (e->ray.side == 1 && e->ray.raydiry < 0))
		return (tex->width - save_texx - 1);
	return (save_texx);
}

static void		greyer(t_color *c)
{
	double		sha;

	sha = 0.50;
	(c->red > 0 && c->red < 255) ? c->red -= (c->red * sha) : c->red;
	(c->green > 0 && c->green < 255) ? c->green -= (c->green * sha) : c->green;
	(c->blue > 0 && c->blue < 255) ? c->blue -= (c->blue * sha) : c->blue;
	c->red = (c->red > 0) ? c->red : 0;
	c->red = (c->red < 255) ? c->red : 255;
	c->green = (c->green > 0) ? c->green : 0;
	c->green = (c->green < 255) ? c->green : 255;
	c->blue = (c->blue > 0) ? c->blue : 0;
	c->blue = (c->blue < 255) ? c->blue : 255;
}

void			draw_wall(t_env *e)
{
	t_point		tex;
	t_color		c;
	int			d;
	int			texnum;
	double		wallx;

	texnum = e->map.map[e->map.mapx][e->map.mapy] - 1;
	wall_x_calc(&e->ray, &e->map, &wallx);
	tex.x = tex_x_coord(e, &e->tex[texnum], wallx);
	e->ray.y = e->ray.drawstart;
	while (e->ray.y < e->ray.drawend)
	{
		d = e->ray.y * 256 - WINHEIGHT * 128 + e->ray.lineheight * 128;
		tex.y = (int)(((d * e->tex[texnum].height) / e->ray.lineheight) / 256);
		get_img_color(&e->tex[texnum], tex.x, tex.y, &c);
		if (e->ray.side == 0 && e->ray.stepx == -1)
			greyer(&c);
		pixel_coord_img(&e->image, e->ray.x, e->ray.y, &c);
		e->ray.y++;
	}
}
