/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_and_do.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 19:21:55 by hlarson           #+#    #+#             */
/*   Updated: 2019/12/12 19:22:33 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	help_move_and_do(t_carret *carret, t_parse *flags)
{
	if (carret->op == 9)
		zjmp(carret, flags->map);
	else if (carret->op == 10)
		ldi(flags, carret);
	else if (carret->op == 11)
		sti(flags, carret);
	else if (carret->op == 12)
		op_fork(flags, carret);
	else if (carret->op == 13)
		lld(flags, carret);
	else if (carret->op == 14)
		lldi(flags, carret);
	else if (carret->op == 15)
		op_lfork(flags, carret);
	else if (carret->op == 16)
		aff(flags, carret);
	return (0);
}

int	move_and_do(t_carret *carret, size_t i, t_parse *flags)
{
	if (carret->op == 1)
		live(flags, carret, i);
	else if (carret->op == 2)
		ld(flags, carret);
	else if (carret->op == 3)
		st(flags, carret);
	else if (carret->op == 4)
		op_add(flags, carret);
	else if (carret->op == 5)
		op_sub(flags, carret);
	else if (carret->op == 6)
		op_and(flags, carret);
	else if (carret->op == 7)
		op_or(flags, carret);
	else if (carret->op == 8)
		op_xor(flags, carret);
	else
		help_move_and_do(carret, flags);
	return (0);
}
