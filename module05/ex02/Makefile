# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marieke <marieke@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/10 14:25:08 by maraasve          #+#    #+#              #
#    Updated: 2025/10/04 12:38:22 by marieke          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Forms
CC = c++
OBJ_DIR = obj
INCL_DIR = incl
INCL_FILES = Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp PresidentialPardonForm.hpp intern.hpp colors.hpp
INCL = $(patsubst %, $(INCL_DIR)/%, $(INCL_FILES))
SRC_DIR = src
SRC_FILES = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp intern.cpp
CFLAGS = -Wall -Werror -Wextra -g -fno-limit-debug-info
SRC = $(patsubst %, $(SRC_DIR)/%, $(SRC_FILES))
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
	@rm -f *_shrubbery

re: fclean all

.PHONY: all clean fclean re