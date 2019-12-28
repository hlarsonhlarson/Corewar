/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 20:12:58 by hlarson           #+#    #+#             */
/*   Updated: 2019/12/28 15:21:59 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static	int	get_args(t_parse *flags, int *d, size_t *i)
{
	unsigned char	args_byte;

	args_byte = flags->map[*i];
	(*i)++;
	if (*i >= MEM_SIZE)
		(*i) %= MEM_SIZE;
	if ((args_byte) >> 6 == T_REG)
		d[0] = get_reg(flags->map, i);
	else
		return (-1);
	if ((args_byte & 0x30) >> 4 == T_REG)
		d[1] = get_reg(flags->map, i);
	else if ((args_byte & 0x30) >> 4 == T_IND)
		d[1] = get_dir_two(flags->map, i);
	else
		return (-1);
	return (0);
}

static void	st_copy_to_pos(t_parse *flags, t_carret *carret, int *d)
{
	int insert_pos;
	int	j;
	int	k;

	k = IDX_MOD;
	insert_pos = (d[1]) % k;
	insert_pos = insert_pos + carret->pos;
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

void		st(t_parse *flags, t_carret *carret)
{
	size_t			i;
	int				d[2];
	int				arg_byte;

	i = carret->pos + 1;
	arg_byte = i;
	if (i >= MEM_SIZE)
		i %= MEM_SIZE;
	set_movement(carret, (flags->map)[i], 2, 4);
	if (get_args(flags, d, &i) == -1)
		return ;
	if (d[0] < 1 || d[0] > 16)
		return ;
	if (((flags->map)[arg_byte] & 0x30) >> 4 == T_REG
			&& (d[1] < 1 || d[1] > 16))
		return ;
	d[0] = (carret->reg)[d[0] - 1];
	if (((flags->map)[arg_byte] & 0x30) >> 4 == T_REG)
		(carret->reg)[d[1] - 1] = d[0];
	else
		st_copy_to_pos(flags, carret, d);
	return ;
}
