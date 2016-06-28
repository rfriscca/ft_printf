/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other_length.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 15:55:48 by rfriscca          #+#    #+#             */
/*   Updated: 2016/06/27 16:09:27 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_l_length(char c, va_list valist, t_stock stock)
{
	if (c == 'd' || c == 'i')
		ft_printnbr((LI)va_arg(valist, LI), stock);
	else if (c == 'u')
		ft_printunbr((ULI)va_arg(valist, ULI), stock);
	else if (c == 'o')
		ft_printoctal((ULI)va_arg(valist, ULI), stock);
	else if (c == 'x')
		ft_printhex((ULI)va_arg(valist, ULI), stock);
	else if (c == 'X')
		ft_printhexcaps((ULI)va_arg(valist, ULI), stock);
}
