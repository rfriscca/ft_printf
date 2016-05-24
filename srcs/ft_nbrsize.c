/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 16:43:15 by rfriscca          #+#    #+#             */
/*   Updated: 2016/05/24 13:53:10 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_nbrsize(int nbr)
{
	int		i;

	i = 0;
	while (nbr)
	{
		nbr = nbr / 10;
		++i;
	}
	return (i);
}

int		ft_nbrsizeoctal(int nbr)
{
	int		i;

	i = 0;
	while (nbr)
	{
		nbr = nbr / 8;
		++i;
	}
	return (i);
}
