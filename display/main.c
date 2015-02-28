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

void	ft_putnbr_to_grid(int y_max, int x_max, int **tab)
{
	int		y_increm;
	int		x_increm;
	int		x;
	int		y;
	int		i;
	int		j;

	y_increm = y_max / 4;
	x_increm = x_max / 4;
	i = 0;
	y = y_increm / 2;
	while (i < 4)
	{
		j = 0;
		x = x_increm / 2;
		while (j < 4)
		{
			
			mvprintw(y, x - ft_intlen(tab[i][j]) / 2, ft_itoa(tab[i][j]));
			x += x_increm;
			j++;
		}
		i++;
		y += y_increm;
	}
	(void)tab;
}

void	ft_draw_grid(int **tab)
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
	ft_putnbr_to_grid(y_max, x_max, tab);
}

int		main(void)
{
	int		y_max;
	int		x_max;
	int		y_new;
	int		x_new;
	int		**tab1;

	tab1 = (int **)malloc(sizeof(int *) * 4);
	for (int i = 0; i < 4; i++)
	{
		tab1[i] = (int *)malloc(sizeof(int) * 4);
		for (int j = 0; j < 4; j++)
		{
			tab1[i][j] = 12345;
		}
	}
	initscr();
	noecho();
	cbreak();
	curs_set(FALSE);
	getmaxyx(stdscr, y_max, x_max);
	ft_draw_grid(tab1);
	refresh();
	while (1)
	{
		getmaxyx(stdscr, y_new, x_new);
		if ((y_new != y_max || x_new != x_max) && y_new > 16 && x_new > 16)
		{
			y_max = y_new;
			x_max = x_new;
			clear();
			ft_draw_grid(tab1);

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
