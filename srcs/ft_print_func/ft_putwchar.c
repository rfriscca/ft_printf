/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 11:44:57 by rfriscca          #+#    #+#             */
/*   Updated: 2016/06/07 12:47:45 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	create_bin(unsigned int *bin, wchar_t c)
{
	if (c <= 127)
		bin[0] = 0x7F & c;
	else if (c > 127 && c <= 2047)
	{
		bin[0] = 128 + (0x3F & c);
		bin[1] = 192 + ((0x7C0 & c) >> 6);
	}
	else if (c > 2047 && c <= 65535)
	{
		bin[0] = 128 + (0x3F & c);
		bin[1] = 128 + ((0xFC0 & c) >> 6);
		bin[2] = 224 + ((0xF000 & c) >> 12);
	}
	else if (c > 65535)
	{
		bin[0] = 128 + (0x3F & c);
		bin[1] = 128 + ((0xFC0 & c) >> 6);
		bin[2] = 128 + ((0x3F000 & c) >> 12);
		bin[3] = 240 + ((0x1C0000 & c) >> 18);
	}
}

void	ft_putwchar(wchar_t c)
{
	unsigned int	*bin;

	bin = (unsigned int*)malloc(sizeof(*bin) * 4);
	bin[0] = 0;
	bin[1] = 0;
	bin[2] = 0;
	bin[3] = 0;
	create_bin(bin, c);
	write(1, &bin[3], 1);
	write(1, &bin[2], 1);
	write(1, &bin[1], 1);
	write(1, &bin[0], 1);
	free(bin);
}
