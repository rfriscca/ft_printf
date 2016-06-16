/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 12:56:20 by rfriscca          #+#    #+#             */
/*   Updated: 2016/06/16 14:41:57 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_no_length(char c, va_list valist, t_stock stock)
{
	if (c == 's')
		ft_printstr(va_arg(valist, char*), stock);
	else if (c == 'd' || c == 'D' || c == 'i')
		ft_printnbr(va_arg(valist, int), stock);
	else if (c == 'c')
		ft_printchar(va_arg(valist, int), stock);
	else if (c == 'u' || c == 'U')
		ft_printunbr(va_arg(valist, unsigned int), stock);
	else if (c == 'o' || c == 'O')
		ft_printoctal(va_arg(valist, int), stock);
	else if (c == 'x')
		ft_printhex(va_arg(valist, int), stock);
	else if (c == 'X')
		ft_printhexcaps(va_arg(valist, int), stock);
	else if (c == '%')
		ft_putchar('%');
	else if (c == 'S')
		ft_printwstr(va_arg(valist, wchar_t*), stock);
	else if (c == 'C')
		ft_printwchar(va_arg(valist, wchar_t), stock);
}

void		ft_hh_length(char c, va_list valist, t_stock stock)
{
	if (c == 'd' || c == 'D' || c == 'i')
		ft_printhhnbr(va_arg(valist, int), stock);
	if (c == 'u' || c == 'U')
		ft_printhhunbr(va_arg(valist, unsigned int), stock);
	if (c == 'x')
		ft_printhhhex(va_arg(valist, int), stock);
}

void		ft_h_length(char c, va_list valist, t_stock stock)
{
}

void		ft_find_format(char const *restrict format, va_list valist,
		t_stock stock, int *i)
{
	if (format[0] == 'h')
	{
		if (format[1] == 'h')
		{
			ft_hh_length(format[2], valist, stock);
			++*i;
		}
		ft_h_length(format[1], valist, stock);
		++*i;
	}
	else
		ft_no_length(format[0], valist, stock);
}
