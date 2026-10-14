# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/13 16:53:22 by maraasve          #+#    #+#              #
#    Updated: 2024/09/13 16:54:40 by maraasve         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = replace
CC = c++
SRC = main.cpp
OBJ_DIR = obj
OBJ = $(SRC:%.cpp=$(OBJ_DIR)/%.o)
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo "executable is ready"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "created object directory"

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@echo "removed object files"

fclean: clean
	@rm -rf $(NAME)
	@echo "removed executable"

re: fclean all

.PHONY: all clean fclean re