/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 18:53:46 by hlarson           #+#    #+#             */
/*   Updated: 2019/12/28 17:09:25 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int		search_name(t_list *args, char *str)
{
	size_t len;

	len = ft_strlen(str);
	while (args)
	{
		if (iss(args->content, str, len))
			return (1);
		args = args->next;
	}
	return (0);
}

static size_t	search_d(t_list *args)
{
	while (args)
	{
		if (iss(args->content, "-d", 2))
			return (ft_atoi_llu((args->next)->content));
		args = args->next;
	}
	return (0);
}

static size_t	search_dump(t_list *args)
{
	while (args)
	{
		if (iss(args->content, "-dump", 5))
			return (ft_atoi_llu((args->next)->content));
		args = args->next;
	}
	return (0);
}

void			parser(t_list *args, t_parse *flags)
{
	t_list *files;
	t_list *filenames;

	flags->last_alive = 1;
	flags->a = search_name(args, "-a");
	flags->v = search_name(args, "-v");
	flags->d = search_d(args);
	flags->dump = search_dump(args);
	flags->check = 0;
	filenames = range_filenames(args);
	files = ft_get_all_files_free(filenames);
	prove_files(files);
	flags->map = ft_memalloc((MEM_SIZE) * sizeof(char));
	flags->color = ft_memalloc((MEM_SIZE) * sizeof(char));
	files = ft_lst_turn(files);
	flags->live = 0;
	flags->print_movement = 1;
	ft_putstr("Introducing contestants...\n");
	files = ft_lst_turn(files);
	flags->carret = carret_generate(files, flags,
			ft_lst_chain_len(files));
	ft_lst_free_chain(files);
}
