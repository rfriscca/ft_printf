/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 16:16:54 by rfriscca          #+#    #+#             */
/*   Updated: 2016/06/28 14:44:08 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		printunbr_expansion(int size_max, int size)
{
	if (size_max > size)
		size_max -= size;
	else
		size_max = 0;
	return (size_max);
}

void	ft_printunbr(uintmax_t nbr, t_stock *stock)
{
	int		spacenum;
	int		size;

	size = ft_nbrsize(nbr);
	stock->size_max = printunbr_expansion(stock->size_max, size);
	spacenum = 0 - stock->size_max;
	if (stock->size_min > size && stock->size_min <= 2147483647)
		spacenum += stock->size_min - size;
	if ((stock->flags & 1) == 0)
	{
		if ((stock->flags & 2) == 0)
			ft_putspace(spacenum);
		else
			ft_putzero(spacenum, stock, 'c');
		ft_printadd(stock, 'u');
		ft_putunbr(nbr);
	}
	else
	{
		ft_printadd(stock, 'u');
		ft_putunbr(nbr);
		ft_putspace(spacenum);
	}
	stock->i += spacenum + size;
}
