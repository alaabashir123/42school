# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abashir <abashir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/10 15:18:50 by abashir           #+#    #+#              #
#    Updated: 2023/09/07 12:03:14 by abashir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIBFT = libft

MINILIBX = libmlx

SRC = 	get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \
		create_array.c \
		utils.c \
		map_checking_1.c \
		map_checking_2.c \
		error_handling.c \
		events.c \
		init_game.c \
		movement.c \
		main.c
		
OBJ = $(SRC:.c=.o)

ARC = 00-libft/libft.a minilibx/libmlx.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

FFLAGS = -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MINILIBX)
	$(CC) $(CFLAGS) $(FFLAGS) $(ARC) $(OBJ) -o $(NAME)

$(LIBFT):
	cd 00-libft && make

$(MINILIBX):
	cd minilibx && make

clean:
	rm -f -v $(OBJ)
	cd 00-libft && make clean
	cd minilibx && make clean
	
fclean: clean
	rm -f $(NAME)
	cd 00-libft && make fclean
	cd minilibx && make fclean

re: fclean all