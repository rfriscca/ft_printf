/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhhunbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 13:35:37 by rfriscca          #+#    #+#             */
/*   Updated: 2016/06/16 14:05:03 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_hhunbrsize(unsigned char nbr)
{
	int		i;

	i = 1;
	while ((nbr = nbr / 10))
		++i;
	return (i);
}

void	ft_puthhunbr(unsigned char nbr)
{
	if (nbr > 9)
	{
		ft_puthhunbr(nbr / 10);
		ft_puthhunbr(nbr % 10);
	}
	if (nbr <= 9)
		ft_putchar(nbr + 48);
}

int		printhhunbr_expansion(int size_max, int size)
{
	if (size_max > size)
		size_max -= size;
	else
		size_max = 0;
	return (size_max);
}

void	ft_printhhunbr(unsigned char nbr, t_stock stock)
{
	int		spacenum;
	int		size;

	size = ft_hhunbrsize(nbr);
	stock.size_max = printhhunbr_expansion(stock.size_max, size);
	spacenum = 0 - stock.size_max;
	if (stock.size_min > size && stock.size_min <= 2147483647)
		spacenum += stock.size_min -size;
	if ((stock.flags & 1) == 0)
	{
		if ((stock.flags & 2) == 0)
			ft_putspace(spacenum);
		else
			ft_putzero(spacenum, stock, 'c');
		ft_printadd(stock, 'u');
		ft_puthhunbr(nbr);
	}
	else
	{
		ft_printadd(stock, 'u');
		ft_puthhunbr(nbr);
		ft_putspace(spacenum);
	}
}
