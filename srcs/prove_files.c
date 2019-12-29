/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prove_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 19:32:20 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/11/09 19:33:25 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			prove_files(t_list *files)
{
	t_list		*temp;

	temp = files;
	while (files)
	{
		if (!files->content)
		{
			ft_putstr_fd("Error: one of the files could not be saved.", 2);
			error_out_free_lst("\nMaybe he doesn't exist.", temp);
		}
		if (!files->content_size)
			error_out_free_lst("Error: one of the files is empty", temp);
		if (files->content_size < 5)
			error_out_free_lst("Error: one of the files is too small", temp);
		files = files->next;
	}
}
