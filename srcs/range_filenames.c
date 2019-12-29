/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range_filenames.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 20:07:27 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/11/12 20:08:39 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static t_list	*insert(t_list *chain, t_list *new, size_t position)
{
	size_t		index;
	t_list		*temp;

	if (!chain)
		return (new);
	if (!new)
		return (chain);
	if (!position)
	{
		new->next = chain;
		return (new);
	}
	index = 1;
	temp = chain;
	while (chain)
	{
		if (index == position)
		{
			new->next = chain->next;
			chain->next = new;
		}
		index++;
		chain = chain->next;
	}
	return (temp);
}

static t_list	*gen_min_position(t_list *ranges, \
	size_t last_position)
{
	static int	first;
	t_list		*result;

	result = NULL;
	while (ranges)
	{
		if (!first && !ranges->content_size)
		{
			first = 1;
			return (ft_lst_unit_transfer(ranges));
		}
		if (((!result && ranges->content_size) || (result && \
			ranges->content_size < result->content_size)) \
			&& ranges->content_size > last_position)
			result = ranges;
		ranges = ranges->next;
	}
	first = 1;
	if (result)
	{
		ranges = ft_lst_unit_transfer(result);
		result->content_size = 0;
		result = ranges;
	}
	return (result);
}

static t_list	*range_filenames_helper(t_list *ranges_list, t_list *sames_list)
{
	size_t		last;
	t_list		*min;

	last = 0;
	while ((min = gen_min_position(ranges_list, last)))
	{
		if (!sames_list)
		{
			sames_list = gen_min_position(ranges_list, last);
			if (sames_list->content_size)
				return (NULL);
		}
		else
		{
			last = min->content_size;
			sames_list = insert(sames_list, min, min->content_size);
		}
	}
	return (sames_list);
}

t_list			*range_filenames(t_list *args)
{
	t_list		*sames_list;
	t_list		*ranges_list;
	t_list		*result;

	sames_list = sames(args);
	ranges_list = ranges(args);
	if (!ranges_list)
		return (sames_list);
	result = range_filenames_helper(ranges_list, sames_list);
	return (result);
}
