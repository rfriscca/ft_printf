/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printwchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 12:55:53 by rfriscca          #+#    #+#             */
/*   Updated: 2016/06/28 14:38:02 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printwchar(wchar_t c, t_stock *stock)
{
	int		size;
	int		spacenum;

	size = 1;
	spacenum = 0;
	if (stock->size_min > size && stock->size_min < 2147483647)
		spacenum = stock->size_min - size;
	if ((stock->flags & 1) == 1)
	{
		ft_putwchar(c);
		ft_putspace(spacenum);
	}
	else
	{
		if ((stock->flags & 2) == 0)
			ft_putspace(spacenum);
		else
			ft_putzero(spacenum, stock, 'c');
		ft_putwchar(c);
	}
	stock->i += spacenum + size;
}
