/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvolberg <dvolberg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 10:54:28 by dvolberg          #+#    #+#             */
/*   Updated: 2015/03/01 21:13:01 by dvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void part2(void)
{
	attron(COLOR_PAIR(25));
	mvprintw(9, (COLS / 2) - 31,
		"      d8888*`  88888X   88888X   :F   8888R     \"*8888888888i  ");
	attron(COLOR_PAIR(26));
	mvprintw(10, (COLS / 2) - 31,
		"    z8**\"`   : 88888X   88888f  x\"    8888R     .zf\"\"*8888888L ");
	attron(COLOR_PAIR(27));
	mvprintw(11, (COLS / 2) - 31,
		"  :?.....  ..F 48888X   88888  d8eeeee88888eer d8F      ^%%888E ");
	attron(COLOR_PAIR(28));
	mvprintw(12, (COLS / 2) - 31,
		" <\"\"888888888~  ?888X   8888\"         8888R    88>        `88~ ");
	attron(COLOR_PAIR(29));
	mvprintw(13, (COLS / 2) - 31,
		" 8:  \"888888*    \"88X   88*`          8888R    '%%N.       d*\"  ");
	attron(COLOR_PAIR(30));
	mvprintw(14, (COLS / 2) - 31,
		" \"\"    \"**\"`       ^\"===\"`         \"*%%%%%%%%%%%%**~    ^\"==");
}

void printtitle(int x)
{
	attron(COLOR_PAIR(20));
	mvprintw(4, (COLS / 2) - 31,
		"  .--~*teu.        .n~~%%x.             xeee       u+=~~~+u.    ");
	attron(COLOR_PAIR(21));
	mvprintw(5, (COLS / 2) - 31,
		" dF     988Nx    x88X   888.          d888R     z8F      `8N.  ");
	attron(COLOR_PAIR(22));
	mvprintw(6, (COLS / 2) - 31,
		"d888b   `8888>  X888X   8888L        d8888R    d88L       98E  ");
	attron(COLOR_PAIR(23));
	mvprintw(7, (COLS / 2) - 31,
		"?8888>  98888F X8888X   88888       @ 8888R    98888bu.. .@*   ");
	attron(COLOR_PAIR(24));
	mvprintw(8, (COLS / 2) - 31,
		" \"**\"  x88888~ 88888X   88888X    .P  8888R    \"88888888NNu.   ");
	part2();
}

int youwin(int x, t_env *env)
{
	int ch;


	ch = 0;
	wclear(stdscr);
	wrefresh(stdscr);
	env->win = 1;
	while (1)
	{
		ch = getch();
		printwin(x);
		if (ch == 'q' || ch == 'Q' || ch == 27)
		{
			// printf("==========");
			endwin();
			return (0);
		}
		if (ch == 10)
		{
			wclear(stdscr);
			// play(env);
			return (1);
		}
		refresh();
	}
}

void gameover(int x)
{
	int ch;

	ch = 0;
	wclear(stdscr);
	wrefresh(stdscr);
	while (1)
	{
		ch = getch();
		printgameover(x);
		if (ch == 'q' || ch == 'Q' || ch == 27 || ch == 10)
		{
			endwin();
			break;
		}
		refresh();
	}
}
