/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 16:06:00 by rfriscca          #+#    #+#             */
/*   Updated: 2016/06/28 14:36:48 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printstr(char *str, t_stock *stock)
{
	int		size;
	int		spacenum;

	size = ft_strlen(str);
	spacenum = 0;
	if (stock->size_max < size && stock->size_max != -1)
		size = stock->size_max;
	if (stock->size_min > size && stock->size_min <= 2147483647)
		spacenum = stock->size_min - size;
	if ((stock->flags & 1) == 1)
	{
		ft_putstrlen(str, size);
		ft_putspace(spacenum);
	}
	else
	{
		if ((stock->flags & 2) == 0)
			ft_putspace(spacenum);
		else
			ft_putzero(spacenum, stock, 'c');
		ft_putstrlen(str, size);
	}
	stock->i += spacenum + size;
}
