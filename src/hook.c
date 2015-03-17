/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espiroux <espiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/11 12:00:30 by espiroux          #+#    #+#             */
/*   Updated: 2015/03/13 15:57:49 by espiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		key_press(int keycode, t_env *e)
{
	if (keycode == 47 && e->debbug != 1)
		e->debbug = 1;
	move_key(keycode, e, 1);
	if (keycode == 49)
		e->move.weapon = 0;
	else if (keycode == 50)
		e->move.weapon = 1;
	if (keycode == 32)
		e->move.shoot = 1;
	if (keycode == 99 && e->map.sky == 0)
		e->map.sky = 1;
	else if (keycode == 99)
		e->map.sky = 0;
	if (keycode == 65307)
		exit(0);
	if (keycode == 114)
		relive_sprite(e);
	return (0);
}

void	my_position(t_env *e)
{
	ft_putstr("Vos Coordonnees : ");
	ft_putnbr(e->move.posx);
	ft_putchar(',');
	ft_putnbr(e->move.posy);
	ft_putstr("\n");
}

int		key_release(int keycode, t_env *e)
{
	move_key(keycode, e, 0);
	if (keycode == 32)
		e->move.shoot = 0;
	return (0);
}

void	debbug_tool(t_env *e)
{
	if (e->debbug == 1)
	{
		ft_putchar('\n');
		my_position(e);
		e->debbug = 0;
	}
}

void	relive_sprite(t_env *e)
{
	int i;

	i = 0;
	while (i < NUMSPRITES)
	{
		e->sprite[i].life = 100;
		e->sprite[i].rip = 0;
		i++;
	}
}
