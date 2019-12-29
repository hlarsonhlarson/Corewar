/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_crrets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 18:10:19 by hlarson           #+#    #+#             */
/*   Updated: 2019/12/28 18:25:33 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	free_carrets(t_list *carret)
{
	t_carret	*carret_tmp;
	t_list		*tmp;
	t_list		*tmp_2;

	tmp = carret;
	while (tmp)
	{
		carret_tmp = tmp->content;
		free(carret_tmp->reg);
		free(carret_tmp->name);
		free(carret_tmp->comment);
		free(carret_tmp);
		tmp_2 = tmp->next;
		free(tmp);
		tmp = tmp_2;
	}
}

void	free_field(t_parse *flags)
{
	free(flags->color);
	free(flags->map);
}
