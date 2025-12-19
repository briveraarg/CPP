# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/12 16:55:59 by brivera           #+#    #+#              #
#    Updated: 2025/12/19 10:51:18 by brivera          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	:= convert

CC		:= c++
FLAGS	:= -Wall -Wextra -Werror -std=c++98
DEBUG_FLAGS := -DDEBUG

SRCS 	:=  main.cpp ScalarConverter.cpp ScalarPrinter.cpp
HEADERS := 	ScalarConverter.hpp ScalarPrinter.hpp

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