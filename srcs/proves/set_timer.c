/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_timer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 16:17:07 by hlarson           #+#    #+#             */
/*   Updated: 2019/12/28 16:26:34 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	help_helper_set(t_carret *carret, t_parse *flags)
{
	if ((flags->color)[carret->pos] != 200
			&& (flags->color)[carret->pos] != 0)
		(flags->color)[carret->pos] /= 10;
	else
		(flags->color)[carret->pos] = 0;
	carret->pos += 1;
	if (carret->pos >= MEM_SIZE)
		carret->pos %= MEM_SIZE;
	carret->timer = 0;
	(carret->movement) = 0;
}

void	help_set_timer(t_carret *carret, t_parse *flags, unsigned char c)
{
	if (c == 10)
		carret->timer = 25;
	else if (c == 11)
		carret->timer = 25;
	else if (c == 12)
		carret->timer = 800;
	else if (c == 13)
		carret->timer = 10;
	else if (c == 14)
		carret->timer = 50;
	else if (c == 15)
		carret->timer = 1000;
	else if (c == 16)
		carret->timer = 2;
	else
		help_helper_set(carret, flags);
}

void	set_timer(t_carret *carret, t_parse *flags)
{
	unsigned char	c;

	c = (flags->map)[carret->pos];
	carret->op = c;
	if (c == 1)
		carret->timer = 10;
	else if (c == 2)
		carret->timer = 5;
	else if (c == 3)
		carret->timer = 5;
	else if (c == 4)
		carret->timer = 10;
	else if (c == 5)
		carret->timer = 10;
	else if (c == 6)
		carret->timer = 6;
	else if (c == 7)
		carret->timer = 6;
	else if (c == 8)
		carret->timer = 6;
	else if (c == 9)
		carret->timer = 20;
	else
		help_set_timer(carret, flags, c);
	carret->movement = (c >= 1 && c <= 16) ? 1 : 0;
}
