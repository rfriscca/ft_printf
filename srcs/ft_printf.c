/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 16:42:43 by rfriscca          #+#    #+#             */
/*   Updated: 2016/05/11 16:18:12 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** flags used binary format to save which flags are used 
** 1 = 1, 2 = 10, 4 = 100, 8 = 1000, 16 = 10000
** example : %-+ => 100 + 1 = 101 = 1 + 4 = 5
** if save = 5 then we'll know 2 flags are used - and + (or + and -)
*/

char	flags(char c, char save)
{
	if (c == '-' && (save & 1) != 1)
		save += 1;
	else if (c == '0' && (save & 2) != 1)
		save += 2;
	else if (c == '+' && (save & 4) != 1)
		save += 4;
	else if (c == ' ' && (save & 8) != 1)
		save += 8;
	else if (c == '#' && (save & 16) != 1)
		save += 16;
	else if (c != '-' && c != '0' && c != '+' && c != ' ' && c != '#')
		return (0);
	return (save);
}

int		ft_find_size(const char * restrict format, int *i)
{
	int size;

	size = 0;
	while (format[*i + 1] >= '0' && format[*i + 1] <= '9')
	{
		size = size * 10;
		size += format[*i + 1] - '0';
		++*i;
	}
	return (size);
}

int		event(const char * restrict format, va_list valist, int	i)
{
	int		size_min;
	int		size_max;
	char	save;

	save = 0;
	size_min = 0;
	size_max = 0;
	while (flags(format[i + 1], save))
	{
		save = flags(format[i + 1], save);
		++i;
	}
	size_min = ft_find_size(format, &i);
	if (format[i + 1] == '.')
		++i;
	size_max = ft_find_size(format, &i);
	ft_find_format(format[i + 1], valist);
	i = i + 2;
	return (i);
}

int		ft_printf(const char * restrict format, ...)
{
	va_list	valist;
	int		i;

	i = 0;
	va_start(valist, format);
	while (format[i])
	{
		if (format[i] == '%')
			i = event(format, valist, i);
		ft_putchar(format[i]);
		if (format[i])
			++i;
	}
	va_end(valist);
	return (0);
}
