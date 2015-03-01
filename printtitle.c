#include "game.h"

void            printtitle(int x)
{
	(void)x;
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
