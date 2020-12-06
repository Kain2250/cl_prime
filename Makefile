# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kain2250 <kain2250@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/06 17:56:24 by kain2250          #+#    #+#              #
#    Updated: 2020/12/06 20:52:00 by kain2250         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cl_prime
CC = clang
FLAGS_GISTAPO = -Wall -Wextra -Werror
FLAGS = #$(FLAGS_GISTAPO)
LIB_FLAGS := -lft

# Флаги компиляции:
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	LIB_FLAGS += -lOpenCL
endif
ifeq ($(UNAME_S),Darwin)
	LIB_FLAGS += -framework OpenCL
endif

LIBFT_DIR = libft/
LIBFT_INCLUDE_DIR = $(LIBFT_DIR)includes
LIBS = -L $(LIBFT_DIR)

INCLUDE_DIR = include/
INCLUDE_LIST = main.h

HEADERS = $(addprefix $(INCLUDE_DIR), $(INCLUDE_LIST))
INCLUDES = -I $(INCLUDE_DIR) -I $(LIBFT_INCLUDE_DIR)

SRC_DIR = src/
SRC_LIST = main.c \
		init.c \
		error.c

SRC = $(addprefix $(SRC_DIR), $(SRC_LIST))

OBJ_DIR = objects/
OBJ_LIST = $(patsubst %.c, %.o, $(SRC_LIST))
OBJS = $(addprefix $(OBJ_DIR), $(OBJ_LIST))

.PHONY: all clean fclean re

all: $(NAME) 

$(NAME): $(HEADERS) $(OBJ_DIR) $(OBJS) 
	@$(MAKE) -C $(LIBFT_DIR)
	@$(CC) $(FLAGS) $(OBJS) $(INCLUDES) $(LIBS) $(LIB_FLAGS) -o $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(HEADERS)
	@$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all
