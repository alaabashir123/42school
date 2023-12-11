# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abashir <abashir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/10 15:18:50 by abashir           #+#    #+#              #
#    Updated: 2023/09/20 13:13:29 by abashir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_B = checker

LIBFT = libft

SRC = 	main.c \
		check_args.c \
		free.c \
		utils.c \
		lst_fcn.c \
		operation_1.c \
		operation_2.c \
		operation_3.c \
		create_stack.c \
		sort_choice.c \
		set_params.c \
		swapping.c \
		cost_a.c \
		cost_b.c \
		optimum.c \

SRC_B = check_args.c \
		free.c \
		utils.c \
		lst_fcn.c \
		operation_1.c \
		operation_2.c \
		operation_3.c \
		create_stack.c \
		bonus/checker.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \
		bonus/implement_inst.c \
		bonus/read_inst.c \
		
OBJ = $(SRC:.c=.o)

OBJ_B = $(SRC_B:.c=.o)

ARC = libft/libft.a
CC = cc

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(ARC) -o $(NAME)
	
$(LIBFT):
	cd libft && make

bonus: $(LIBFT) $(OBJ_B)
	$(CC) $(OBJ_B) $(CFLAGS) $(ARC) -o $(NAME_B)
	
clean:
	rm -f -v $(OBJ) $(OBJ_B)
	cd libft && make clean

fclean: clean
	rm -f $(NAME) $(NAME_B)
	cd libft && make fclean

re: fclean all

.PHONY: all clean fclean re libft bonus
