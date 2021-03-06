/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   what_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 19:55:03 by hlarson           #+#    #+#             */
/*   Updated: 2019/10/06 20:31:32 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	what_arg(char c)
{
	if (c & T_REG)
		return (1);
	else if (c & T_DIR)
		return (2);
	else if (c & T_IND)
		return (3);
	return (-1);
}
