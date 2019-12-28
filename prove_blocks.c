/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prove_blocks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 19:29:07 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/11/09 19:30:09 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int		check_next(t_list *next)
{
	char		*str;

	if (!next)
		return (1);
	str = next->content;
	if (is_dot_cor(str) || iss(str, "-n", 2))
		return (0);
	return (1);
}

void			prove_blocks_cors(t_list *lst)
{
	int			flag;
	t_list		*temp;

	flag = 0;
	temp = lst;
	while (lst)
	{
		if (is_dot_cor(lst->content))
			flag += check_next(lst->next);
		lst = lst->next;
	}
	if (flag > 1)
		error_out_free_lst("Error: block formatting is broken", temp);
}
