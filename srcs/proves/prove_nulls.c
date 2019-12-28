/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prove_nulls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 19:34:00 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/11/09 19:34:19 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			prove_nulls(t_list *lst)
{
	t_list		*temp;

	temp = lst;
	while (lst)
	{
		if (iss(lst->content, "-n", 2) && !ft_atoi_llu(lst->next->content))
		{
			ft_putstr_fd("Error: player priority", 2);
			error_out_free_lst(" must be greater than zero", temp);
		}
		lst = lst->next;
	}
}
