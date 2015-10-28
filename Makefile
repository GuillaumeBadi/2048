# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvolberg <dvolberg@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/01 22:16:59 by dvolberg          #+#    #+#              #
#    Updated: 2015/03/03 06:27:35 by dvolberg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror -lncurses

SOURCE = main.c ft_print_tout.c display.c draw.c ft_get_pair.c game.c \
		input.c merge_bottom.c merge_left.c merge_right.c merge_top.c \
		move_bottom.c move_left.c move_right.c ascii/color.c ascii/printtitle.c\
		move_top.c tab.c play.c ascii/ascii_0.c ascii/ascii_1.c ascii/ascii_2.c\
		ascii/ascii_3.c ascii/ascii_4.c ascii/ascii_5.c ascii/ascii_6.c\
		ascii/ascii_8.c ascii/ascii_9.c ascii/print_1024.c ascii/print_128.c\
		ascii/print_16.c ascii/print_2.c ascii/print_2048.c ascii/print_256.c\
		ascii/print_32.c ascii/print_4.c ascii/print_4096.c ascii/print_512.c\
		ascii/print_64.c ascii/print_8.c ascii/gameover.c ascii/youwin.c


SRCO = $(SOURCE:%.c=%.o)

NAME = game_2048

all: $(NAME)

$(NAME): $(SRCO)

	@echo "\033[0m"
	@echo " 222222222222222         000000000            444444444       888888888     "
	@echo "2:::::::::::::::22     00:::::::::00         4::::::::4     88:::::::::88   "
	@echo "2::::::222222:::::2  00:::::::::::::00      4:::::::::4   88:::::::::::::88 "
	@echo "2222222     2:::::2 0:::::::000:::::::0    4::::44::::4  8::::::88888::::::8"
	@echo "            2:::::2 0::::::0   0::::::0   4::::4 4::::4  8:::::8     8:::::8"
	@echo "            2:::::2 0:::::0     0:::::0  4::::4  4::::4  8:::::8     8:::::8"
	@echo "         2222::::2  0:::::0     0:::::0 4::::4   4::::4   8:::::88888:::::8 "
	@echo "    22222::::::22   0:::::0 000 0:::::04::::444444::::444  8:::::::::::::8  "
	@echo "  22::::::::222     0:::::0 000 0:::::04::::::::::::::::4 8:::::88888:::::8 "
	@echo " 2:::::22222        0:::::0     0:::::04444444444:::::4448:::::8     8:::::8"
	@echo "2:::::2             0:::::0     0:::::0          4::::4  8:::::8     8:::::8"
	@echo "2:::::2             0::::::0   0::::::0          4::::4  8:::::8     8:::::8"
	@echo "2:::::2       2222220:::::::000:::::::0          4::::4  8::::::88888::::::8"
	@echo "2::::::2222222:::::2 00:::::::::::::00         44::::::44 88:::::::::::::88 "
	@echo "2::::::::::::::::::2   00:::::::::00           4::::::::4   88:::::::::88   "
	@echo "22222222222222222222     000000000             4444444444     888888888     "



	@make -C libft
	@$(CC) $(CFLAGS) $(SOURCE) -L./libft/ -lft -o $(NAME) -I./includes/

%.o: %.c ./includes/game.h
	@$(CC) -o $@  -I includes/ -c $<

clean:
	@make -C libft clean
	@/bin/rm -rf $(SRCO)

fclean: clean
	@make -C libft fclean
	@/bin/rm -rf $(NAME)

re: fclean all
