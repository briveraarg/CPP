# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/25 17:08:51 by brivera           #+#    #+#              #
#    Updated: 2025/12/09 21:38:23 by brivera          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	 	:= ex03

CC			:= c++
FLAGS		:= -Wall -Wextra -Werror -std=c++98
DEBUG_FLAGS := -DDEBUG

SRCS 	:=  main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp \
			RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp

HEADERS := 	Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp \
			RobotomyRequestForm.hpp PresidentialPardonForm.hpp Intern.hpp

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

debug: FLAGS += $(DEBUG_FLAGS)
debug: re

.PHONY: all clean fclean re debug

.GOAL: all