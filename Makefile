# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/02 16:24:00 by oavelar           #+#    #+#              #
#    Updated: 2022/01/29 21:44:38 by oavelar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_FT 		= ft_containers
NAME_STD		= std_containers
RM				= rm -rf

ifeq ($(shell uname), Linux)
 CC = g++
else
 CC = clang++
endif

FLAGS = -Wall -Wextra -Werror -std=c++98 #-fsanitize=address

INCS_DIR	= Container_Include
MAIN_INC	= -I$(INCS_DIR)
INCS		= $(shell find $(INCS_DIR) -type f -name "*.hpp")

SRCS_DIR 	= Container_Test
SRCS		= $(shell find $(SRCS_DIR) -type f -name "*.cpp")

STD_DIR 	= Container_STD
SRC_STD		= $(shell find $(STD_DIR) -type f -name "*.cpp")

OBJS		= $(SRCS:%.cpp=%.o)

OBJ_STD		= $(SRC_STD:%.cpp=%.o)

OK			= [\033[32mOK\033[0m]
RED			= \033[1;31m
MAG			= \033[33;95m
OFF			= \033[0m

all			: $(NAME_FT) $(NAME_STD)

%.o			: %.cpp $(INCS) 
			@$(CC) $(FLAGS) $(MAIN_INC) -c $< -o $@

$(NAME_FT)		: $(OBJS)
			@$(CC) $(FLAGS) $(OBJS) -o $(NAME_FT)
			@echo "Compilation of $(MAG)$(NAME_FT): $(OFF) $(OK)$(OFF)"

$(NAME_STD)		:	$(OBJ_STD)
			@$(CC) $(FLAGS) $(OBJ_STD) -o $(NAME_STD)
			@echo "Compilation of $(MAG)$(NAME_STD): $(OFF) $(OK)$(OFF)"

clean		:
			@$(RM) $(OBJS) $(OBJ_STD)
			@echo "$(RED)Objects deleted!$(OFF)"

fclean		: 
			@$(RM) $(NAME_FT) $(NAME_STD)
			@echo "$(RED)All removed!$(OFF)"

re			: fclean all

.PHONY		: all clean fclean re
