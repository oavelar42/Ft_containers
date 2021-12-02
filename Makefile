# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/02 16:24:00 by oavelar           #+#    #+#              #
#    Updated: 2021/12/02 18:29:32 by oavelar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_containers

ifeq ($(shell uname), Linux)
 CC = g++
else
 CC = clang++
endif
FLAGS = -Wall -Wextra -Werror -g3 -std=c++98 #-fsanitize=address

INC_DIR		= Container_Include
TEST_DIR	= Container_Test

INC			= $(shell find $(INC_DIR) -type f -name "*.hpp")
TEST		= $(shell find $(TEST_DIR) -type f -name "*.cpp")

OBJ			= $(TEST:%.cpp=%.o)

OK			= [\033[32mOK\033[0m]
RED			= \033[1;31m
MAG			= \033[33;95m
OFF			= \033[0m

all: $(NAME)

$(NAME):
	@$(CC) $(FLAGS) -I$(INC) -c $< -o $@
	@echo "Compilation of $(MAG)$(NAME): $(OFF) $(OK)$(OFF)"

clean:
	@rm -f $(OBJ)
	@echo "$(RED)Objects deleted!$(OFF)"

fclean: 
	@rm $(NAME) 
	@echo "$(RED)All removed!$(OFF)"

re: fclean all 

.PHONY: all clean fclean re