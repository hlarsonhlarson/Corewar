/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 17:24:31 by hlarson           #+#    #+#             */
/*   Updated: 2019/12/28 17:35:24 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	print_hex_four(int n)
{
	char				*c;
	int					i;
	char				*x;

	ft_putstr("0x");
	i = 3;
	c = "0123456789abcdef";
	x = ft_strdup("0000");
	while (n)
	{
		x[i] = c[n % 16];
		n /= 16;
		i--;
	}
	ft_putstr(x);
	free(x);
	ft_putstr(" :");
}

void	print_hex_two(unsigned char n)
{
	char				*c;
	int					i;
	char				*x;

	i = 1;
	c = "0123456789abcdef";
	x = ft_strdup("00");
	while (n)
	{
		x[i] = c[n % 16];
		n /= 16;
		i--;
	}
	ft_putstr(x);
	free(x);
}
