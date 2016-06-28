# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/27 16:12:10 by rfriscca          #+#    #+#              #
#    Updated: 2016/06/27 16:48:17 by rfriscca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror
LIBRARY = -Llibft/ -lft
INCLUDES = -I libft -I srcs -I srcs/ft_print_func
SRCS_DIR = srcs
PRINTFUNC_DIR = srcs/ft_print_func
SRCS = ft_convertbase.c		\
	   ft_nbrsize.c			\
	   ft_printf.c			\
	   ft_putspace.c		\
	   data_stock.c			\
	   ft_find_format.c		\
	   ft_other_length.c	\
	   ft_printadd.c		\
	   ft_putunbr.c
PRINTFUNC = ft_printhex.c		\
			ft_printnbr.c		\
			ft_printstr.c		\
			ft_printwchar.c		\
			ft_putwchar.c		\
			ft_printchar.c		\
			ft_printhexcaps.c	\
			ft_printoctal.c		\
			ft_printunbr.c		\
			ft_printwstr.c
OBJ = $(SRCS:.c=.o)
OBJ2 = $(PRINTFUNC:.c=.o)
OBJ_LIB = libft/ft_putchar.o	\
		libft/ft_putnbr.o		\
		libft/ft_putstr.o		\
		libft/ft_strlen.o	
NAME = libftprintf.a
LIBFT_DIR = libft

all : LIBFT $(NAME)

LIBFT : 
	make -C $(LIBFT_DIR)

$(NAME) : $(OBJ) $(OBJ2)
	ar rc $(NAME) $(OBJ) $(OBJ2) $(OBJ_LIB)
	ranlib $(NAME)
	
%.o : $(SRCS_DIR)/%.c
	gcc $(FLAGS) -c $< $(INCLUDES)

%.o : $(PRINTFUNC_DIR)/%.c
	gcc $(FLAGS) -c $< $(INCLUDES)

clean :
	rm -f $(OBJ)
	rm -f $(OBJ2)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re LIBFT
