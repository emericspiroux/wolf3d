/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espiroux <espiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/11 12:00:30 by espiroux          #+#    #+#             */
/*   Updated: 2015/03/04 11:06:24 by espiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		key_release(int keycode, t_env *e)
{
	move_key(keycode, e, 0);
	if (keycode == 32)
		e->move.shoot = 0;
	return (0);
}
