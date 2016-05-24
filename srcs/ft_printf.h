/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 16:34:58 by rfriscca          #+#    #+#             */
/*   Updated: 2016/05/24 13:59:42 by rfriscca         ###   ########.fr       */
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
void			ft_find_format(char c, va_list valist, t_stock stock);
void			ft_putspace(int n);
void			ft_putzero(int n);
void			ft_putstrlen(char *str, int i);
void			ft_putunbr(unsigned int n);
void			ft_printchar(char c, t_stock stock);
void			ft_converttooctal(int num);
void			ft_printoctal(int nbr, t_stock stock);
t_stock			data_stock(int size_min, int size_max, char flags);

#endif
