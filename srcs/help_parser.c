/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 17:06:51 by hlarson           #+#    #+#             */
/*   Updated: 2019/12/28 17:10:54 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

char			*print_begin(int index, int champion_exec_code_size, \
		char *name, char *comment)
{
	t_list	*lst;
	char	*str;

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

void			colorizer(unsigned char *color,
		unsigned char paint, size_t size)
{
	size_t index;

	index = 0;
	while (index < size)
	{
		color[index] = paint;
		index++;
	}
}

t_list			*add_to_print(char *to_print, t_list *old)
{
	ft_lstadd(&old, ft_lstnew_no_copy(to_print, ft_strlen(to_print)));
	return (old);
}

void			help_carret_generate(t_carret *carret, size_t index,
		t_parse *flags, t_list *files)
{
	carret->name = ft_memdup(ft_jump(files->content, 4), (PROG_NAME_LENGTH));
	ft_memcpy(&(carret->champion_exec_code_size),
			ft_jump(files->content, 8 + (PROG_NAME_LENGTH)), 4);
	ft_mem_reverse(&(carret->champion_exec_code_size), 1, 4);
	ft_memcpy(flags->map + carret->pos, ft_jump(files->content,
				16 + (PROG_NAME_LENGTH) + (COMMENT_LENGTH)),
			carret->champion_exec_code_size);
	colorizer(flags->color + carret->pos, (unsigned char)index,
			carret->champion_exec_code_size);
	carret->reg = (int *)ft_memalloc((REG_NUMBER) * sizeof(int));
	(carret->reg)[0] = -((int)(index));
	carret->comment = ft_memdup(ft_jump(files->content,
				12 + (PROG_NAME_LENGTH)), (COMMENT_LENGTH));
	carret->number = index;
	carret->timer = 0;
	carret->carry = 0;
	carret->movement = 0;
	carret->dead = 0;
	carret->live = 0;
	carret->live_last = 0;
	carret->id = index;
}

t_list			*carret_generate(t_list *files, t_parse *flags,
		size_t file_num)
{
	t_carret	carret;
	size_t		index;
	t_list		*result;
	t_list		*to_print;

	index = 1;
	result = NULL;
	to_print = NULL;
	while (files)
	{
		carret.pos = (index - 1) * ((MEM_SIZE) / file_num);
		help_carret_generate(&carret, index, flags, files);
		ft_lstadd(&result, ft_lstnew_no_copy(ft_memdup(&carret,
						sizeof(t_carret)), sizeof(t_carret)));
		to_print = add_to_print(print_begin(index,
					carret.champion_exec_code_size,
					carret.name, carret.comment), to_print);
		files = files->next;
		index++;
	}
	ft_lst_putstr_free(ft_lst_turn(to_print));
	return (result);
}
