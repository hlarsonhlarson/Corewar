/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_proves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 19:18:42 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/11/09 19:22:41 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		next_d(t_list *next, t_list *chain)
{
	if (!next)
	{
		ft_putstr_fd("Error: there's nothing", 2);
		error_out_free_lst(" after the flag -d or -dump", chain);
	}
	if (!ft_isdigits(next->content))
	{
		ft_putstr_fd("Error: there are no numbers ", 2);
		error_out_free_lst("after the -d or -dump flags", chain);
	}
}

static void		next_n(t_list *next, t_list *chain)
{
	if (!next)
	{
		ft_putstr_fd("Error: there's nothing", 2);
		error_out_free_lst(" after the flag -n", chain);
	}
	if (!ft_isdigits(next->content))
	{
		ft_putstr_fd("Error: there are no numbers ", 2);
		error_out_free_lst("after the -n flag", chain);
	}
	if (!next->next)
	{
		ft_putstr_fd("Error: no champion ", 2);
		error_out_free_lst("is listed after the -n flag", chain);
	}
	if (!is_dot_cor((char *)((next->next)->content)))
	{
		ft_putstr_fd("Error: incorrect champion", 2);
		error_out_free_lst(" name after the -n flag", chain);
	}
}

void			next_proves(t_list *arguments)
{
	t_list		*temp;

	temp = arguments;
	while (arguments)
	{
		if (iss(arguments->content, "-d", 2) \
		|| iss(arguments->content, "-dump", 5))
			next_d(arguments->next, temp);
		else if (iss(arguments->content, "-n", 2))
			next_n(arguments->next, temp);
		arguments = arguments->next;
	}
}
