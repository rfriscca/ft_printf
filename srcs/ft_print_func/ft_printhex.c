/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 16:00:08 by rfriscca          #+#    #+#             */
/*   Updated: 2016/05/30 16:04:50 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printhex(int nbr, t_stock stock)
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
			ft_putzero(spacenum, stock, 'x');
		if ((stock.flags & 2) == 0)
			ft_printadd(stock, 'x');
		ft_converttohex(nbr, 0);
	}
	else
	{
		ft_printadd(stock, 'x');
		ft_converttohex(nbr, 0);
		ft_putspace(spacenum);
	}
}
