/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_args_prove.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 19:24:49 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/11/09 19:25:15 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void			error_num_args_prove(t_list *args)
{
	ft_putstr_fd("Error: extra arguments\n", 2);
	ft_putstr_fd("The -v, -d, -a, and -dump arguments ", 2);
	ft_putstr_fd("must be in at most one instance each. ", 2);
	error_out_free_lst("The -d and -dump flags exclude each other.", args);
}

static void			num_args_prove_helper(t_list *arguments)
{
	size_t			ds;
	size_t			vs;
	size_t			dumps;
	t_list			*temp;
	size_t			as;

	ds = 0;
	vs = 0;
	as = 0;
	dumps = 0;
	temp = arguments;
	while (arguments)
	{
		ds += iss(arguments->content, "-d", 2);
		vs += iss(arguments->content, "-v", 2);
		as += iss(arguments->content, "-a", 2);
		dumps += iss(arguments->content, "-dump", 5);
		arguments = arguments->next;
	}
	if (ds > 1 || dumps > 1 || vs > 1 || (dumps && ds) || as > 1)
		error_num_args_prove(temp);
}

static void			num_champions(t_list *arguments)
{
	t_list			*temp;
	size_t			champions;

	temp = arguments;
	champions = 0;
	while (arguments)
	{
		if (is_dot_cor(arguments->content))
			champions += 1;
		arguments = arguments->next;
	}
	if (CHAMP_MAX_SIZE == 0)
	{
		ft_putstr_fd("Error: an erroneous constant", 2);
		error_out_free_lst(" of the number of Champions", temp);
	}
	if (champions > CHAMP_MAX_SIZE)
	{
		ft_putstr_fd("Error: too many Champions\n", 2);
		error_out_free_lst("They don't fit in the stadium.", temp);
	}
}

void				num_args_prove(t_list *arguments)
{
	t_list			*temp;

	num_args_prove_helper(arguments);
	num_champions(arguments);
	temp = arguments;
	while (arguments)
	{
		if (is_dot_cor(arguments->content))
			return ;
		arguments = arguments->next;
	}
	error_out_free_lst("Error: missing champion name", temp);
}
