/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 21:47:02 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/02/26 05:58:05 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H

# include "../Libft/includes/libft.h"
# include <stdio.h>

typedef struct			s_work
{
	size_t priority;
	unsigned char	operation;
	void *memory;
	size_t size;
}						t_work;

t_list *queue_add(t_work *work, t_list *queue_lst);
void queue_decrement(t_list *queue);

#endif
