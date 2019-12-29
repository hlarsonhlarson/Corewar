/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 21:01:49 by hlarson           #+#    #+#             */
/*   Updated: 2019/12/28 15:19:19 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			op_add(t_parse *flags, t_carret *carret)
{
	size_t		i;
	int			args_byte;
	int			reg_1;
	int			reg_2;
	int			reg_3;

	i = carret->pos + 2;
	i = (i >= MEM_SIZE) ? i % MEM_SIZE : i;
	args_byte = i - 1;
	set_movement(carret, flags->map[args_byte], 3, 4);
	if (what_arg((flags->map)[args_byte] >> 6) != 1)
		return ;
	if ((reg_1 = get_reg(flags->map, &i)) < 1 || reg_1 > 16)
		return ;
	if (what_arg(((flags->map)[args_byte] & 0x30) >> 4) != 1)
		return ;
	if ((reg_2 = get_reg(flags->map, &i)) < 1 || reg_2 > 16)
		return ;
	if (what_arg(((flags->map)[args_byte] & 0x3f) >> 2) != 1)
		return ;
	if ((reg_3 = get_reg(flags->map, &i)) < 1 || reg_3 > 16)
		return ;
	(carret->reg)[reg_3 - 1] = (carret->reg)[reg_2 - 1] +
		(carret->reg)[reg_1 - 1];
	carret->carry = ((carret->reg)[reg_3 - 1] != 0) ? 0 : 1;
}
