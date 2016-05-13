/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_stock.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 14:35:34 by rfriscca          #+#    #+#             */
/*   Updated: 2016/05/13 14:41:02 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_stock		data_stock(int size_min, int size_max, char flags)
{
	t_stock stock;

	stock.size_min = size_min;
	stock.size_max = size_max;
	stock.flags = flags;
	return (stock);
}
