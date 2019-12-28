/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proves.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 15:59:12 by hlarson           #+#    #+#             */
/*   Updated: 2019/12/28 15:59:20 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	prove_arguments(t_list *arguments)
{
	if (!arguments)
		error_out("Error: not arguments");
	all_is_proves(arguments);
	num_args_prove(arguments);
	next_proves(arguments);
	overflow_numbers_prove(arguments);
	previous_num_prove(arguments);
	prove_n_num_duples(arguments);
	prove_blocks_cors(arguments);
	prove_num_position(arguments);
	prove_nulls(arguments);
}
