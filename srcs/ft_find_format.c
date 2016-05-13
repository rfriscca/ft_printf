/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 12:56:20 by rfriscca          #+#    #+#             */
/*   Updated: 2016/05/13 13:13:01 by rfriscca         ###   ########.fr       */
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
	while (spacenum > 0)
	{
		ft_putchar(' ');
		--spacenum;
	}
	while (i < size)
	{
		ft_putchar(str[i]);
		++i;
	}
}

void		ft_find_format(char c, va_list valist, int size_min, int size_max)
{
	if (c == 's')
		ft_printstr(va_arg(valist, char*), size_min, size_max);
	if (c == 'd' || c == 'D' || c == 'i')
		ft_putnbr(va_arg(valist, int));
}
