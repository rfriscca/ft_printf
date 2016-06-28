/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 15:10:13 by rfriscca          #+#    #+#             */
/*   Updated: 2016/06/28 14:39:30 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_printchar(char c, t_stock *stock)
{
	int		size;
	int		spacenum;

	size = 1;
	spacenum = 0;
	if (stock->size_min > 2147483647)
		stock->size_min = 0;
	if (stock->size_min > size)
		spacenum = stock->size_min - size;
	if ((stock->flags & 1) == 1)
	{
		ft_putchar(c);
		ft_putspace(spacenum);
	}
	else
	{
		if ((stock->flags & 2) == 0)
			ft_putspace(spacenum);
		else
			ft_putzero(spacenum, stock, 'c');
		ft_putchar(c);
	}
	stock->i += spacenum + 1;
}
