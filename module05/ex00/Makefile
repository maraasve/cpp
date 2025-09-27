# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marieke <marieke@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/10 14:25:08 by maraasve          #+#    #+#              #
#    Updated: 2025/06/18 14:44:55 by marieke          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Bureaucrat
CC = c++
CFLAGS = -Wall -Werror -Wextra -g -fno-limit-debug-info
SRC_DIR = src
SRC_FILES = main.cpp Bureaucrat.cpp
SRC = $(patsubst %, $(SRC_DIR)/%, $(SRC_FILES))
OBJ_DIR = obj
INCL_DIR = incl
INCL_FILES = Bureaucrat.hpp
INCL = $(patsubst %, $(INCL_DIR)/%, $(INCL_FILES))
OBJ = $(SRC_FILES:%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -I$(INCL_DIR)
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