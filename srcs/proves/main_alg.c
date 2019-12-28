/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_alg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 02:23:13 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/12/28 16:17:47 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	print_map_printf(unsigned char *map, t_parse *flags)
{
	int	i;
	int	k;

	i = 0;
	if (flags->d != 0)
		k = 64;
	else if (flags->dump != 0)
		k = 32;
	else
		k = 1;
	while (i != MEM_SIZE)
	{
		if (i % k == 0 && i)
			printf("%c\n", ' ');
		if (i % k == 0 && i)
			printf("%#04.4x :", i);
		else if (i % k == 0)
			printf("0x0000 :");
		printf(" ");
		printf("%0.2x", map[i]);
		i++;
	}
	printf(" \n");
}

void	work_with_carret(t_list *tmp, size_t i, t_parse *flags)
{
	((t_carret *)(tmp->content))->movement = 0;
	move_and_do(tmp->content, i, flags);
	(flags->color)[((t_carret *)(tmp->content))->pos] = 0;
	((t_carret *)(tmp->content))->pos =
		(((t_carret *)(tmp->content))->movement
		+ ((t_carret *)(tmp->content))->pos) % MEM_SIZE;
	((t_carret *)(tmp->content))->movement = 0;
}

int	run_carret(t_list *carret, size_t i, t_parse *flags)
{
	t_list	*tmp;

	tmp = carret;
	while (tmp)
	{
		if (((t_carret *)(tmp->content))->dead == 0)
		{
			if (((t_carret *)(tmp->content))->timer <= 0
					&& ((t_carret *)(tmp->content))->movement == 0)
				set_timer(tmp->content, flags);
			if (((t_carret *)(tmp->content))->timer != 0)
				((t_carret *)(tmp->content))->timer =
					((t_carret *)(tmp->content))->timer - 1;
			if (((t_carret *)(tmp->content))->timer <= 0
					&& ((t_carret *)(tmp->content))->movement == 1)
				work_with_carret(tmp, i, flags);
		}
		if (((flags->color)[((t_carret *)(tmp->content))->pos] *= 10) == 0
				&& (((t_carret *)(tmp->content))->dead == 0))
			(flags->color)[((t_carret *)(tmp->content))->pos] = 200;
		tmp = tmp->next;
	}
	return (0);
}

static int	check_for_life(t_list *carret)
{
	t_list		*tmp;
	t_carret	*help;

	tmp = carret;
	while (tmp)
	{
		help = tmp->content;
		if (help->dead == 0)
			return (0);
		tmp = tmp->next;
	}
	return (1);
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
	return (0);
}

int		main_alg(t_parse *flags)
{
	size_t	i;
	size_t	delta;
	int		k;
	int		win;

	init_main_alg(&i, &delta, &k, &win);
	init_ncurses(flags);
	while (win != 1 && (flags->dump != i || i == 0)
			&& (flags->d != i || i == 0))
	{
		i++;
		run_carret(flags->carret, i, flags);
		if (k < 0)
		{
			win = 1;
			break ;
		}
		else if (k == 0)
			life_checker(flags, &k, i, &delta);
		if (flags->v == 1)
			print_map(flags->map, flags, i);
		k--;
		win = check_for_life(flags->carret);
	}
	return (end_main_alg(flags, win));
}
