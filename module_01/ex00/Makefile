# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/26 15:37:41 by brivera           #+#    #+#              #
#    Updated: 2025/09/26 15:42:51 by brivera          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := BraiiiiiiinnnzzzZ

CC		:= cc++
FLAGS	:= -Wall -Wextra -Werror -std=c++98

SRCS 	:= 
HEADERS :=

OBJS_DIR 	:= objs
OBJS		:= $(addprefix $(OBJS_DIR)/, $(SRCS:.cpp=.o))

RM := rm -rf

RED			:=	\033[91;1m
GREEN		:=	\033[92;1m
CLEAR_COLOR	:=	\033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled successfully!$(CLEAR_COLOR)"

$(OBJS_DIR)/%.o: %.cpp $(HEADERS)
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

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