/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putspace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 14:29:05 by rfriscca          #+#    #+#             */
/*   Updated: 2016/05/24 16:13:14 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstrlen(char *str, int i)
{
	int		j;

	j = 0;
	while (j < i)
	{
		ft_putchar(str[j]);
		++j;
	}
}

void	ft_putzero(int n)
{
	while (n > 0)
	{
		ft_putchar('0');
		--n;
	}
}

void	ft_putspace(int n)
{
	while (n > 0)
	{
		ft_putchar(' ');
		--n;
	}
}
