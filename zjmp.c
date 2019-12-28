/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:42:36 by hlarson           #+#    #+#             */
/*   Updated: 2019/12/28 15:22:23 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	zjmp(t_carret *carret, unsigned char *c)
{
	size_t	i;
	int		k;

	k = IDX_MOD;
	if (carret->carry == 0)
	{
		carret->movement = 3;
		return ;
	}
	i = carret->pos + 1;
	if (i >= MEM_SIZE)
		i %= MEM_SIZE;
	carret->movement = get_dir_two(c, &i) % k;
	while (carret->movement < 0)
		carret->movement += MEM_SIZE;
}
