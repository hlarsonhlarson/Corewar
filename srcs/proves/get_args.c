/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 18:30:24 by hlarson           #+#    #+#             */
/*   Updated: 2019/12/28 15:20:59 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

short					get_dir_two(unsigned char *c, size_t *i)
{
	int				j;
	unsigned char	d[2];

	if (*i >= MEM_SIZE)
		*i = *i % MEM_SIZE;
	ft_bzero(d, 2);
	j = 1;
	while (j != -1)
	{
		d[j] = c[*i];
		j--;
		(*i)++;
		if (*i >= MEM_SIZE)
			*i = *i % MEM_SIZE;
	}
	return (*((short *)d));
}

int						get_dir_one(unsigned char *c, size_t *i)
{
	int				j;
	unsigned char	d[4];

	if (*i >= MEM_SIZE)
		*i = *i % MEM_SIZE;
	ft_bzero(d, 4);
	j = 3;
	while (j != -1)
	{
		d[j] = c[*i];
		j--;
		(*i)++;
		if (*i >= MEM_SIZE)
			*i = *i % MEM_SIZE;
	}
	return (*((int *)d));
}

int						get_reg(unsigned char *c, size_t *i)
{
	char			x;

	if (*i >= MEM_SIZE)
		*i = *i % MEM_SIZE;
	x = c[*i];
	*i = *i + 1;
	return (((int)x));
}

short					get_ind(unsigned char *c, size_t *i)
{
	int				j;
	unsigned char	d[2];

	if (*i >= MEM_SIZE)
		*i = *i % MEM_SIZE;
	ft_bzero(d, 2);
	j = 1;
	while (j != -1)
	{
		d[j] = c[*i];
		j--;
		(*i)++;
		if (*i >= MEM_SIZE)
			*i = *i % MEM_SIZE;
	}
	return (*((short *)d));
}

int						get_arg_for_ind(unsigned char *c,
		t_carret *carret, size_t *i, int ind)
{
	int				j;
	unsigned char	d[4];
	int				k;

	*i = *i;
	k = ind + carret->pos;
	while (k < 0)
		k += MEM_SIZE;
	if (k >= MEM_SIZE)
		k %= MEM_SIZE;
	ft_bzero(d, 4);
	j = 3;
	while (j != -1)
	{
		d[j] = c[k];
		j--;
		(k)++;
		if (k >= MEM_SIZE)
			k = k % MEM_SIZE;
	}
	return (*((int *)d));
}
