# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/02 16:24:00 by oavelar           #+#    #+#              #
#    Updated: 2021/12/20 21:38:59 by oavelar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#SHELL 		= /bin/bash
NAME 		= ft_containers
RM			= rm -rf

ifeq ($(shell uname), Linux)
 CC = g++
else
 CC = clang++
endif
FLAGS = -Wall -Wextra -Werror -std=c++11 #-std=c++98 -fsanitize=address

INCS_DIR	= Container_Include
MAIN_INC	= -I$(INCS_DIR)
INCS		= $(shell find $(INCS_DIR) -type f -name "*.hpp")

SRCS_DIR 	= Container_Test
SRCS		= $(shell find $(SRCS_DIR) -type f -name "*.cpp")

OBJS		= $(SRCS:%.cpp=%.o)

OK			= [\033[32mOK\033[0m]
RED			= \033[1;31m
MAG			= \033[33;95m
OFF			= \033[0m

all			: $(NAME)

%.o			: %.cpp $(INCS) 
			@$(CC) $(FLAGS) $(MAIN_INC) -c $< -o $@ -MD -g

$(NAME)		: $(OBJS)
			@$(CC) $(FLAGS) $(OBJS) -o $(NAME)
			@echo "Compilation of $(MAG)$(NAME): $(OFF) $(OK)$(OFF)"

clean		:
			@$(RM) $(OBJS)
			@echo "$(RED)Objects deleted!$(OFF)"

fclean		: 
			@$(RM) $(NAME)
			@echo "$(RED)All removed!$(OFF)"

re			: fclean all

.PHONY		: all clean fclean re