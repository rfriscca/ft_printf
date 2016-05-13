/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 12:56:20 by rfriscca          #+#    #+#             */
/*   Updated: 2016/05/13 15:32:31 by rfriscca         ###   ########.fr       */
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
	if ((stock.flags & 1) == 0)
	{
		if ((stock.flags & 2) == 0)
			ft_putspace(spacenum);
		else
			ft_putzero(spacenum);
		ft_putstrlen(str, size);
	}
	else
	{
		ft_putstrlen(str, size);
		ft_putspace(spacenum);
	}
}

void		ft_find_format(char c, va_list valist, t_stock stock)
{
	if (c == 's')
		ft_printstr(va_arg(valist, char*), stock);
	else if (c == 'd' || c == 'D' || c == 'i')
		ft_putnbr(va_arg(valist, int));
	else
	{
		ft_putstr("error");
		exit (1);
	}
}
