/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prove_num_position.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 19:35:23 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/11/09 19:35:59 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static size_t	count_files(t_list *args)
{
	size_t		result;

	result = 0;
	while (args)
	{
		if (is_dot_cor(args->content))
			result++;
		args = args->next;
	}
	return (result);
}

void			prove_num_position(t_list *args)
{
	size_t		count;
	t_list		*temp;

	count = count_files(args);
	temp = args;
	while (args)
	{
		if (iss(args->content, "-n", 2))
		{
			if (ft_atoi_llu((args->next)->content) > count)
			{
				ft_putstr("Error: the file sequence ");
				error_out_free_lst("number is too large", temp);
			}
		}
		args = args->next;
	}
}
