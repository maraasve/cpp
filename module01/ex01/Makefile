# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marieke <marieke@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/05 17:48:26 by marieke           #+#    #+#              #
#    Updated: 2024/09/06 12:02:38 by marieke          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = zombieHorde
SRC = main.cpp Zombie.cpp zombieHorde.cpp
OBJ_DIR = obj
OBJ = $(SRC:%.cpp=$(OBJ_DIR)/%.o)
CC = c++
CFLAGS = -Wall -Werror -Wextra

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

re: clean fclean all

.PHONY: all clean fclean re