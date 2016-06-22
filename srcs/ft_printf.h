/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 16:34:58 by rfriscca          #+#    #+#             */
/*   Updated: 2016/06/22 14:55:24 by rfriscca         ###   ########.fr       */
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

# define LI long int
# define ULI unsigned long int
# define LLI long long int
# define ULLI unsigned long long int

typedef struct	s_stock
{
	int			size_min;
	int			size_max;
	char		flags;
}				t_stock;

# include "ft_print_func.h"

int				ft_printf(char const *restrict format, ...);
int				ft_nbrsize(int nbr);
int				ft_nbrsizeoctal(int nbr);
int				ft_nbrsizehex(int nbr);
void			ft_find_format(char const *restrict format, va_list valist,
		t_stock stock, int *i);
void			ft_putspace(int n);
void			ft_putzero(int n, t_stock stock, char c);
void			ft_putstrlen(char *str, int i);
void			ft_putunbr(uintmax_t n);
void			ft_converttooctal(uintmax_t num);
void			ft_converttohex(uintmax_t num, int caps);
void			ft_printadd(t_stock stock, char c);
void			ft_printwstr(wchar_t *str, t_stock stock);
void			ft_l_length(char c, va_list valist, t_stock stock);
t_stock			data_stock(int size_min, int size_max, char flags);

#endif
