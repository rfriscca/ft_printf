/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexcaps.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 13:09:23 by rfriscca          #+#    #+#             */
/*   Updated: 2016/05/30 15:56:18 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printhexcaps(int nbr, t_stock stock)
{
	int		spacenum;
	int		size;

	spacenum = 0;
	size = ft_nbrsizehex(nbr);
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
		ft_converttohex(nbr, 1);
	}
	else
	{
		ft_printadd(stock, 'X');
		ft_converttohex(nbr, 1);
		ft_putspace(spacenum);
	}
}
