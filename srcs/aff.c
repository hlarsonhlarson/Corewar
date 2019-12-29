/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 04:51:49 by hlarson           #+#    #+#             */
/*   Updated: 2019/12/28 15:19:27 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	help_aff(int *d, t_parse *flags, t_carret *carret, size_t *i)
{
	if (((flags->map)[*i] >> 6) == T_REG)
	{
		(*i)++;
		*d = get_reg(flags->map, i);
		return (0);
	}
	else if (((flags->map)[*i] >> 6) == T_DIR)
	{
		carret->movement += 4;
		return (-1);
	}
	else if (((flags->map)[*i] >> 6) == T_IND)
	{
		carret->movement += 2;
		return (-1);
	}
	else
	{
		carret->movement += 0;
		return (-1);
	}
}

void		aff(t_parse *flags, t_carret *carret)
{
	size_t	i;
	int		d;

	carret->movement += 2;
	i = carret->pos + 1;
	if (i >= MEM_SIZE)
		i %= MEM_SIZE;
	if (help_aff(&d, flags, carret, &i) == -1)
		return ;
	carret->movement += 1;
	if (d < 1 || d > 16)
		return ;
	d = (carret->reg)[d - 1];
	if (flags->a != 0)
	{
		ft_putstr("Aff: ");
		ft_putchar(d);
		ft_putchar('\n');
	}
}
