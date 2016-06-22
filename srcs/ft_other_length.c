/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other_length.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 15:55:48 by rfriscca          #+#    #+#             */
/*   Updated: 2016/06/22 14:34:26 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_l_length(char c, va_list valist, t_stock stock)
{
	if (c == 'd' || c == 'i')
		ft_printnbr((LI)va_arg(valist, LI), stock);
	if (c == 'u')
		ft_printunbr((ULI)va_arg(valist, ULI), stock);
	if (c == 'o')
		ft_printoctal((ULI)va_arg(valist, ULI), stock);
	if (c == 'x')
		ft_printhex((ULI)va_arg(valist, ULI), stock);
	if (c == 'X')
		ft_printhexcaps((ULI)va_arg(valist, ULI), stock);
}
