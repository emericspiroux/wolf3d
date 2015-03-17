/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espiroux <espiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/11 11:34:03 by espiroux          #+#    #+#             */
/*   Updated: 2015/03/17 17:13:43 by espiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3D.h"

int				main(void)
{
	t_env		e;

	if (!(e.mlx = mlx_init()))
		return (EXIT_FAILURE);
	if (!(e.win = mlx_new_window(e.mlx, WINWIDTH, WINHEIGHT, "Wolf 3D")))
		return (EXIT_FAILURE);
	load_texture(&e);
	init_game(&e);
	if (read_file("map/lvl1.map", &e) == -1)
	{
		ft_putstr("Error Reading Map\n");
		exit(0);
	}
	mlx_loop_hook(e.mlx, &draw, &e);
	mlx_hook(e.win, 2, (1L << 0), &key_press, &e);
	mlx_hook(e.win, 3, (1L << 1), &key_release, &e);
	mlx_loop(e.mlx);
	return (0);
}
