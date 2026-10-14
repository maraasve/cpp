# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/19 15:56:05 by maraasve          #+#    #+#              #
#    Updated: 2024/09/13 14:18:44 by maraasve         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone
SRC = megaphone.cpp
CC = c++
CFLAGS = -Wall -Werror -Wextra
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