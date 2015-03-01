/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvolberg <dvolberg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 10:54:28 by dvolberg          #+#    #+#             */
/*   Updated: 2015/03/01 16:01:59 by dvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void printGameOver(int x)
{
	attron(COLOR_PAIR(1));
	mvprintw(15, (x / 2) - 28,
	 "   ______                         ____                    ");
	mvprintw(16, (x / 2) - 28,
	 "  / ____/____ _ ____ ___   ___   / __ \\ _   __ ___   _____");
	mvprintw(17, (x / 2) - 28,
	 " / / __ / __ `// __ `__ \\ / _ \\ / / / /| | / // _ \\ / ___/");
	mvprintw(18, (x / 2) - 28,
	 "/ /_/ // /_/ // / / / / //  __// /_/ / | |/ //  __// /    ");
	mvprintw(19, (x / 2) - 28,
	 "\\____/ \\__,_//_/ /_/ /_/ \\___/ \\____/  |___/ \\___//_/     ");
	mvprintw(25, (x / 2) - 15, "Press q or Q or enter to quit.");
	attroff(COLOR_PAIR(1));
}

void printTitle(int x)
{
	// attron(COLOR_PAIR(20));
	// mvprintw(4, (x / 2) , "      _____                  ");
	// attron(COLOR_PAIR(21));
	// mvprintw(5, (x / 2) , "     /__  /     __    ______ ");
	// attron(COLOR_PAIR(22));
	// mvprintw(6, (x / 2) , "    ___/ /_____/ / __/ __  / ");
	// attron(COLOR_PAIR(23));
	// mvprintw(7, (x / 2) , "   / ___/ __  / /_/ /_   _/  ");
	// attron(COLOR_PAIR(24));
	// mvprintw(8, (x / 2) , "  / /__/ /_/ /___  / __  /   ");
	// attron(COLOR_PAIR(25));
	// mvprintw(9, (x / 2) , " /____/_____/   /_/_____/    ");

// attron(COLOR_PAIR(20));
// mvprintw(4, (x / 5), "____/\\\\\\\\\\_________/\\\\\\\\_______________/\\\\________/\\\\\\\\\\____        ");
// attron(COLOR_PAIR(21));
// mvprintw(5, (x / 5), " __/\\\\///////\\\\_____/\\\\/////\\\\___________/\\\\\\______/\\\\///////\\\\__       ");
// attron(COLOR_PAIR(22));
// mvprintw(6, (x / 5), "  _\\///______\\//\\\\___/\\\\____\\//\\\\________/\\\\/\\\\_____\\/\\\\_____\\/\\\\__      ");
// attron(COLOR_PAIR(23));
// mvprintw(7, (x / 5), "   ___________/\\\\/___\\/\\\\_____\\/\\\\______/\\\\/\\/\\\\_____\\///\\\\\\\\\\/___     ");
// attron(COLOR_PAIR(24));
// mvprintw(8, (x / 5), "    ________/\\\\//_____\\/\\\\_____\\/\\\\____/\\\\/__\\/\\\\______/\\\\///////\\\\__    ");
// attron(COLOR_PAIR(25));
// mvprintw(9, (x / 5), "     _____/\\\\//________\\/\\\\_____\\/\\\\__/\\\\\\\\\\\\\\\\__/\\\\______\\//\\\\_   ");
// attron(COLOR_PAIR(22));
// mvprintw(10, (x / 5), "      ___/\\\\/___________\\//\\\\____/\\\\__\\///////////\\\\//__\\//\\\\______/\\\\__  ");
// attron(COLOR_PAIR(21));
// mvprintw(11, (x / 5), "       __/\\\\\\\\\\\\\\\\__\\///\\\\\\\\/_____________\\/\\\\_____\\///\\\\\\\\\\/___ ");
// attron(COLOR_PAIR(20));
// mvprintw(12, (x / 5), "        _\\///////////////_____\\///////_______________\\///________\\/////////_____");

attron(COLOR_PAIR(20));
mvprintw(4, (x / 5), "  .--~*teu.        .n~~%%x.             xeee       u+=~~~+u.    ");
attron(COLOR_PAIR(21));
mvprintw(5, (x / 5), " dF     988Nx    x88X   888.          d888R     z8F      `8N.  ");
attron(COLOR_PAIR(22));
mvprintw(6, (x / 5), "d888b   `8888>  X888X   8888L        d8888R    d88L       98E  ");
attron(COLOR_PAIR(23));
mvprintw(7, (x / 5), "?8888>  98888F X8888X   88888       @ 8888R    98888bu.. .@*   ");
attron(COLOR_PAIR(24));
mvprintw(8, (COLS / 2) - 31, " \"**\"  x88888~ 88888X   88888X    .P  8888R    \"88888888NNu.   ");
attron(COLOR_PAIR(25));
mvprintw(9, (x / 5), "      d8888*`  88888X   88888X   :F   8888R     \"*8888888888i  ");
attron(COLOR_PAIR(26));
mvprintw(10, (x / 5), "    z8**\"`   : 88888X   88888f  x\"    8888R     .zf\"\"*8888888L ");
attron(COLOR_PAIR(27));
mvprintw(11, (x / 5), "  :?.....  ..F 48888X   88888  d8eeeee88888eer d8F      ^%%888E ");
attron(COLOR_PAIR(28));
mvprintw(12, (x / 5), " <\"\"888888888~  ?888X   8888\"         8888R    88>        `88~ ");
attron(COLOR_PAIR(29));
mvprintw(13, (x / 5), " 8:  \"888888*    \"88X   88*`          8888R    '%%N.       d*\"  ");
attron(COLOR_PAIR(30));
mvprintw(14, (x / 5), " \"\"    \"**\"`       ^\"===\"`         \"*%%%%%%%%%%%%**~    ^\"=====\"`    ");

}

void gameover(int x)
{
	int ch = 0;

	wclear(stdscr);
	wrefresh(stdscr);
	while (1) {
		ch = getch();
		printGameOver(x);
		if (ch == 'q' || ch == 'Q' || ch == 27 || ch == 10)
			break;
		refresh();
	}
}
