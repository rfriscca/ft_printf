/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhhhex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 14:17:34 by rfriscca          #+#    #+#             */
/*   Updated: 2016/06/16 14:30:43 by rfriscca         ###   ########.fr       */
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

void	ft_printhhhex(char nbr, t_stock stock)
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
			ft_putzero(spacenum, stock, 'x');
		if ((stock.flags & 2) == 0)
			ft_printadd(stock, 'x');
		ft_converttohex((int)nbr, 0);
	}
	else
	{
		ft_printadd(stock, 'x');
		ft_converttohex((int)nbr, 0);
		ft_putspace(spacenum);
	}
}
