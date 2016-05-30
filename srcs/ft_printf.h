/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 16:34:58 by rfriscca          #+#    #+#             */
/*   Updated: 2016/05/30 16:31:30 by rfriscca         ###   ########.fr       */
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

# include "ft_print_func.h"

int				ft_printf(char const * restrict format, ...);
int				ft_nbrsize(int nbr);
int				ft_nbrsizeoctal(int nbr);
int				ft_nbrsizehex(int nbr);
void			ft_find_format(char c, va_list valist, t_stock stock);
void			ft_putspace(int n);
void			ft_putzero(int n, t_stock stock, char c);
void			ft_putstrlen(char *str, int i);
void			ft_putunbr(unsigned int n);
void			ft_converttooctal(int num);
void			ft_converttohex(int num, int caps);
void			ft_printadd(t_stock stock, char c);
void			ft_printwstr(wchar_t *str, t_stock stock);
t_stock			data_stock(int size_min, int size_max, char flags);

#endif
