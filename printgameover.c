#include "game.h"

void            gameover(int x)
{
	int                             ch;

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
			break ;
		}
		refresh();
	}
}
