/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_coor_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espiroux <espiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 16:41:26 by espiroux          #+#    #+#             */
/*   Updated: 2015/03/03 18:41:16 by espiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		pixel_coord_img(t_img *img, int x, int y, t_color *c)
{
	img->pimg[y * img->sline + x * (img->bpp / 8) + 2] = c->red;
	img->pimg[y * img->sline + x * (img->bpp / 8)] = c->green;
	img->pimg[y * img->sline + x * (img->bpp / 8) + 1] = c->blue;
}
