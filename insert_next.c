/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_next.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 20:40:18 by hlarson           #+#    #+#             */
/*   Updated: 2019/11/09 19:18:10 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		insert_next(t_carret *carret, t_list *current)
{
	t_list	*next;
	t_list	*to_insert;

	next = current->next;
	to_insert = ft_lstnew_no_copy(carret, sizeof(t_carret));
	current->next = to_insert;
	to_insert->next = next;
}
