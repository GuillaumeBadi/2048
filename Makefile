# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbadi <gbadi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/01 22:16:59 by gbadi             #+#    #+#              #
#    Updated: 2015/03/01 23:03:43 by gbadi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SOURCE = main.c\
		ascii.c\
		ascii2.c\
		display.c\
		draw.c\
		ft_get_pair.c\
		game.c\
		horizontal.c\
		input.c\
		vertical.c\
		play.c\
		play2.c\
		play3.c\
		print.c\
		print2.c\
		print3.c\
		tab.c

SRCO = $(SOURCE:%.c=%.o)

NAME = game_2048

all: $(NAME)

$(NAME): $(SRCO)
	@make -C libft
	$(CC) $(CFLAGS) $(SOURCE) -L./libft/ -lft -o $(NAME) -I./includes/ -lncurses

%.o: %.c ./includes/game.h
	$(CC) -o $@  -I includes/ -c $< -lncurses $(FLAGS)

clean:
	make -C libft clean

fclean: clean
	make -C libft fclean
	/bin/rm -rf $(NAME)

re: fclean all
