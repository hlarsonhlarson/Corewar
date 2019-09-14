/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_work_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 18:07:23 by hlarson           #+#    #+#             */
/*   Updated: 2019/09/14 19:07:18 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	insert_in_right_order(int num_of_player, t_map *map)
{
	if (map->)
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
	{
		map->ch_names[map->names_iterator] = ft_strdup(argv[*i]);
		map->names_iterator = map->names_iterator + 1;
		insert_in right_order(num_of_player, map);
	}
	else
		*i = 0;
}
