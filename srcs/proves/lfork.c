/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 20:37:25 by hlarson           #+#    #+#             */
/*   Updated: 2019/12/28 15:53:38 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	carret_cpy(t_carret *carret_new, t_carret *carret)
{
	size_t i;

	i = 0;
	carret_new->number = carret->number;
	carret_new->name = ft_strdup(carret->name);
	carret_new->comment = ft_strdup(carret->comment);
	carret_new->reg = (int *)ft_memalloc(sizeof(int) * REG_NUMBER);
	while (i != 16)
	{
		carret_new->reg[i] = carret->reg[i];
		i++;
	}
	carret_new->dead = 0;
	carret_new->timer = 0;
	carret_new->movement = 0;
	carret_new->live = carret->live;
	carret_new->carry = carret->carry;
	carret_new->live_last = carret->live_last;
	carret_new->champion_exec_code_size = carret->champion_exec_code_size;
}

void		op_lfork(t_parse *flags, t_carret *carret)
{
	int			pos;
	size_t		i;
	t_carret	*carret_new;

	i = carret->pos + 1;
	if (i >= MEM_SIZE)
		i %= MEM_SIZE;
	pos = (short)get_dir_two(flags->map, &i);
	carret_new = (t_carret *)malloc(sizeof(t_carret));
	carret_cpy(carret_new, carret);
	carret_new->pos = pos + carret->pos;
	carret_new->movement = 0;
	if (carret_new->pos >= MEM_SIZE)
		carret_new->pos %= MEM_SIZE;
	ft_lstadd(&(flags->carret),
			ft_lstnew_no_copy(carret_new, sizeof(t_carret)));
	while (carret_new->pos < 0)
		carret_new->pos += MEM_SIZE;
	carret->movement += 3;
}
