/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espiroux <espiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 16:41:26 by espiroux          #+#    #+#             */
/*   Updated: 2015/03/04 12:34:35 by espiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		open_texture(t_env *e, t_img *tex, char *name)
{
	tex->img = mlx_xpm_file_to_image(e->mlx, name, &tex->width, &tex->height);
	tex->pimg = mlx_get_data_addr(tex->img, &tex->bpp, &tex->sline, &tex->endi);
}

void			load_texture(t_env *e)
{
	open_texture(e, &e->tex[0], "text/wall/normal.xpm");
	open_texture(e, &e->tex[1], "text/wall/normalalt3.xpm");
	open_texture(e, &e->tex[2], "text/wall/normalalt2.xpm");
	open_texture(e, &e->tex[3], "text/wall/floor.xpm");
	open_texture(e, &e->tex[4], "text/object/barrel.xpm");
	open_texture(e, &e->tex[5], "text/object/pillar.xpm");
	open_texture(e, &e->tex[6], "text/object/barrel_rip.xpm");
	open_texture(e, &e->tex[7], "text/object/barrel_hit.xpm");
	open_texture(e, &e->tex[12], "text/object/pillar_rip.xpm");
	open_texture(e, &e->tex[11], "text/object/pillar_hit.xpm");
	open_texture(e, &e->tex[8], "text/enemy/enemy00.xpm");
	open_texture(e, &e->tex[9], "text/enemy/enemy01.xpm");
	open_texture(e, &e->tex[10], "text/enemy/enemy02.xpm");
	open_texture(e, &e->weap[0][0], "text/weapon10.xpm");
	open_texture(e, &e->weap[0][1], "text/weapon11.xpm");
	open_texture(e, &e->weap[0][2], "text/weapon12.xpm");
	open_texture(e, &e->weap[1][0], "text/weapon20.xpm");
	open_texture(e, &e->weap[1][1], "text/weapon21.xpm");
	open_texture(e, &e->weap[1][2], "text/weapon22.xpm");
	open_texture(e, &e->sky, "text/skybox12.xpm");
}
