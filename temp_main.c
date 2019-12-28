/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 18:15:05 by hlarson           #+#    #+#             */
/*   Updated: 2019/10/26 19:01:15 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int main(int argc, char **argv)
{
	t_list *arguments;
	t_parse flags;

	arguments = ft_get_arguments_command_line(argc, argv);
	prove_arguments(arguments);
	parser(arguments, &flags);
	//ft_printf("d = %d, dump = %d, a = %d, v = %d\n", (int)flags.d, (int)flags.dump, (int)flags.a, (int)flags.v);
	//ft_printf("%.*s", (int)flags.size_map, flags.map);
	//write(1, flags.map, MEM_SIZE);
/*	size_t	i = 0;
	while (i != MEM_SIZE)
	{
		if (i % 64 == 0)
			ft_printf("\n");
		if (i % 2 == 0)
			ft_printf(" ");
		ft_printf("%0.2X", flags.map[i]);
		i++;
	}*/
//	flags.v = 1;
//	if (flags.v == 1)
//		init_ncurses();
	main_alg(&flags);
//	if (flags.v == 1)
//		endwin();
	return (0);
}
