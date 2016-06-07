/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 12:56:20 by rfriscca          #+#    #+#             */
/*   Updated: 2016/06/07 13:00:40 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_find_format(char c, va_list valist, t_stock stock)
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
	else
		exit(1);
}
