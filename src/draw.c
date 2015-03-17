/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espiroux <espiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 16:41:26 by espiroux          #+#    #+#             */
/*   Updated: 2015/03/04 11:48:17 by espiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	load_img_game(t_img *img, void *img_ptr)
{
	img->pimg = mlx_get_data_addr(img_ptr, &img->bpp, &img->sline, &img->endi);
}

int			draw(t_env *e)
{
	if (e->image.img != NULL)
	{
		mlx_destroy_image(e->mlx, e->image.img);
		e->image.img = NULL;
	}
	e->image.img = mlx_new_image(e->mlx, WINWIDTH, WINHEIGHT);
	load_img_game(&e->image, e->image.img);
	draw_wolf(e);
	move_player(e);
	shoot_animation(e);
	debbug_tool(e);
	get_timeframe(e);
	mlx_put_image_to_window(e->mlx, e->win, e->image.img, 0, 0);
	return (0);
}
