# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/22 16:45:39 by brivera           #+#    #+#              #
#    Updated: 2025/09/26 17:14:08 by brivera          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := PhoneBook

CC 		:= c++
CFLAGS	:= -Wall -Wextra -Werror -std=c++98

SRCS	:= main.cpp Contact.cpp PhoneBook.cpp PhoneBookInterface.cpp

HEADERS := Contact.hpp PhoneBook.hpp phoneBookInterface.hpp

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

test: fclean 
	$(CXX) $(CXXFLAGS) -DTEST=1 -o $(NAME) *.cpp
	@echo "✅$(GREEN)Compilado en modo TEST $(CLEAR_COLOR)"

.PHONY: all clean fclean re test

.GOAL: all