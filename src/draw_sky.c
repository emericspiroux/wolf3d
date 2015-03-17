/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sky.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espiroux <espiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 16:41:26 by espiroux          #+#    #+#             */
/*   Updated: 2015/03/03 19:43:08 by espiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void					draw_sky(t_env *e)
{
	int					sky_y;
	int					sky_y_img;
	static int			sky_x_img = 0;
	t_color				c_tex;

	sky_y = 0;
	sky_y_img = 0;
	if (sky_x_img >= e->sky.width)
		sky_x_img = 0;
	while (sky_y < e->ray.drawstart)
	{
		if (e->sky.height <= sky_y_img)
			sky_y_img = 0;
		get_img_color(&e->sky, sky_x_img, sky_y_img, &c_tex);
		pixel_coord_img(&e->image, e->ray.x, sky_y, &c_tex);
		sky_y++;
		sky_y_img++;
	}
	sky_x_img++;
}
