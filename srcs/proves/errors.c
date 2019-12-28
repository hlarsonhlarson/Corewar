/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 19:02:00 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/11/09 19:02:20 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	error_out(char *error_message)
{
	ft_putstr_fd(error_message, 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}

void	error_out_free_lst(char *error_message, t_list *lst)
{
	ft_lst_free_chain(lst);
	error_out(error_message);
}
