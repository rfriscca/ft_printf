/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertbase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 13:30:48 by rfriscca          #+#    #+#             */
/*   Updated: 2016/06/22 13:54:09 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_converttooctal(uintmax_t num)
{
	if (num)
	{
		ft_converttooctal(num / 8);
		ft_putnbr(num % 8);
	}
}

void	ft_hex(int num)
{
	if (num == 10)
		ft_putchar('a');
	else if (num == 11)
		ft_putchar('b');
	else if (num == 12)
		ft_putchar('c');
	else if (num == 13)
		ft_putchar('d');
	else if (num == 14)
		ft_putchar('e');
	else
		ft_putchar('f');
}

void	ft_hexcaps(int num)
{
	if (num == 10)
		ft_putchar('A');
	else if (num == 11)
		ft_putchar('B');
	else if (num == 12)
		ft_putchar('C');
	else if (num == 13)
		ft_putchar('D');
	else if (num == 14)
		ft_putchar('E');
	else
		ft_putchar('F');
}

void	ft_converttohex(uintmax_t num, int caps)
{
	if (num)
	{
		ft_converttohex(num / 16, caps);
		if (num % 16 < 10)
			ft_putnbr(num % 16);
		else if (caps == 0)
			ft_hex(num % 16);
		else
			ft_hexcaps(num % 16);
	}
}
