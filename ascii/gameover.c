/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameover.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvolberg <dvolberg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 18:01:29 by dvolberg          #+#    #+#             */
/*   Updated: 2015/03/03 05:22:37 by dvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	part_1(void)
{
	attron(COLOR_PAIR(20));
	mvprintw (10, (COLS / 2) - 32,
		"      ....        .                                              ");
	attron(COLOR_PAIR(20));
	mvprintw (11, (COLS / 2) - 32,
		"   .x88\" `^x~  xH(`                                              ");
	attron(COLOR_PAIR(20));
	mvprintw (12, (COLS / 2) - 32,
		"  X888   x8 ` 8888h                  ..    .     :               ");
	attron(COLOR_PAIR(21));
	mvprintw (13, (COLS / 2) - 32,
		" 88888  888.  %%8888                .888: x888  x888.       .u    ");
	attron(COLOR_PAIR(21));
	mvprintw (14, (COLS / 2) - 32,
		"<8888X X8888   X8?       us888u.  ~`8888~'888X`?888f`   ud8888.  ");
	attron(COLOR_PAIR(21));
	mvprintw (15, (COLS / 2) - 32,
		"X8888> 488888>\"8888x  .@88 \"8888\"   X888  888X '888>  :888'8888. ");
	attron(COLOR_PAIR(22));
	mvprintw (16, (COLS / 2) - 32,
		"X8888>  888888 '8888L 9888  9888    X888  888X '888>  d888 '88%%\" ");
	attron(COLOR_PAIR(22));
	mvprintw (17, (COLS / 2) - 32,
		"?8888X   ?8888>'8888X 9888  9888    X888  888X '888>  8888.+\"    ");
}

static void	part_2(void)
{
	attron(COLOR_PAIR(22));
	mvprintw (18, (COLS / 2) - 32,
	" 8888X h  8888 '8888~ 9888  9888    X888  888X '888>  8888L      ");
	attron(COLOR_PAIR(23));
	mvprintw (19, (COLS / 2) - 32,
	"  ?888  -:8*\"  <888\"  9888  9888   \"*88%%\"\"*88\" '888!` '8888c. .+");
	attron(COLOR_PAIR(23));
	mvprintw (20, (COLS / 2) - 32,
	"   `*88.      :88%%    \"888*\"\"888\"    `~    \"    `\"`    \"88888%%");
	attron(COLOR_PAIR(23));
	mvprintw (21, (COLS / 2) - 32,
	"      ^\"~====\"\"`       ^Y\"   ^Y'                         \"YP'    ");
	attron(COLOR_PAIR(20));
	mvprintw(22, (COLS / 2) - 15, "Press q or Q to quit.");
	attron(COLOR_PAIR(24));
	mvprintw (23, (COLS / 2) - 32,
		"        ....            _                                 ");
	attron(COLOR_PAIR(24));
	mvprintw (24, (COLS / 2) - 32,
		"    .x~X88888Hx.       u                                  ");
	attron(COLOR_PAIR(24));
	mvprintw (25, (COLS / 2) - 32,
		"   H8X 888888888h.    88Nu.   u.                .u    .   ");
}

static void	part_3(void)
{
	mvprintw (26, (COLS / 2) - 32,
		"  8888:`*888888888:  '88888.o888c      .u     .d88B :@8c  ");
	attron(COLOR_PAIR(25));
	mvprintw (27, (COLS / 2) - 32,
		"  88888:        `%%8   ^8888  8888   ud8888.  =\"8888f8888r ");
	attron(COLOR_PAIR(25));
	mvprintw (28, (COLS / 2) - 32,
		". `88888          ?>   8888  8888 :888'8888.   4888>'88\"  ");
	attron(COLOR_PAIR(26));
	mvprintw (29, (COLS / 2) - 32,
		"`. ?888%%           X   8888  8888 d888 '88%%\"   4888> '    ");
	attron(COLOR_PAIR(26));
	mvprintw (30, (COLS / 2) - 32,
		"  ~*??.            >   8888  8888 8888.+\"      4888>      ");
}

static void	printgameover(void)
{
	part_1();
	part_2();
	part_3();
	attron(COLOR_PAIR(25));
	attron(COLOR_PAIR(26));
	mvprintw (31, (COLS / 2) - 32,
		" .x88888h.        <   .8888b.888P 8888L       .d888L .+   ");
	attron(COLOR_PAIR(27));
	mvprintw (32, (COLS / 2) - 32,
		":\"\"\"8888888x..  .x     ^Y8888*\"\"  '8888c. .+  ^\"8888*\"    ");
	attron(COLOR_PAIR(27));
	mvprintw (33, (COLS / 2) - 32,
		"`    `*888888888\"        `Y\"       \"88888%%       \"Y\"      ");
	attron(COLOR_PAIR(27));
	mvprintw (34, (COLS / 2) - 32,
		"        \"\"***\"\"                      \"YP'                 ");
}

void		gameover(void)
{
	int		ch;

	ch = 0;
	wclear(stdscr);
	wrefresh(stdscr);
	while (1)
	{
		ch = getch();
		printgameover();
		if (ch == 'q' || ch == 'Q' || ch == 27 || ch == 10)
		{
			endwin();
			break ;
		}
		refresh();
	}
}
