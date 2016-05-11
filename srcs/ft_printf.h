/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 16:34:58 by rfriscca          #+#    #+#             */
/*   Updated: 2016/05/10 15:46:17 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

// delete this later
# include <stdio.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_isdigit(char c);
int		ft_printf(char const * restrict format, ...);
int		ft_atoi(const char *str);

#endif
