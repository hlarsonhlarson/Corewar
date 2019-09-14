/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:27:54 by hlarson           #+#    #+#             */
/*   Updated: 2019/09/14 17:59:35 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		check_for_name(char **argv, t_map *map, size_t *i)
{
	if (ft_strcmp(argv[i], "-n") == 0)
		add_flag_n(map, argv, i);
	else if (ft_strcmp(argv[i], "-dump") == 0)
		add_flag_dump(map, argv, i);
	else if (ft_strcmp(argv[i], "-d") == 0)
		add_flag_d(map, argv, i);
	else
		add_champ_name(map, argv, i);
	return ((*i == 0) ? -1 : 0);
}

int		ft_validate(char **argv)
{
	size_t	i;

	i = 1;
	while (argv[i])
	{
		if (check_for_name(argv, map, &i) < 0)
			return (-1);
		if (check_file_format(map->champion) < 0)
			return (-1);
		i++;
	}
	return (1);
}
