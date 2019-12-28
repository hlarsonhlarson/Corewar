/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_alg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 02:23:13 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/12/06 16:50:48 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void print_map_printf(unsigned char *map, t_parse *flags)
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

void set_timer(t_carret *carret, t_parse *flags)
{
	unsigned char	c;

	c = (flags->map)[carret->pos];
    carret->op = c;
	//printf("%x\n", c);
	if (c == 1)
		carret->timer = 10;
	else if (c == 2)
		carret->timer = 5;
	else if (c == 3)
		carret->timer = 5;
	else if (c == 4)
		carret->timer = 10;
	else if (c == 5)
		carret->timer = 10;
	else if (c == 6)
		carret->timer = 6;
	else if (c == 7)
		carret->timer = 6;
	else if (c == 8)
		carret->timer = 6; 
	else if (c == 9)
		carret->timer = 20;
	else if (c == 10)
		carret->timer = 25;
	else if (c == 11)
		carret->timer = 25;
	else if (c == 12)
		carret->timer = 800;
	else if (c == 13)
		carret->timer = 10;
	else if (c == 14)
		carret->timer = 50;
	else if (c == 15)
		carret->timer = 1000;
	else if (c == 16)
		carret->timer = 2;
	else
	{
		if ((flags->color)[carret->pos] != 200 && (flags->color)[carret->pos] != 0)
			(flags->color)[carret->pos] /= 10;
		else
			(flags->color)[carret->pos] = 0;
		carret->pos += 1;
		if (carret->pos >= MEM_SIZE)
			carret->pos %= MEM_SIZE;
		carret->timer = 0;
		(carret->movement) = 0;
		return ;
	}
	carret->movement = 1;
}
/*
static int	count_carret(t_list *carret)
{
	t_list	*tmp;
	int	i;

	i = 0;
	tmp = carret;
	while(tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
*/

int	run_carret(t_list *carret, size_t i, t_parse *flags)
{
	t_list	*tmp;

	tmp = carret;
	//printf("START\n\n\n\n\n");
	while (tmp)
	{
//		printf("HI %d %zu %s \n\n",  ((t_carret *)(tmp->content))->pos, ((t_carret *)(tmp->content))->timer, ((t_carret *)(tmp->content))->name);
        if (((t_carret *)(tmp->content))->dead == 0)
        {
            if (((t_carret *)(tmp->content))->timer <= 0 && ((t_carret *)(tmp->content))->movement == 0)
                        set_timer(tmp->content, flags);
			if (((t_carret *)(tmp->content))->timer != 0)
				((t_carret *)(tmp->content))->timer = ((t_carret *)(tmp->content))->timer - 1;
			if (((t_carret *)(tmp->content))->timer <= 0 && ((t_carret *)(tmp->content))->movement == 1)
			{
				((t_carret *)(tmp->content))->movement = 0;
				move_and_do(tmp->content, i, flags);
				(flags->color)[((t_carret *)(tmp->content))->pos] = 0;
				((t_carret *)(tmp->content))->pos = (((t_carret *)(tmp->content))->movement + ((t_carret *)(tmp->content))->pos) % MEM_SIZE;
				((t_carret *)(tmp->content))->movement = 0;
			}
		}
		if (((flags->color)[((t_carret *)(tmp->content))->pos] *= 10) == 0 && (((t_carret *)(tmp->content))->dead == 0))
			(flags->color)[((t_carret *)(tmp->content))->pos] = 200;
		tmp = tmp->next;
	}
	//printf("end\n");
	return (0);
}
/*
static void set_first_timer(t_list *carret, t_parse *flags)
{
	t_list	*tmp;

	tmp = carret;
	while (tmp)
	{
		set_timer(tmp->content, flags);
		((t_carret *)tmp->content)->movement = 1;
    //    ((t_carret *)tmp->content)->timer -= 1;
		tmp = tmp->next;
	}
}
*/
static int	check_for_life(t_list *carret)
{
	t_list	*tmp;
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

int print_winner(t_parse *flags)
{
	t_list *gamers;
	t_carret *gamer;

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
	//printf("Die \n\n\n\n\n");
	while (tmp)
	{
		tmp_carret = tmp->content;
		if (tmp_carret->dead == 0) {

            res_delta = i - tmp_carret->live_last;
            if (res_delta >= compare) {
              //  printf("%d cycle %zu, id%d CTD%d\n", res_delta, i, tmp_carret->id, compare);
                tmp_carret->dead = 1;
            }
        }
		tmp = tmp->next;
	}
}

int		main_alg(t_parse *flags)
{
	size_t	i;
	size_t	delta;
	int k = 0;
	int win = 0;

	i = 0;
	delta = 0;
	if (flags->v)
		init_ncurses();
	k = (int)(CYCLES_TO_DIE) - 1;
	//set_first_timer(flags->carret, flags);
	while (win != 1 && (flags->dump != i || i == 0) && (flags->d != i || i == 0))
	{
        i++;
       // if (i == 268)
       //     printf("HI");
		run_carret(flags->carret, i, flags);
		if (k < 0)
        {
            win = 1;
            break ;
        }
		else if (k == 0)
		{
		   // printf("CTD %lu\n", (CYCLES_TO_DIE - delta));
            ft_set_lives(flags->carret, i, delta);
            if ((flags->live) >= (int)NBR_LIVE)
            {
                delta += CYCLE_DELTA;
                flags->check = 0;
            }
            else
                (flags->check)++;
            if (flags->check >= MAX_CHECKS)
            {
                flags->check = 0;
                delta += CYCLE_DELTA;
            }
            flags->live = 0;
			k = (int)(CYCLES_TO_DIE - delta);
		}
		if (flags->v == 1)
			print_map(flags->map, flags, i);
        k--;
		win = check_for_life(flags->carret);
	}
	if ((flags->d != 0 || flags->dump != 0) && win == 0)
		print_map_printf(flags->map, flags);
	if (flags->v == 1)
		endwin();
	if (win != 0)
		print_winner(flags);
	return (0);
}
