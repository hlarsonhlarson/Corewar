/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 18:00:08 by hlarson           #+#    #+#             */
/*   Updated: 2019/09/14 18:54:15 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H
# include "op.h"
# include "../Libft/libft.h"

typedef struct	s_map
{
	char	**ch_names;
	size_t	names_iterator;
	int		dump;
	int		d;
	int		v;
}				t_map;

#endif
