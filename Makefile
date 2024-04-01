# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/01 14:39:40 by plgol.perso       #+#    #+#              #
#    Updated: 2023/12/01 14:39:43 by plgol.perso      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC := clang
RM := rm -f
CFLAGS := -Wall -Werror -Wextra -g3

# Executable name
NAME := smlx

# Directories
INC_DIR := ./include
SRC_DIRS := ./source
LIB_DIR := ./lib
MLX_DIR := ./mlx

# Source files
SRCS := $(wildcard $(addsuffix /*.c,$(SRC_DIRS)))
OBJS := $(SRCS:.c=.o)

# Libraries
CLIB := $(LIB_DIR)/libclib.a
LIBMLX := $(MLX_DIR)/libmlx.a

# Targets
.PHONY: all clean fclean re plib mlx

all: $(NAME)

$(NAME): $(OBJS) clib mlx
	$(CC) $(CFLAGS) -o $@ $(OBJS) -L$(LIB_DIR) -lclib -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

%.o: %.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clib:
	$(MAKE) -C $(LIB_DIR)

mlx:
	$(MAKE) -C $(MLX_DIR)

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIB_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIB_DIR) fclean
	$(MAKE) -C $(MLX_DIR) clean

re: fclean all
