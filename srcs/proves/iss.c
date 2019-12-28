/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iss.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 19:07:15 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/12/28 15:55:43 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			is_dot_cor(char *str)
{
	int cmp;

	ft_str_reverse(str);
	cmp = ft_memcmp(str, "roc.", 4);
	ft_str_reverse(str);
	if (!cmp && ft_strlen(str) > 4)
		return (1);
	return (0);
}

int			iss(char *str, char *original, size_t len)
{
	if (ft_strlen(str) != len)
		return (0);
	if (!ft_memcmp(str, original, len))
		return (1);
	return (0);
}

static int	is_proves(t_list *lst)
{
	int to_prove;

	while (lst)
	{
		to_prove = 0;
		to_prove += is_dot_cor(lst->content);
		to_prove += iss(lst->content, "-dump", 5);
		to_prove += iss(lst->content, "-v", 2);
		to_prove += iss(lst->content, "-d", 2);
		to_prove += iss(lst->content, "-n", 2);
		to_prove += iss(lst->content, "-a", 2);
		to_prove += ft_isdigits(lst->content);
		if (!to_prove)
			return (0);
		lst = lst->next;
	}
	return (1);
}

void		all_is_proves(t_list *lst)
{
	if (!is_proves(lst))
		error_out_free_lst("Error: unrecognized argument type", lst);
}
