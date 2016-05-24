/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:04:37 by rfriscca          #+#    #+#             */
/*   Updated: 2016/05/24 16:13:44 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunbr(unsigned int n)
{
	unsigned int	n2;

	n2 = n;
	if (n2 > 9)
	{
		ft_putunbr(n2 / 10);
		ft_putunbr(n2 % 10);
	}
	if (n2 <= 9)
		ft_putchar(n2 + 48);
}

void	ft_printoctal(int nbr, t_stock stock)
{
	int		spacenum;
	int		size;

	spacenum = 0;
	size = ft_nbrsizeoctal(nbr);
	if (stock.size_min > 2147483647)
		size = 0;
	if (stock.size_min > size)
		spacenum = stock.size_min - size;
	if ((stock.flags & 1) == 0)
	{
		if ((stock.flags & 2) == 0)
			ft_putspace(spacenum);
		else
			ft_putzero(spacenum);
		ft_converttooctal(nbr);
	}
	else
	{
		ft_converttooctal(nbr);
		ft_putspace(spacenum);
	}
}

void	ft_printhex(int nbr, t_stock stock, int caps)
{
	int		spacenum;
	int		size;

	spacenum = 0;
	size = ft_nbrsizehex(nbr);
	if (stock.size_min > 2147483647)
		size = 0;
	if (stock.size_min > size)
		spacenum = stock.size_min - size;
	if ((stock.flags & 1) == 0)
	{
		if ((stock.flags & 2) == 0)
			ft_putspace(spacenum);
		else
			ft_putzero(spacenum);
		ft_converttohex(nbr, caps);
	}
	else
	{
		ft_converttohex(nbr, caps);
		ft_putspace(spacenum);
	}
}
