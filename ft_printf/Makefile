# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abashir <abashir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/10 15:00:44 by abashir           #+#    #+#              #
#    Updated: 2023/08/07 10:15:45 by abashir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc

CFLAGS = -Wall -Werror -Wextra -I ./include

SRC := src/ft_check_param.c src/ft_printf_x.c src/ft_printf_p.c src/ft_nbr_len.c src/ft_printf_dec.c src/ft_printf_int.c \
		src/ft_printf_str.c src/ft_putchar_fd.c src/ft_putnbr_fd.c src/ft_strlen.c \
		src/ft_printf.c  

OBJS = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all