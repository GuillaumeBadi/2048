# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvolberg <dvolberg@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/18 05:41:35 by bsautron          #+#    #+#              #
#    Updated: 2015/02/28 04:50:47 by dvolberg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = game_2048

SRC = main.c

DIR_H = ./includes

HEADERS = $(DIR_H)/rush.h \
		 $(DIR_H)/libft.h \
		 $(DIR_H)/get_next_line.h

OBJ = $(SRC:%.c=%.o)

CFLAGS = -Wextra -Wall -Werror -lncurses

LIB = -L./libft -lft

.PHONY: all libs clean fclean re

all: libs $(NAME)

$(NAME): $(OBJ)
	@echo "\033[31m"
	@$(CC) -o $@ $^ $(LIB) -lncurses -g
	@echo "\033[37m"

libs:
	@make -C libft/

%.o: %.c $(HEADERS)
	# @echo "\033[33m   $<"
	@$(CC) -o $@ -I includes/ -c $< -g

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
