/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 16:43:15 by rfriscca          #+#    #+#             */
/*   Updated: 2016/06/14 15:15:21 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_nbrsize(int nbr)
{
	int		i;

	i = 1;
	while ((nbr = nbr / 10))
		++i;
	return (i);
}

int		ft_nbrsizeoctal(int nbr)
{
	int		i;

	i = 1;
	while ((nbr = nbr / 8))
		++i;
	return (i);
}

int		ft_nbrsizehex(int nbr)
{
	int		i;

	i = 1;
	while ((nbr = nbr / 16))
		++i;
	return (i);
}
