# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/04 20:04:24 by acarneir          #+#    #+#              #
#    Updated: 2023/06/09 19:26:10 by acarneir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = sed
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp

OBJ_DIR = objs
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

clean:
	rm -rf $(OBJ_DIR)
	rm -rf file
	rm -rf file.replace

fclean: clean
	rm -f $(NAME)

re: fclean all