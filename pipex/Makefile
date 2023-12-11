# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abashir <abashir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/10 15:18:50 by abashir           #+#    #+#              #
#    Updated: 2023/10/10 10:40:35 by abashir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

LIBFT = libft

SRC = 	main.c \
		parse_args.c \
		parse_pipes.c \
		exec_pipes.c \
		utils.c \
		free.c \
		error.c \

SRC_B = bonus/main_bonus.c \
		bonus/parse_args_bonus.c \
		bonus/parse_pipes_bonus.c \
		bonus/exec_pipes_bonus.c \
		bonus/utils_bonus.c \
		bonus/free_bonus.c \
		bonus/error_bonus.c \
		bonus/ft_here_doc.c \
		libs/get_next_line/get_next_line.c \
		libs/get_next_line/get_next_line_utils.c \

OBJ = $(SRC:.c=.o)

OBJ_B = $(SRC_B:.c=.o)

ARC = libs/libft/libft.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(ARC) -o $(NAME)
	
$(LIBFT):
	cd libs/libft && make

bonus: $(LIBFT) $(OBJ_B)
	$(CC) $(OBJ_B) $(CFLAGS) $(ARC) -o $(NAME)
	
clean:
	cd libs/libft && make clean
	rm -f -v $(OBJ) $(OBJ_B)

fclean: clean
	rm -f $(NAME)
	cd libs/libft && make fclean

re: fclean all

.PHONY: all clean fclean re libft bonus
