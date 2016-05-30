/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 16:16:54 by rfriscca          #+#    #+#             */
/*   Updated: 2016/05/30 16:21:15 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printunbr(unsigned int nbr, t_stock stock)
{
	int		spacenum;
	int		size;

	spacenum = 0;
	size = ft_nbrsize(nbr);
	if (stock.size_min > size && stock.size_min <= 2147483647)
		spacenum = stock.size_min - size;
	if ((stock.flags & 1) == 0)
	{
		if ((stock.flags & 2) == 0)
			ft_putspace(spacenum);
		else
			ft_putzero(spacenum, stock, 'c');
		ft_putunbr(nbr);
	}
	else
	{
		ft_putunbr(nbr);
		ft_putspace(spacenum);
	}
}
