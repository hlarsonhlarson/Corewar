/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_filenames.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 19:15:24 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/11/09 19:17:11 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static t_list	*jump_next_next(t_list *current)
{
	current = current->next;
	current = current->next;
	return (current->next);
}

static size_t	get_range_of_name(t_list *current)
{
	current = current->next;
	return (ft_atoi_llu(current->content) - 1);
}

t_list			*sames(t_list *lst)
{
	t_list		*result;

	result = NULL;
	while (lst)
	{
		if (iss(lst->content, "-n", 2))
		{
			lst = jump_next_next(lst);
			continue ;
		}
		if (is_dot_cor(lst->content))
			ft_lstadd(&result, \
				ft_lstnew_no_copy(ft_strdup(lst->content), \
				ft_strlen(lst->content)));
		lst = lst->next;
	}
	return (ft_lst_turn(result));
}

t_list			*ranges(t_list *lst)
{
	t_list		*result;
	t_list		*new;
	char		*str;

	result = NULL;
	while (lst)
	{
		if (iss(lst->content, "-n", 2))
		{
			str = (lst->next->next)->content;
			new = ft_lstnew_no_copy(ft_strdup(str), get_range_of_name(lst));
			ft_lstadd(&result, new);
			lst = jump_next_next(lst);
			continue ;
		}
		lst = lst->next;
	}
	return (result);
}
