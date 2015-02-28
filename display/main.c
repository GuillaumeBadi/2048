#include "rush.h"

void	ft_draw_col(int y_max, int x_max)
{
	int		y;
	int		x;

	y = 0;
	while (y <= y_max)
	{
		x = 0;
		while (x <= x_max)
		{
			mvprintw(y, x, "|");
			x += x_max / 4;
		}
		y++;
	}
}

void	ft_draw_row(int y_max, int x_max)
{
	int		y;
	int		x;

	y = 0;
	while (y <= y_max)
	{
		x = 0;
		while (x <= x_max)
		{
			mvprintw(y, x, "-");
			x++;
		}
		y += y_max / 4;
	}
}

void	ft_draw_corner(int y_max, int x_max)
{
	int		y;
	int		x;

	y = 0;
	while (y <= y_max)
	{
		x = 0;
		while (x <= x_max)
		{
			mvprintw(y, x, "+");
			x += x_max / 4;
		}
		y += y_max / 4;
	}
}

void	ft_draw_grid(void)
{
	int		y_max;
	int		x_max;

	getmaxyx(stdscr, y_max, x_max);
	x_max /= 4;
	y_max /= 4;
	x_max *= 4;
	y_max *= 4;
	y_max -= 4;
	x_max -= 4;
	ft_draw_col(y_max, x_max);
	ft_draw_row(y_max, x_max);
	ft_draw_corner(y_max, x_max);
}

int		main(void)
{
	int		y_max;
	int		x_max;
	int		y_new;
	int		x_new;

	initscr();
	noecho();
	cbreak();
	curs_set(FALSE);
	getmaxyx(stdscr, y_max, x_max);
	ft_draw_grid();
	refresh();
	while (1)
	{
		getmaxyx(stdscr, y_new, x_new);
		if ((y_new != y_max || x_new != x_max) && y_new > 16 && x_new > 16)
		{
			y_max = y_new;
			x_max = x_new;
			clear();
			ft_draw_grid();

		}
		else if (y_new <= 16 || x_new <= 16)
		{
			clear();
			mvprintw(0, 0, "la fenettre est trop petite");
		}

		refresh();
	}
	endwin();

	return (0);
}
