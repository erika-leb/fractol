# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ele-borg <ele-borg@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/04 18:23:01 by ele-borg          #+#    #+#              #
#    Updated: 2024/10/07 16:23:46 by ele-borg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#variables

# Commun source files
SRC_FILES = utils.c \
			math_functions.c \
			colors.c \
			fractol.c \
			parsing.c \
			math_bonus.c \
			events.c \

OBJ_FILES = $(SRC_FILES:.c=.o)

NAME = fractol

FLAGS_C = -Wall -Wextra -Werror -I. -I minilibx-linus/mlx.h

FLAGS_L = ./minilibx-linux/libmlx_Linux.a -lm -lXext -lX11
 
CC = cc

#rules

all: ${NAME} 

${NAME}: ${OBJ_FILES}
	${CC} ${OBJ_FILES} ${FLAGS_L} -o ${NAME}

.c.o:
	$(CC) -c $(FLAGS_C) $< -o $@

clean: 
	rm -f ${OBJ_FILES}

fclean: clean
	rm -f ${NAME}

re: fclean all

reclean : all clean

.PHONY: all clean fclean re bonus