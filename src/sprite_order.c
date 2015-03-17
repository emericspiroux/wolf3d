/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_order.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espiroux <espiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 16:41:26 by espiroux          #+#    #+#             */
/*   Updated: 2015/03/03 19:32:50 by espiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static	void	how_gap(int *gap)
{
	*gap = (*gap * 10) / 13;
	if (*gap == 9 || *gap == 10)
		*gap = 11;
	if (*gap < 1)
		*gap = 1;
}

static void		sprite_sort(int *order, double *dist, int amount)
{
	int			gap;
	int			swapped;
	int			i;
	int			j;

	gap = amount;
	swapped = 0;
	while (gap > 1 || swapped)
	{
		how_gap(&gap);
		swapped = 0;
		i = 0;
		while (i < amount - gap)
		{
			j = i + gap;
			if (dist[i] < dist[j])
			{
				ft_swap_double(&dist[i], &dist[j]);
				ft_swap_int(&order[i], &order[j]);
				swapped = 1;
			}
			i++;
		}
	}
}

void			sprite_order(t_env *e, int *spriteorder)
{
	double		spritedistance[NUMSPRITES];
	int			i;
	double		calc_a;
	double		calc_b;

	i = 0;
	while (i < NUMSPRITES)
	{
		spriteorder[i] = i;
		calc_a = (e->move.posx - e->sprite[i].x);
		calc_a = calc_a * (e->move.posx - e->sprite[i].x);
		calc_b = (e->move.posy - e->sprite[i].y);
		calc_b = calc_b * (e->move.posy - e->sprite[i].y);
		spritedistance[i] = (calc_a + calc_b);
		i++;
	}
	sprite_sort(spriteorder, spritedistance, NUMSPRITES);
}
