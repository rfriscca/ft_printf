/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printwstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 15:30:58 by rfriscca          #+#    #+#             */
/*   Updated: 2016/05/30 15:57:53 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_wstrlen(wchar_t *str)
{
	int		i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

void	ft_putwstrlen(wchar_t *str, int size)
{
	int		i;

	i = 0;
	while (i < size && str[i])
	{
		write(1, &str[i], 1);
		++i;
	}
}

void	ft_printwstr(wchar_t *str, t_stock stock)
{
	int		size;
	int		spacenum;

	size = ft_wstrlen(str);
	spacenum = 0;
	if (stock.size_max < size && stock.size_max != -1)
		size = stock.size_max;
	if (stock.size_min > size && stock.size_min <= 2147483647)
		spacenum = stock.size_min - size;
	if ((stock.flags & 1) == 1)
	{
		ft_putwstrlen(str, size);
		ft_putspace(spacenum);
	}
	else
	{
		if ((stock.flags & 2) == 0)
			ft_putspace(spacenum);
		else
			ft_putzero(spacenum, stock, 'c');
		ft_putwstrlen(str, size);
	}
}
