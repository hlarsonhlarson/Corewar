/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_alg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 02:23:13 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/12/28 17:35:52 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		print_map_printf(unsigned char *map, t_parse *flags)
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
			ft_putstr(" \n");
		if (i % k == 0 && i)
			print_hex_four(i);
		else if (i % k == 0)
			ft_putstr("0x0000 :");
		ft_putchar(' ');
		print_hex_two(map[i]);
		i++;
	}
	printf(" \n");
}

void		work_with_carret(t_list *tmp, size_t i, t_parse *flags)
{
	((t_carret *)(tmp->content))->movement = 0;
	move_and_do(tmp->content, i, flags);
	(flags->color)[((t_carret *)(tmp->content))->pos] = 0;
	((t_carret *)(tmp->content))->pos =
		(((t_carret *)(tmp->content))->movement
		+ ((t_carret *)(tmp->content))->pos) % MEM_SIZE;
	((t_carret *)(tmp->content))->movement = 0;
}

int			run_carret(t_list *carret, size_t i, t_parse *flags)
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

int			main_alg(t_parse *flags)
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
