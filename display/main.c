#include "rush.h"

void	ft_draw_col(WINDOW *field, int y_max, int x_max)
{
	int		y;
	int		x;

	y = 0;
	while (y <= y_max)
	{
		x = 0;
		while (x <= x_max)
		{
			mvwprintw(field, y, x, "|");
			x += x_max / 4;
		}
		y++;
	}
}

void	ft_draw_row(WINDOW *field, int y_max, int x_max)
{
	int		y;
	int		x;

	y = 0;
	while (y <= y_max)
	{
		x = 0;
		while (x <= x_max)
		{
			mvwprintw(field, y, x, "-");
			x++;
		}
		y += y_max / 4;
	}
}

void	ft_draw_corner(WINDOW *field, int y_max, int x_max)
{
	int		y;
	int		x;

	y = 0;
	while (y <= y_max)
	{
		x = 0;
		while (x <= x_max)
		{
			mvwprintw(field, y, x, "+");
			x += x_max / 4;
		}
		y += y_max / 4;
	}
}

void	ft_draw_grid(WINDOW *field, int y_max, int x_max)
{
	ft_draw_col(field, y_max, x_max);
	ft_draw_row(field, y_max, x_max);
	ft_draw_corner(field, y_max, x_max);
}

int		main(void)
{
	WINDOW *field;
	int		y_max;
	int		x_max;


	initscr();
	noecho();
	curs_set(FALSE);
	getmaxyx(stdscr, y_max, x_max);
	x_max /= 4;
	y_max /= 4;
	x_max *= 4;
	y_max *= 4;
	y_max++;
	x_max++;
	field = newwin(y_max, x_max, 0, 0);
	ft_draw_grid(field, y_max, x_max);
	wrefresh(field);

	sleep(5);
	delwin(field);
	endwin();

	return (0);
}
