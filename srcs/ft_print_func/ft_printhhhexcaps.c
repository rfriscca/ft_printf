/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhhhexcaps.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 14:51:54 by rfriscca          #+#    #+#             */
/*   Updated: 2016/06/16 15:17:34 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_hhnbrsizehex(char nbr)
{
	int		i;

	i = 1;
	while ((nbr = nbr / 16))
		++i;
	return (i);
}

void	ft_printhhhexcaps(char nbr, t_stock stock)
{
	int		spacenum;
	int		size;

	spacenum = 0;
	size = ft_hhnbrsizehex(nbr);
	if (stock.size_min > size && stock.size_min <= 2147483647)
		spacenum = stock.size_min - size;
	if ((stock.flags & 16) != 0)
		spacenum -= 2;
	if ((stock.flags & 1) == 0)
	{
		if ((stock.flags & 2) == 0)
			ft_putspace(spacenum);
		else
			ft_putzero(spacenum, stock, 'X');
		if ((stock.flags & 2) == 0)
			ft_printadd(stock, 'X');
		ft_converttohex((int)nbr, 1);
	}
	else
	{
		ft_printadd(stock, 'X');
		ft_converttohex((int)nbr, 1);
		ft_putspace(spacenum);
	}
}
