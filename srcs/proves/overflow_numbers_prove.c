/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overflow_numbers_prove.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 19:25:39 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/11/09 19:26:24 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void				overflow_numbers_prove(t_list *lst)
{
	t_list			*temp;
	long int		num;
	char			*str;
	int				result;

	temp = lst;
	while (lst)
	{
		if (ft_isdigits(lst->content))
		{
			num = ft_atoi_llu(lst->content);
			str = ft_itoa_llu(num);
			result = ft_math_longar_str_comparison(str, lst->content);
			free(str);
			if (result)
				error_out_free_lst("Error: integer overflow", temp);
		}
		lst = lst->next;
	}
}
