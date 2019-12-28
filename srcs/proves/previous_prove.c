/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   previous_prove.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 19:27:44 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/11/09 19:28:14 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		previous_num_prove_helper(t_list *previous, t_list *temp)
{
	int			result;

	if (!previous)
		error_out_free_lst("Error: the flag for the number is undefined", temp);
	result = iss(previous->content, "-d", 2);
	result += iss(previous->content, "-n", 2);
	result += iss(previous->content, "-dump", 5);
	if (!result)
		error_out_free_lst("Error: the flag for the number is undefined", temp);
}

void			previous_num_prove(t_list *lst)
{
	t_list		*temp;
	t_list		*previous;

	previous = NULL;
	temp = lst;
	while (lst)
	{
		if (ft_isdigits(lst->content))
			previous_num_prove_helper(previous, temp);
		previous = lst;
		lst = lst->next;
	}
}
