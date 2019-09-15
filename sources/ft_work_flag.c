/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_work_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 18:07:23 by hlarson           #+#    #+#             */
/*   Updated: 2019/09/15 15:30:34 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	insert_in_right_order(int num_of_player, t_map *map, char *name)
{
	t_list	*tmp;
	t_list	*tmp_two;
	size_t	iterator;

	tmp = NULL;
	tmp_two = map->ch_names;
	iterator = 1;
	while (tmp_two && iterator < num_of_player)
	{
		tmp_two = tmp->next;
		iterator++;
	}




void	add_flag_n(t_map *map, char **argv, size_t *i)
{
	int		num_of_player;

	*i = *i + 1;	
	num_of_player = ft_atoi(argv[i]);
	*i = *i + 1;
	if (num_of_player <= 0)
	{
		*i = 0;
		return ;
	}
	*i = *i + 1;
	if (check_name(argv[*i]) > 0)
		insert_in right_order(num_of_player, map, argv[*i]);
	else
		*i = 0;
}
