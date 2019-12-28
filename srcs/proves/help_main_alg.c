/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_main_alg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 16:29:47 by hlarson           #+#    #+#             */
/*   Updated: 2019/12/28 16:35:45 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	init_main_alg(size_t *i, size_t *delta, int *k, int *win)
{
	(*win) = 0;
	(*i) = 0;
	(*delta) = 0;
	(*k) = (int)(CYCLES_TO_DIE) - 1;
}

int		end_main_alg(t_parse *flags, int win)
{
	if ((flags->d != 0 || flags->dump != 0) && win == 0)
		print_map_printf(flags->map, flags);
	if (flags->v == 1)
		endwin();
	if (win != 0)
		print_winner(flags);
	free_carrets(flags->carret);
	free_field(flags);
	return (0);
}

int		print_winner(t_parse *flags)
{
	t_list		*gamers;
	t_carret	*gamer;

	gamers = flags->carret;
	while (gamers)
	{
		gamer = gamers->content;
		if (gamer->number == (size_t)(flags->last_alive))
		{
			printf("Contestant %d, \"%s\", has won !\n", \
					(int)(gamer->number), gamer->name);
			return (0);
		}
		gamers = gamers->next;
	}
	return (0);
}

void	ft_set_lives(t_list *carret, size_t i, int delta)
{
	t_list		*tmp;
	t_carret	*tmp_carret;
	int			compare;
	int			res_delta;

	tmp = carret;
	compare = CYCLES_TO_DIE - delta;
	while (tmp)
	{
		tmp_carret = tmp->content;
		if (tmp_carret->dead == 0)
		{
			res_delta = i - tmp_carret->live_last;
			if (res_delta >= compare)
				tmp_carret->dead = 1;
		}
		tmp = tmp->next;
	}
}

void	life_checker(t_parse *flags, int *k, size_t i, size_t *delta)
{
	ft_set_lives(flags->carret, i, *delta);
	if ((flags->live) >= (int)NBR_LIVE)
	{
		(*delta) += CYCLE_DELTA;
		flags->check = 0;
	}
	else
		(flags->check)++;
	if (flags->check >= MAX_CHECKS)
	{
		flags->check = 0;
		(*delta) += CYCLE_DELTA;
	}
	flags->live = 0;
	*k = (int)(CYCLES_TO_DIE - *delta);
}
