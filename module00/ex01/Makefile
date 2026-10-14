# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marieke <marieke@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/03 16:36:13 by maraasve          #+#    #+#              #
#    Updated: 2024/09/17 12:42:55 by marieke          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook
SRC = main.cpp contact.cpp phonebook.cpp strings.cpp
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++11
OBJ_DIR = obj
OBJ = $(SRC:%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo "executable is ready"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "Created obj directory"

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@echo "removed object files"

fclean: clean
	@rm -f $(NAME)
	@echo "removed executable"

re: fclean all

.PHONY: all clean fclean re