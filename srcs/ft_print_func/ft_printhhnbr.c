/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhhnbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 15:07:29 by rfriscca          #+#    #+#             */
/*   Updated: 2016/06/14 15:35:07 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthhnbr(char nbr)
{
	unsigned char	n2;

	if (nbr >= 0)
		n2 = nbr;
	if (nbr < 0)
	{
		ft_putchar('-');
		n2 = -nbr;
	}
	if (n2 > 9)
	{
		ft_puthhnbr(n2 / 10);
		ft_puthhnbr(n2 % 10);
	}
	if (n2 <= 9)
		ft_putchar(n2 + 48);
}

int		ft_hh_nbr_size(char nbr)
{
	int		i;

	i = 1;
	while ((nbr = nbr / 10))
		++i;
	return (i);
}

int		printhhnbr_expansion(int size_max, int size)
{
	if (size_max > size)
		size_max -= size;
	else
		size_max = 0;
	return (size_max);
}

void	ft_printhhnbr(char nbr, t_stock stock)
{
	int		spacenum;
	int		size;

	size = ft_hh_nbr_size(nbr);
	stock.size_max = printhhnbr_expansion(stock.size_max, size);
	spacenum = 0 - stock.size_max;
	if (stock.size_min > size && stock.size_min <= 2147483647)
		spacenum += stock.size_min - size;
	if ((stock.flags & 4) != 0)
		spacenum -= 1;
	if ((stock.flags & 1) == 0)
	{
		if ((stock.flags & 2) == 0)
			ft_putspace(spacenum);
		else
			ft_putzero(spacenum, stock, 'd');
		ft_printadd(stock, 'd');
		ft_puthhnbr(nbr);
	}
	else
	{
		ft_printadd(stock, 'd');
		ft_puthhnbr(nbr);
		ft_putspace(spacenum);
	}
}
