/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 20:59:27 by hlarson           #+#    #+#             */
/*   Updated: 2019/12/28 15:54:07 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	help_get_args(t_parse *flags, size_t args_byte, int *d, size_t i)
{
	if ((((flags->map[args_byte]) & 0xc) >> 2) == T_REG)
		d[2] = get_reg(flags->map, &i);
	else
		return (-1);
	if ((((((flags->map[args_byte]) & 0xc) >> 2) == T_REG) &&
				(d[2] < 1 || d[2] > 16))
			|| (((((flags->map[args_byte]) & 0x3f) >> 4) == T_REG) &&
				(d[1] < 1 || d[1] > 16))
			|| (((((flags->map[args_byte]) >> 6) & T_REG) &&
					(d[0] < 1 || d[0] > 16))))
		return (-1);
	return (0);
}

static int	get_all_args(t_parse *flags, t_carret *carret, int *d, size_t i)
{
	size_t	args_byte;

	args_byte = i;
	i++;
	if (i >= MEM_SIZE)
		i %= MEM_SIZE;
	if (((((flags->map)[args_byte])) >> 6) == T_REG)
		d[0] = get_reg(flags->map, &i);
	else if (((((flags->map)[args_byte])) >> 6) == T_DIR)
		d[0] = get_dir_one(flags->map, &i);
	else if ((((flags->map[args_byte])) >> 6) == T_IND)
		d[0] = get_arg_for_ind(flags->map, carret,
				&i, get_ind(flags->map, &i) % IDX_MOD);
	else
		return (-1);
	if (((((flags->map)[args_byte]) & 0x30) >> 4) == T_REG)
		d[1] = get_reg(flags->map, &i);
	else if (((((flags->map)[args_byte]) & 0x30) >> 4) == T_DIR)
		d[1] = get_dir_one(flags->map, &i);
	else if ((((flags->map[args_byte]) & 0x30) >> 4) == T_IND)
		d[1] = get_arg_for_ind(flags->map, carret,
				&i, get_ind(flags->map, &i) % IDX_MOD);
	else
		return (-1);
	return (help_get_args(flags, args_byte, d, i));
}

static void	or_helper(t_parse *flags, t_carret *carret,
		int *d, size_t args_byte)
{
	if (((((flags->map)[args_byte])) >> 6) & T_REG)
		d[0] = (carret->reg)[d[0] - 1];
	if (((((flags->map)[args_byte]) & 0x30) >> 4) & T_REG)
		d[1] = (carret->reg)[d[1] - 1];
	(carret->reg)[d[2] - 1] = d[0] & d[1];
	if ((d[0] & d[1]) == 0)
		carret->carry = 1;
	else
		carret->carry = 0;
}

void		op_and(t_parse *flags, t_carret *carret)
{
	size_t	i;
	size_t	args_byte;
	int		d[3];

	i = carret->pos + 1;
	if (i >= MEM_SIZE)
		i %= MEM_SIZE;
	args_byte = i;
	ft_bzero(d, 3);
	set_movement(carret, flags->map[args_byte], 3, 4);
	if (get_all_args(flags, carret, d, i) == -1)
		return ;
	or_helper(flags, carret, d, args_byte);
}
