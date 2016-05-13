/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 12:56:20 by rfriscca          #+#    #+#             */
/*   Updated: 2016/05/13 14:42:59 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_printstr(char *str, int size_min, int size_max)
{
	int		size;
	int		spacenum;
	int		i;

	size = ft_strlen(str);
	spacenum = 0;
	i = 0;
	if (size_min > 2147483647)
		size_min = 0;
	if (size_max < size && size_max != -1)
		size = size_max;
	if (size_min > size)
		spacenum = size_min - size;
	ft_putspace(spacenum);
	while (i < size)
	{
		ft_putchar(str[i]);
		++i;
	}
}

void		ft_find_format(char c, va_list valist, t_stock stock)
{
	if (c == 's')
		ft_printstr(va_arg(valist, char*), stock.size_min, stock.size_max);
	if (c == 'd' || c == 'D' || c == 'i')
		ft_putnbr(va_arg(valist, int));
}
