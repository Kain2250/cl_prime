# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwing <cwing@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/06 17:56:24 by kain2250          #+#    #+#              #
#    Updated: 2020/12/06 23:59:01 by cwing            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cl_prime

CC = clang
CCFLAGS = -Wall -Wextra
FLAGS = -O2

LIBFT = $(LIBFT_DIRECTORY)libft.a
LIBFT_DIRECTORY = libft/
LIBFT_FLAGS = -L $(LIBFT_DIRECTORY) -lft

INCLUDES_DIRECTORY = include/
INCLUDES_DIRECTORY_LIBFT = $(LIBFT_DIRECTORY)includes/
INCLUDES = -I $(INCLUDES_DIRECTORY) -I $(INCLUDES_DIRECTORY_LIBFT)
HEADERS = $(addprefix $(INCLUDES_DIRECTORY), $(HEADERS_LIST))

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	CL_FLAGS += -lOpenCL
endif
ifeq ($(UNAME_S),Darwin)
	CL_FLAGS += -framework OpenCL
endif

ALL_FLAGS = $(CL_FLAGS) $(LIBFT_FLAGS) $(CCFLAGS)

HEADERS_LIST = main.h

SRC_DIRECTORY = ./src/
SRC_LIST = error.c \
		init.c \
		get_file.c \
		main.c
SRC = $(addprefix $(SRC_DIRECTORY), $(SRC_LIST))

OBJ_DIR = objects/
OBJ_LIST = $(patsubst %.c, %.o, $(SRC_LIST))
OBJECTS = $(addprefix $(OBJ_DIR), $(OBJ_LIST))

GREEN = \033[0;32;1m
RED = \033[0;31;1m
RESET = \033[0m

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJECTS) 
	@$(CC) $(OBJECTS) $(INCLUDES) $(ALL_FLAGS) -o $(NAME)
	@printf "$(GREEN)[$(NAME)] Make executable file $(NAME) successfuly! [OK]\n$(RESET)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@printf "$(GREEN)[$(NAME)] Make object directory\n$(RESET)"

$(OBJ_DIR)%.o: $(SRC_DIRECTORY)%.c $(HEADERS)
	@printf "$(RED)[$(NAME)] Compiling [...]\r$(RESET)"
	@$(CC) -c $(CCFLAGS) $(FLAGS) $(INCLUDES)  $< -o $@
	@printf "$(GREEN)[$(NAME)] Compiling [$@]\n$(RESET)"

$(LIBFT):
	@printf "$(GREEN)[$(NAME)] Make $(LIBFT) [OK]\n$(RESET)"
	@$(MAKE) -sC $(LIBFT_DIRECTORY)

clean:
	@make -sC $(LIBFT_DIRECTORY) clean
	@rm -rf $(OBJ_DIR)
	@printf "$(RED)[$(NAME)] Delete object files successfuly! [OK]\n$(RESET)"


fclean: clean
	@rm -f $(NAME)
	@printf "$(RED)[$(NAME)] Delete $(NAME) successfuly! [OK]\n$(RESET)"

re:
	@$(MAKE) fclean
	@$(MAKE) all