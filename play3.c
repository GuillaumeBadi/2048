/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <gbadi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 21:51:49 by dvolberg          #+#    #+#             */
/*   Updated: 2015/03/01 23:06:09 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void win(void)
{
	attron(COLOR_PAIR(20));
	mvprintw (10, (COLS / 2) - 23,
		"                                              ");
	attron(COLOR_PAIR(20));
	mvprintw (11, (COLS / 2) - 23,
		"   .xnnx.  .xx.                               ");
	attron(COLOR_PAIR(21));
	mvprintw (12, (COLS / 2) - 23,
		" .f``\"888X< `888.         u.      x.    .     ");
	attron(COLOR_PAIR(21));
	mvprintw (13, (COLS / 2) - 23,
		" 8L   8888X  8888   ...ue888b   .@88k  z88u   ");
	attron(COLOR_PAIR(22));
	mvprintw (14, (COLS / 2) - 23,
		"X88h. `8888  X888k  888R Y888r ~\"8888 ^8888   ");
	attron(COLOR_PAIR(22));
	mvprintw (15, (COLS / 2) - 23,
		"'8888 '8888  X8888  888R I888>   8888  888R   ");
	attron(COLOR_PAIR(23));
	mvprintw (16, (COLS / 2) - 23,
		" `*88>'8888  X8888  888R I888>   8888  888R   ");
	attron(COLOR_PAIR(23));
	mvprintw (17, (COLS / 2) - 23,
		"   `! X888~  X8888  888R I888>   8888  888R   ");
}

void win1(void)
{
	attron(COLOR_PAIR(24));
	mvprintw (18, (COLS / 2) - 23,
		"  -`  X*\"    X8888 u8888cJ888    8888 ,888B . ");
	attron(COLOR_PAIR(24));
	mvprintw (19, (COLS / 2) - 23,
		"   xH88hx  . X8888  \"*888*P\"    \"8888Y 8888\"  ");
	attron(COLOR_PAIR(25));
	mvprintw (20, (COLS / 2) - 23,
		" .*\"*88888~  X888X    'Y\"        `Y\"   'YP    ");
	attron(COLOR_PAIR(25));
	mvprintw (21, (COLS / 2) - 23,
		" `    \"8%%    X888>                            ");
	attron(COLOR_PAIR(26));
	mvprintw (22, (COLS / 2) - 23,
		"    .x..     888f                             ");
	attron(COLOR_PAIR(26));
	mvprintw (23, (COLS / 2) - 23,
		"   88888    :88f                              ");
	attron(COLOR_PAIR(27));
	mvprintw (24, (COLS / 2) - 23,
		"   \"88*\"  .x8*~                               ");
	attron(COLOR_PAIR(20));
	mvprintw (25, (COLS / 2) - 12,
		"Press q to quit or enter to continue.");
}

void win2(void)
{
	attron(COLOR_PAIR(28));
	mvprintw (26, (COLS / 2) - 26,
		"        ...    .     ...         .                  ");
	attron(COLOR_PAIR(28));
	mvprintw (27, (COLS / 2) - 26,
		"     .~`\"888x.!**h.-``888h.     @88>                ");
	attron(COLOR_PAIR(27));
	mvprintw (28, (COLS / 2) - 26,
		"    dX   `8888   :X   48888>    %%8P      u.    u.   ");
	attron(COLOR_PAIR(27));
	mvprintw (29, (COLS / 2) - 26,
		"   '888x  8888  X88.  '8888>     .     x@88k u@88c. ");
	attron(COLOR_PAIR(26));
	mvprintw (30, (COLS / 2) - 26,
		"   '88888 8888X:8888:   )?\"\"`  .@88u  ^\"8888\"\"8888\" ");
	attron(COLOR_PAIR(26));
	mvprintw (31, (COLS / 2) - 26,
		"    `8888>8888 '88888>.88h.   ''888E`   8888  888R  ");
	attron(COLOR_PAIR(25));
	mvprintw (32, (COLS / 2) - 26,
		"      `8\" 888f  `8888>X88888.   888E    8888  888R  ");
	attron(COLOR_PAIR(25));
	mvprintw (33, (COLS / 2) - 26,
		"     -~` '8%%\"     88\" `88888X   888E    8888  888R  ");
}

void printwin(int x)
{
	(void)x;
	win();
	win1();
	win2();
	attron(COLOR_PAIR(24));
	mvprintw (34, (COLS / 2) - 26,
		"     .H888n.      XHn.  `*88!   888E    8888  888R  ");
	attron(COLOR_PAIR(24));
	mvprintw (35, (COLS / 2) - 26,
		"    :88888888x..x88888X.  `!    888&   \"*88*\" 8888\" ");
	attron(COLOR_PAIR(23));
	mvprintw (36, (COLS / 2) - 26,
		"    f  ^%%888888%% `*88888nx\"     R888\"    \"\"   'Y\"   ");
	attron(COLOR_PAIR(23));
	mvprintw (37, (COLS / 2) - 26,
		"         `\"**\"`    `\"**\"\"        \"\"                 ");
	attron(COLOR_PAIR(22));
	mvprintw (38, (COLS / 2) - 26,
		"                                                    ");
	attron(COLOR_PAIR(22));
	mvprintw (39, (COLS / 2) - 26,
		"                                                    ");
	attron(COLOR_PAIR(21));
	mvprintw (40, (COLS / 2) - 26,
		"                                                    ");
}
