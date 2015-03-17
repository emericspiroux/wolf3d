/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_img_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espiroux <espiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 16:41:26 by espiroux          #+#    #+#             */
/*   Updated: 2015/03/03 18:27:36 by espiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		get_img_color(t_img *tex, int x, int y, t_color *c)
{
	c->red = tex->pimg[y * tex->sline + x * (tex->bpp / 8) + 2];
	c->green = tex->pimg[y * tex->sline + x * (tex->bpp / 8)];
	c->blue = tex->pimg[y * tex->sline + x * (tex->bpp / 8) + 1];
}
