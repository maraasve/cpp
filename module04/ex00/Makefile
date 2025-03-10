# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/10 14:25:08 by maraasve          #+#    #+#              #
#    Updated: 2025/03/10 17:40:10 by maraasve         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Animal
CC = c++
CFLAGS = -Wall -Werror -Wextra
SRC_DIR = src
SRC_FILES = main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongDog.cpp WrongCat.cpp
SRC = $(patsubst %, $(SRC_DIR)/%, $(SRC_FILES))
OBJ_DIR = obj
INCL_DIR = incl
INCL_FILES = Animal.hpp Dog.hpp Cat.hpp WrongAnimal.hpp WrongDog.hpp WrongCat.hpp
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