# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/26 14:45:36 by brivera           #+#    #+#              #
#    Updated: 2025/11/29 20:21:44 by brivera          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	:= ex03

CC		:= c++
FLAGS	:= -Wall -Wextra -Werror -std=c++98

SRCS 	:=  main.cpp AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp
HEADERS := 	AMateria.hpp Character.hpp Cure.hpp Ice.hpp ICharacter.hpp IMateriaSource.hpp MateriaSource.hpp
OBJS_DIR 	:= objs
OBJS		:= $(addprefix $(OBJS_DIR)/, $(SRCS:.cpp=.o))

RM := rm -rf

RED			:=	\033[91;1m
GREEN		:=	\033[92;1m
CLEAR_COLOR	:=	\033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled successfully!$(CLEAR_COLOR)"

$(OBJS_DIR)/%.o: %.cpp $(HEADERS)
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS_DIR)/*.o $(OBJS_DIR)
	@echo "$(RED)Object files removed.$(CLEAR_COLOR)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)$(NAME) executable removed.$(CLEAR_COLOR)"

re: fclean all
	@echo "$(GREEN)Recompiled $(NAME).$(CLEAR_COLOR)"

.PHONY: all clean fclean re

.GOAL: all