/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 12:56:20 by rfriscca          #+#    #+#             */
/*   Updated: 2016/05/24 16:30:24 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_printstr(char *str, t_stock stock)
{
	int		size;
	int		spacenum;

	size = ft_strlen(str);
	spacenum = 0;
	if (stock.size_min > 2147483647)
		stock.size_min = 0;
	if (stock.size_max < size && stock.size_max != -1)
		size = stock.size_max;
	if (stock.size_min > size)
		spacenum = stock.size_min - size;
	if ((stock.flags & 1) == 1)
	{
		ft_putstrlen(str, size);
		ft_putspace(spacenum);
	}
	else
	{
		if ((stock.flags & 2) == 0)
			ft_putspace(spacenum);
		else
			ft_putzero(spacenum);
		ft_putstrlen(str, size);
	}
}

void		ft_printnbr(int nbr, t_stock stock)
{
	int		spacenum;
	int		size;

	spacenum = 0;
	size = ft_nbrsize(nbr);
	if (stock.size_min > size && stock.size_min < 2147483647)
		spacenum = stock.size_min - size;
	if ((stock.flags & 1) == 0)
	{
		if ((stock.flags & 2) == 0)
			ft_putspace(spacenum);
		else
			ft_putzero(spacenum);
		if ((stock.flags & 4) == 1 && nbr > 0)
			ft_putchar('+');
		ft_putnbr(nbr);
	}
	else
	{
		if ((stock.flags & 4) == 1 && nbr > 0)
			ft_putchar('+');
		ft_putnbr(nbr);
		ft_putspace(spacenum);
	}
}

void		ft_printunbr(unsigned int nbr, t_stock stock)
{
	int		spacenum;
	int		size;

	spacenum = 0;
	size = ft_nbrsize(nbr);
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
		ft_putunbr(nbr);
	}
	else
	{
		ft_putunbr(nbr);
		ft_putspace(spacenum);
	}
}

void		ft_find_format(char c, va_list valist, t_stock stock)
{
	if (c == 's')
		ft_printstr(va_arg(valist, char*), stock);
	else if (c == 'd' || c == 'D' || c == 'i')
		ft_printnbr(va_arg(valist, int), stock);
	else if (c == 'c' || c == 'C')
		ft_printchar(va_arg(valist, int), stock);
	else if (c == 'u' || c == 'U')
		ft_printunbr(va_arg(valist, unsigned int), stock);
	else if (c == 'o' || c == 'O')
		ft_printoctal(va_arg(valist, int), stock);
	else if (c == 'x')
		ft_printhex(va_arg(valist, int), stock, 0);
	else if (c == 'X')
		ft_printhex(va_arg(valist, int), stock, 1);
	else if (c == '%')
		ft_putchar('%');
	else
	{
		ft_putstr("error");
		exit(1);
	}
}
