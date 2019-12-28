/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 15:43:38 by hlarson           #+#    #+#             */
/*   Updated: 2019/12/28 15:58:24 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	help_init(void)
{
	init_pair(10, COLOR_YELLOW, COLOR_WHITE);
	init_pair(20, COLOR_RED, COLOR_WHITE);
	init_pair(30, COLOR_GREEN, COLOR_WHITE);
	init_pair(40, COLOR_BLUE, COLOR_WHITE);
	init_pair(60, COLOR_CYAN, COLOR_WHITE);
	init_pair(200, COLOR_WHITE, COLOR_WHITE);
	return (0);
}

int			init_ncurses(t_parse *flags)
{
	if (!(flags->v))
		return (0);
	initscr();
	start_color();
	noecho();
	init_pair(1, COLOR_YELLOW, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(6, COLOR_CYAN, COLOR_BLACK);
	help_init();
	nodelay(stdscr, TRUE);
	curs_set(FALSE);
	return (0);
}

int			count_carret(t_list *carret)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = carret;
	while (tmp)
	{
		if (((t_carret *)(tmp->content))->dead == 0)
			i++;
		tmp = tmp->next;
	}
	return (i);
}

void		print_map(unsigned char *c, t_parse *flags, size_t j)
{
	size_t	i;

	i = 0;
	erase();
	if (flags->print_movement != 0)
	{
		attron(A_BOLD);
		while (i != MEM_SIZE)
		{
			if (i % 64 == 0)
				printw("\n");
			if (i % 2 == 0)
				printw(" ");
			attron(COLOR_PAIR(flags->color[i]));
			printw("%02X", c[i]);
			attroff(COLOR_PAIR(flags->color[i]));
			i++;
		}
		printw("\nCYCLE NUM %zu PROCESS NUMS %d\n",
				j, count_carret(flags->carret));
		attroff(A_BOLD);
		refresh();
	}
	usleep(10000);
}
