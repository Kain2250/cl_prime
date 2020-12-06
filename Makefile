# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kain2250 <kain2250@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/06 17:56:24 by kain2250          #+#    #+#              #
#    Updated: 2020/12/06 19:14:31 by kain2250         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cl_prime
CC = clang
FLAGS = -Wall -Wextra $(LIB_FLAGS)
LIB_FLAGS = -lOpenCL

INCLUDE_DIR = include/
INCLUDE_LIST = main.h

HEADERS = $(addprefix $(INCLUDE_DIR), $(INCLUDE_LIST))
INCLUDES = -I $(INCLUDE_DIR)

SRC_DIR = src/
SRC_LIST = main.c \
		init.c

SRC = $(addprefix $(SRC_DIR), $(SRC_LIST))

OBJ_DIR = objects/
OBJ_LIST = $(patsubst %.c, %.o, $(SRC_LIST))
OBJS = $(addprefix $(OBJ_DIR), $(OBJ_LIST))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): #$(OBJ_DIR) $(OBJS)
	@$(CC) $(FLAGS) $(INCLUDES) $(SRC) -o $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(HEADERS)
	@$(CC) $(FLAGS) $(INCLUDES) $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all
