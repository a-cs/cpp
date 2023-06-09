# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/18 23:02:15 by acarneir          #+#    #+#              #
#    Updated: 2023/06/09 19:26:10 by acarneir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = phoneBook
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
VALGRIND = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --tool=memcheck -q ./phoneBook

SRC = main.cpp \
		Contact.cpp \
		PhoneBook.cpp
		
INCLUDE = Contact.hpp \
			PhoneBook.hpp

OBJ_DIR = objs
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: %.c $(INCLUDE)
	$(CC) $(FLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

valgrind: all
	@$(VALGRIND)

v: valgrind