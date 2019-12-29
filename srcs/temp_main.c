/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 18:15:05 by hlarson           #+#    #+#             */
/*   Updated: 2019/12/28 16:00:36 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	main(int argc, char **argv)
{
	t_list	*arguments;
	t_parse	flags;

	arguments = ft_get_arguments_command_line(argc, argv);
	prove_arguments(arguments);
	parser(arguments, &flags);
	main_alg(&flags);
	ft_lst_free_chain(arguments);
	return (0);
}
