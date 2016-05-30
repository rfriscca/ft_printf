/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printoctal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 15:47:20 by rfriscca          #+#    #+#             */
/*   Updated: 2016/05/30 15:57:11 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printoctal(int nbr, t_stock stock)
{
	int		spacenum;
	int		size;
	
	spacenum = 0;
	size = ft_nbrsizeoctal(nbr);
	if (stock.size_min > size && stock.size_min <= 2147483647)
		spacenum = stock.size_min - size;
	if ((stock.flags & 16) != 0)
		spacenum -= 1;
	if ((stock.flags & 1) == 0)
	{
		if ((stock.flags & 2) == 0)
			ft_putspace(spacenum);
		else
			ft_putzero(spacenum, stock, 'c');
		ft_printadd(stock, 'o');
		ft_converttooctal(nbr);
	}
	else
	{
		ft_printadd(stock, 'o');
		ft_converttooctal(nbr);
		ft_putspace(spacenum);
	}
}
