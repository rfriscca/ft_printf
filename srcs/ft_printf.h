/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 16:34:58 by rfriscca          #+#    #+#             */
/*   Updated: 2016/05/27 12:59:39 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"


// delete this later
# include <stdio.h>

typedef struct	s_stock
{
	int			size_min;
	int			size_max;
	char		flags;
}				t_stock;

int				ft_printf(char const * restrict format, ...);
int				ft_nbrsize(int nbr);
int				ft_nbrsizeoctal(int nbr);
int				ft_nbrsizehex(int nbr);
void			ft_find_format(char c, va_list valist, t_stock stock);
void			ft_putspace(int n);
void			ft_putzero(int n, t_stock stock, char c);
void			ft_putstrlen(char *str, int i);
void			ft_putunbr(unsigned int n);
void			ft_printchar(char c, t_stock stock);
void			ft_converttooctal(int num);
void			ft_converttohex(int num, int caps);
void			ft_printoctal(int nbr, t_stock stock);
void			ft_printhex(int nbr, t_stock stock, int caps);
void			ft_printadd(t_stock stock, char c);
t_stock			data_stock(int size_min, int size_max, char flags);

#endif
