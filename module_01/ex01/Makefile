# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/06 12:00:00 by brivera           #+#    #+#              #
#    Updated: 2025/10/06 14:40:08 by brivera          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	:= Moar_brainz!

CC		:= c++
FLAGS	:= -Wall -Wextra -Werror -std=c++98

SRCS 	:= main.cpp Zombie.cpp zombieHorde.cpp
HEADERS := Zombie.hpp colors.hpp

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
