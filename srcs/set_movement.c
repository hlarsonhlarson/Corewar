/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_movement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 20:16:14 by hlarson           #+#    #+#             */
/*   Updated: 2019/12/28 15:59:40 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

#include "corewar.h"

static void	help_set_movement(t_carret *carret, unsigned char c, int dir_size)
{
	if ((c & 0xc) >> 2 == T_DIR)
		carret->movement += dir_size;
	else if ((c & 0xc) >> 2 == T_REG)
		carret->movement += 1;
	else if ((c & 0xc) >> 2 == T_IND)
		carret->movement += 2;
	else
		carret->movement += 0;
}

void		set_movement(t_carret *carret, unsigned char c,
		int num_args, int dir_size)
{
	carret->movement += 2;
	if (c >> 6 == T_DIR)
		carret->movement += dir_size;
	else if (c >> 6 == T_REG)
		carret->movement += 1;
	else if (c >> 6 == T_IND)
		carret->movement += 2;
	else
		carret->movement += 0;
	if ((c & 0x30) >> 4 == T_DIR)
		carret->movement += dir_size;
	else if ((c & 0x30) >> 4 == T_REG)
		carret->movement += 1;
	else if ((c & 0x30) >> 4 == T_IND)
		carret->movement += 2;
	else
		carret->movement += 0;
	if (num_args == 2)
		return ;
	help_set_movement(carret, c, dir_size);
}
