/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 16:11:44 by rfriscca          #+#    #+#             */
/*   Updated: 2016/06/22 13:42:20 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putintmaxnbr(intmax_t n)
{
	uintmax_t	n2;

	if (n < 0)
	{
		ft_putchar('-');
		n2 = -n;
	}
	else
		n2 = n;
	if (n2 > 9)
	{
		ft_putintmaxnbr(n2 / 10);
		ft_putintmaxnbr(n2 % 10);
	}
	else
		ft_putchar(n2 + 48);
}

int		printnbr_expansion(int size_max, int size)
{
	if (size_max > size)
		size_max -= size;
	else
		size_max = 0;
	return (size_max);
}

void	ft_printnbr(intmax_t nbr, t_stock stock)
{
	int		spacenum;
	int		size;

	size = ft_nbrsize(nbr);
	stock.size_max = printnbr_expansion(stock.size_max, size);
	spacenum = 0 - stock.size_max;
	if (stock.size_min > size && stock.size_min <= 2147483647)
		spacenum += stock.size_min - size;
	if ((stock.flags & 4) != 0)
		spacenum -= 1;
	if ((stock.flags & 1) == 0)
	{
		if ((stock.flags & 2) == 0)
			ft_putspace(spacenum);
		else
			ft_putzero(spacenum, stock, 'd');
		ft_printadd(stock, 'd');
		ft_putintmaxnbr(nbr);
	}
	else
	{
		ft_printadd(stock, 'd');
		ft_putintmaxnbr(nbr);
		ft_putspace(spacenum);
	}
}
