# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marieke <marieke@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/10 14:25:08 by maraasve          #+#    #+#              #
#    Updated: 2025/10/11 16:11:31 by marieke          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = abomination
CC = c++
OBJ_DIR = obj
INCL_DIR = incl
INCL_FILES = MutantStack.hpp
INCL = $(patsubst %, $(INCL_DIR)/%, $(INCL_FILES))
SRC_DIR = src
SRC_FILES = main.cpp MutantStack.cpp
CFLAGS = -Wall -Werror -Wextra -I$(INCL_DIR)
SRC = $(patsubst %, $(SRC_DIR)/%, $(SRC_FILES))
OBJ = $(SRC_FILES:%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo "Executable is ready"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(INCL) | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I$(INCL_DIR) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re