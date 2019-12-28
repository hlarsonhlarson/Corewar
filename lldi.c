/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 04:26:34 by hlarson           #+#    #+#             */
/*   Updated: 2019/12/28 15:21:20 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	help_get_args(t_parse *flags, size_t args_byte, int *d, size_t i)
{
	if ((((flags->map[args_byte]) << 0xc) >> 2) == T_REG)
		d[2] = get_reg(flags->map, &i);
	else
		return (-1);
	if ((((((flags->map[args_byte]) << 0xc) >> 2) == T_REG) &&
				(d[2] < 1 || d[2] > 16))
			|| (((((flags->map[args_byte]) & 0x3f) >> 4) == T_REG) &&
				(d[1] < 1 || d[1] > 16))
			|| (((((flags->map[args_byte]) & 0x3f) >> 4) == T_REG) &&
				(d[0] < 1 || d[0] > 16)))
		return (-1);
	return (0);
}

static int	get_all_args(t_parse *flags, t_carret *carret, int *d, size_t i)
{
	size_t	args_byte;

	args_byte = i;
	set_movement(carret, flags->map[args_byte], 3, 2);
	if (((((flags->map)[args_byte])) >> 6) == T_REG)
		d[0] = get_reg(flags->map, &i);
	else if (((((flags->map)[args_byte])) >> 6) == T_DIR)
		d[0] = get_dir_two(flags->map, &i);
	else if ((((flags->map[args_byte])) >> 6) == T_IND)
		d[0] = get_arg_for_ind(flags->map, carret, &i, get_ind(flags->map, &i));
	else
		return (-1);
	if (((((flags->map)[args_byte]) & 0x30) >> 4) == T_REG)
		d[1] = get_reg(flags->map, &i);
	else if (((((flags->map)[args_byte]) & 0x30) >> 4) == T_DIR)
		d[1] = get_dir_two(flags->map, &i);
	else
		return (-1);
	return (help_get_args(flags, args_byte, d, i));
}

static void	st_copy_to_pos(t_parse *flags, t_carret *carret, int *d)
{
	int		insert_pos;
	int		j;
	int		k;

	k = IDX_MOD;
	insert_pos = carret->pos + (d[0] + d[1]) % k;
	while (insert_pos < 0)
		insert_pos = insert_pos + MEM_SIZE;
	if (insert_pos >= MEM_SIZE)
		insert_pos = insert_pos % MEM_SIZE;
	j = 3;
	while (j != -1)
	{
		(flags->map)[insert_pos] = ((unsigned char *)(d))[j];
		(flags->color)[insert_pos] = carret->number;
		j--;
		insert_pos++;
		if (insert_pos >= MEM_SIZE)
			insert_pos = insert_pos % MEM_SIZE;
	}
}

void		lldi(t_parse *flags, t_carret *carret)
{
	int		d[3];
	size_t	i;
	int		k;
	int		arg_byte;

	k = IDX_MOD;
	i = carret->pos + 1;
	if (i >= MEM_SIZE)
		i %= MEM_SIZE;
	arg_byte = i;
	if (get_all_args(flags, carret, d, i) == -1)
		return ;
	if (((((flags->map)[arg_byte])) >> 6) == T_REG)
		d[0] = (carret->reg)[d[0]];
	if (((((flags->map)[arg_byte]) & 0x30) >> 4) == T_REG)
		d[1] = (carret->reg)[d[1]];
	st_copy_to_pos(flags, carret, d);
}
