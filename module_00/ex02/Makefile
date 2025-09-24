# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/23 20:45:00 by brivera           #+#    #+#              #
#    Updated: 2025/09/24 12:44:28 by brivera          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := account

CC 		:= c++
CFLAGS	:= -Wall -Wextra -Werror -std=c++98

SRCS	:= tests.cpp Account.cpp

HEADERS := Account.hpp

OBJS_DIR := objs
OBJS := $(addprefix $(OBJS_DIR)/, $(SRCS:.cpp=.o))

RM := rm -rf

GREEN := \033[0;32m
RED := \033[0;31m
CLEAR_COLOR := \033[0m

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

diff_ignore:
	./$(NAME) > myfile
	@if diff --ignore-matching-lines='^\[[0-9]\{8\}_[0-9]\{6\}\]' 19920104_091532.log myfile > /dev/null; then \
		echo "✅ Files match (ignoring timestamp)"; \
	else \
		echo "❌ Differences found:"; \
		diff --ignore-matching-lines='^\[[0-9]\{8\}_[0-9]\{6\}\]' 19920104_091532.log myfile; \
	fi
	@$(RM) myfile

.PHONY: all clean fclean re test diff_ignore

.GOAL: all
