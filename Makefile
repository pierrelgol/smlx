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
CC := gcc
RM := rm -f
CFLAGS := -Wall -Werror -Wextra -flto -finline-functions

# Executable name
lib := libsmlx.a

# Directories
INC_DIR := ./include
SRC_DIRS := ./source/camera ./source/helpers ./source/mat4 ./source/quat ./source/vec2 ./source/vec3 ./source/vec4 ./source/view
MLX_DIR := ./mlx

# Source files
SRCS := $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))
OBJS := $(SRCS:.c=.o)

# Libraries
LIBMLX := $(MLX_DIR)/libmlx.a

# Targets
.PHONY: all clean fclean re mlx

all: $(lib)

$(lib): $(OBJS) mlx
	ar -rcs $@ $(OBJS) $(LIBMLX)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

mlx:
	$(MAKE) -C $(MLX_DIR)

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	$(RM) $(lib)
	$(MAKE) -C $(MLX_DIR) clean

re: fclean all
