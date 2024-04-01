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
CFLAGS := -Wall -Werror -Wextra

# Executable name
lib := libsmlx.a

# Directories
INC_DIR := ./include

# Sources
SRC_DIRS := ./source/camera          \
            ./source/helpers         \
            ./source/mat4            \
            ./source/quat            \
            ./source/vec2            \
            ./source/vec3            \
            ./source/vec4            \
            ./source/view            \
            ./source/mlx             \
            ./source/smlx            \


# Source files
SRCS := $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))
OBJS := $(SRCS:.c=.o)

# Targets
.PHONY: all clean fclean re

all: $(lib)

$(lib): $(OBJS)
	ar -rcs $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(lib)

re: fclean all
