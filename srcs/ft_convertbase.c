/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertbase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 13:30:48 by rfriscca          #+#    #+#             */
/*   Updated: 2016/05/24 13:45:43 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_converttooctal(int num)
{
	if (num)
	{
		ft_converttooctal(num / 8);
		ft_putnbr(num % 8);
	}
}
