/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prove_duples.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 19:30:41 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/11/12 20:15:48 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static unsigned long long int	return_n(t_list *current)
{
	return (ft_atoi_llu((char *)((current->next)->content)));
}

void							prove_n_num_duples(t_list *args)
{
	t_list						*new;
	t_list						*temp;
	t_list						*dedupl;
	size_t						len;

	new = NULL;
	temp = args;
	while (args)
	{
		if (iss(args->content, "-n", 2))
			ft_lstadd(&new, ft_lstnew_no_copy(ft_itoa_llu(return_n(args)),\
			sizeof(unsigned long long int)));
		args = args->next;
	}
	len = ft_lst_chain_len(new);
	dedupl = ft_lst_deduplication(new);
	len = len - ft_lst_chain_len(dedupl);
	ft_lst_free_chain(dedupl);
	if (len)
		error_out_free_lst("Error: champions priorities overlap", temp);
}
