/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printadd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 16:52:33 by rfriscca          #+#    #+#             */
/*   Updated: 2016/05/27 12:44:43 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printadd(t_stock stock, char c)
{
	if ((stock.flags & 4) != 0 && c == 'd')
		ft_putchar('+');
	if ((stock.flags & 16) != 0 && c == 'o')
		ft_putchar('0');
	if ((stock.flags & 16) != 0 && c == 'x')
		ft_putstr("0x");
}
