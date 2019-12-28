/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 18:53:46 by hlarson           #+#    #+#             */
/*   Updated: 2019/11/18 15:52:32 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int search_name(t_list *args, char *str)
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

static size_t search_d(t_list *args)
{
	while (args)
	{
		if (iss(args->content, "-d", 2))
			return (ft_atoi_llu((args->next)->content));
		args = args->next;
	}
	return (0);
}

static size_t search_dump(t_list *args)
{
	while (args)
	{
		if (iss(args->content, "-dump", 5))
			return (ft_atoi_llu((args->next)->content));
		args = args->next;
	}
	return (0);
}

char *print_begin(int index, int champion_exec_code_size, \
	char *name, char *comment)
{
	t_list *lst;
	char *str;

	lst = NULL;
	str = ft_strdup("* Player ");
	ft_lstadd(&lst, ft_lstnew_no_copy(str, ft_strlen(str)));
	str = ft_itoa(index);
	ft_lstadd(&lst, ft_lstnew_no_copy(str, ft_strlen(str)));
	str = ft_strdup(", weighing ");
	ft_lstadd(&lst, ft_lstnew_no_copy(str, ft_strlen(str)));
	str = ft_itoa(champion_exec_code_size);
	ft_lstadd(&lst, ft_lstnew_no_copy(str, ft_strlen(str)));
	str = ft_strdup(" bytes, \"");
	ft_lstadd(&lst, ft_lstnew_no_copy(str, ft_strlen(str)));
	str = ft_strdup(name);
	ft_lstadd(&lst, ft_lstnew_no_copy(str, ft_strlen(str)));
	str = ft_strdup("\" (\"");
	ft_lstadd(&lst, ft_lstnew_no_copy(str, ft_strlen(str)));
	str = ft_strdup(comment);
	ft_lstadd(&lst, ft_lstnew_no_copy(str, ft_strlen(str)));
	str = ft_strdup("\") !\n");
	ft_lstadd(&lst, ft_lstnew_no_copy(str, ft_strlen(str)));
	return (ft_lst_strjoin_free_cs(ft_lst_turn(lst)));
}

void colorizer(unsigned char *color, unsigned char paint, size_t size)
{
	size_t index;

	index = 0;
	while (index < size)
	{
		color[index] = paint;
		index++;
	}
}

t_list *add_to_print(char *to_print, t_list *old)
{
	ft_lstadd(&old, ft_lstnew_no_copy(to_print, ft_strlen(to_print)));
	return (old);
}

t_list *carret_generate(t_list *files, unsigned char *map, size_t file_num, unsigned char *color)
{
	t_carret carret;
	size_t index;
	t_list *result;
	t_list *to_print;

	index = 1;
	result = NULL;
	to_print = NULL;
	while (files)
	{
		carret.name = ft_memdup(ft_jump(files->content, 4), (PROG_NAME_LENGTH));
		ft_memcpy(&(carret.champion_exec_code_size), ft_jump(files->content, 8 + (PROG_NAME_LENGTH)), 4);
		ft_mem_reverse(&(carret.champion_exec_code_size), 1, 4);
		carret.pos = (index - 1) * ((MEM_SIZE) / file_num);
		ft_memcpy(map + carret.pos, ft_jump(files->content, 16 + (PROG_NAME_LENGTH) + (COMMENT_LENGTH)), carret.champion_exec_code_size);
		colorizer(color + carret.pos, (unsigned char)index, carret.champion_exec_code_size);
		carret.reg = (int *)ft_memalloc((REG_NUMBER) * sizeof(int));
		(carret.reg)[0] = -((int)(index));
		carret.comment = ft_memdup(ft_jump(files->content, 12 + (PROG_NAME_LENGTH)), (COMMENT_LENGTH));
		to_print = add_to_print(print_begin(index, carret.champion_exec_code_size, carret.name, carret.comment), to_print);
		carret.number = index;
		carret.timer = 0;
		carret.carry = 0;
		carret.movement = 0;
		carret.dead = 0;
		carret.live = 0;
		carret.live_last = 0;
		carret.id = index;
		ft_lstadd(&result, ft_lstnew(ft_memdup(&carret, sizeof(t_carret)), sizeof(t_carret)));
		files = files->next;
		index++;
	}
	ft_lst_putstr_free(ft_lst_turn(to_print));
	return (result);
}

void parser(t_list *args, t_parse *flags)
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
	flags->carret = carret_generate(files, flags->map, ft_lst_chain_len(files), flags->color);
	ft_lst_free_chain(files);
}
