/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 15:33:42 by hlarson           #+#    #+#             */
/*   Updated: 2019/12/28 15:56:14 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		live(t_parse *flags, t_carret *carret, size_t cycle)
{
	size_t			i;
	int				k;
	int				j;

	k = DIR_SIZE;
	i = carret->pos + 1;
	if (i >= MEM_SIZE)
		i %= MEM_SIZE;
	carret->movement += k + 1;
	(flags->live)++;
	j = get_dir_one(flags->map, &i);
	carret->live = 1;
	carret->live_last = cycle;
	if ((int)(-(carret->number)) == j)
		flags->last_alive = carret->number;
}
