/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 16:11:44 by rfriscca          #+#    #+#             */
/*   Updated: 2016/06/07 13:58:01 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		printnbr_expansion(int size_max, int size)
{
	if (size_max > size)
		size_max -= size;
	return (size_max);
}

void	ft_printnbr(int nbr, t_stock stock)
{
	int		spacenum;
	int		size;

	spacenum = 0;
	size = ft_nbrsize(nbr);
	if (stock.size_min > size && stock.size_min <= 2147483647)
		spacenum = stock.size_min - size;
	if ((stock.flags & 4) == 1)
		spacenum -= 1;
	stock.size_max = printnbr_expansion(stock.size_max, size);
	if ((stock.flags & 1) == 0)
	{
		if ((stock.flags & 2) == 0)
			ft_putspace(spacenum);
		else
			ft_putzero(spacenum, stock, 'd');
		ft_printadd(stock, 'd');
		ft_putnbr(nbr);
	}
	else
	{
		ft_printadd(stock, 'd');
		ft_putnbr(nbr);
		ft_putspace(spacenum);
	}
}
