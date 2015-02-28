/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvolberg <dvolberg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 22:20:56 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/28 08:17:55 by dvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	ft_draw_bg(int **tab, int y_max, int x_max)
{
	int		y;
	int		j;
	int		i;

	y = 0;
	while (y < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			attron(COLOR_PAIR(tab[y][j]));
			i = y * (y_max / 4);
			while (i < (y + 1) * y_max / 4)
			{
				mvhline(i, j * (x_max / 4) + 1, ' ', x_max / 4);
				i++;
			}
			attroff(COLOR_PAIR(tab[y][j]));
			j++;
		}
		y++;
	}
}

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
			x += x_max / SIZE;
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
		y += y_max / SIZE;
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
			x += x_max / SIZE;
		}
		y += y_max / SIZE;
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

	y_increm = y_max / SIZE;
	x_increm = x_max / SIZE;
	i = 0;
	y = y_increm / 2;
	while (i < SIZE)
	{
		j = 0;
		x = x_increm / 2;
		while (j < SIZE)
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
	x_max /= SIZE;
	y_max /= SIZE;
	x_max *= SIZE;
	y_max *= SIZE;
	y_max -= SIZE;
	x_max -= SIZE;


	ft_draw_bg(tab, y_max, x_max);
	ft_draw_col(y_max, x_max);
	ft_draw_row(y_max, x_max);
	ft_draw_corner(y_max, x_max);
	ft_putnbr_to_grid(y_max, x_max, tab);
}

void	ft_init(void)
{

}

int		main(void)
{
	int		y_max;
	int		x_max;
	int		y_new;
	int		x_new;
	int		**tab1;
	int		ch;

	ch = 0;
	tab1 = (int **)malloc(sizeof(int *) * SIZE);
	int i = 0;
	while (i < SIZE)
	{
		tab1[i] = (int *)malloc(sizeof(int) * SIZE);
		int j = 0;
		while (j < SIZE)
		{
			tab1[i][j] = 2;
			j++;
		}
		i++;
	}
	tab1[0][2] = 4;
	initscr();
	noecho();
	cbreak();
	curs_set(FALSE);
	start_color();
	init_pair(1, COLOR_BLACK, COLOR_WHITE);
	init_pair(2, COLOR_RED, COLOR_BLUE);
	init_pair(4, COLOR_RED, COLOR_GREEN);
	getmaxyx(stdscr, y_max, x_max);

	ft_draw_grid(tab1);
	refresh();
	while (1)
	{
		ch = getch();
		//tab1 = ft_keyTrigger(ch);
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
