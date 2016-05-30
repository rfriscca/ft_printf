/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_func.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 15:54:00 by rfriscca          #+#    #+#             */
/*   Updated: 2016/05/30 16:32:02 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_FUNC_H

# define FT_PRINT_FUNC_H

void	ft_printchar(char c, t_stock stock);
void	ft_printhexcaps(int nbr, t_stock stock);
void	ft_printoctal(int nbr, t_stock stock);
void	ft_printwstr(wchar_t *str, t_stock stock);
void	ft_printhex(int nbr, t_stock stock);
void	ft_printstr(char *str, t_stock stock);
void	ft_printnbr(int nbr, t_stock stock);
void	ft_printunbr(unsigned int nbr, t_stock stock);

#endif