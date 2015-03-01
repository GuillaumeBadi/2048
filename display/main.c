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

#include "display.h"

# define COLOR_EMPTY	3 + 10
# define COLOR_BG		5 + 10
# define COLOR_2		2 + 10
# define COLOR_4		4 + 10
# define COLOR_8		8 + 10
# define COLOR_16		16 + 10
# define COLOR_32		32 + 10
# define COLOR_64		64 + 10
# define COLOR_128		128 + 10
# define COLOR_256		256 + 10
# define COLOR_512		512 + 10
# define COLOR_1024		1024 + 10
# define COLOR_2048		2048 + 10
# define COLOR_4098		4098 + 10

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
			attron(COLOR_PAIR(tab[y][j] + 10));
			i = y * (y_max / 4);
			while (i < (y + 1) * y_max / 4)
			{
				mvhline(i, j * (x_max / 4) + 1, ' ', x_max / 4);
				i++;
			}
			attroff(COLOR_PAIR(tab[y][j] + 10));
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
			attron(COLOR_PAIR(15));
			mvhline(y, x, ' ', 2);
			x += x_max / SIZE;
			attroff(COLOR_PAIR(15));
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
			attron(COLOR_PAIR(15));
			mvhline(y, x, ' ', 1);
			attroff(COLOR_PAIR(15));
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
			attron(COLOR_PAIR(15));
			mvhline(y, x, ' ', 1);
			attroff(COLOR_PAIR(15));
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
			if (tab[i][j] != 3)
				mvprintw(y, x - ft_intlen(tab[i][j]) / 2 + 1, ft_itoa(tab[i][j]));
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
	initscr();
	noecho();
	cbreak();
	curs_set(FALSE);
	start_color();
	init_color(COLOR_BG, 119 * 3, 110 * 3, 101 * 3);
	init_color(COLOR_EMPTY, 154 * 3, 142 * 3, 139 * 3);
	init_color(COLOR_2, 255 * 3, 248 * 3, 239 * 3);
	init_color(COLOR_4, 155 * 3, 208 * 3, 239 * 3);
	init_color(COLOR_8, 155 * 3, 208 * 3, 239 * 3);
	init_color(COLOR_16, 155 * 3, 208 * 3, 239 * 3);
	init_color(COLOR_32, 155 * 3, 208 * 3, 239 * 3);
	init_color(COLOR_64, 155 * 3, 208 * 3, 239 * 3);
	init_color(COLOR_128, 155 * 3, 208 * 3, 239 * 3);
	init_color(COLOR_256, 155 * 3, 208 * 3, 239 * 3);
	init_color(COLOR_512, 155 * 3, 208 * 3, 239 * 3);
	init_pair(1, COLOR_BLACK, COLOR_WHITE);
	init_pair(13, COLOR_BLACK, COLOR_EMPTY);
	init_pair(2 + 10, COLOR_EMPTY, COLOR_2);
	init_pair(4 + 10, COLOR_EMPTY, COLOR_4);
	init_pair(8 + 10, COLOR_EMPTY, COLOR_4);
	init_pair(16 + 10, COLOR_EMPTY, COLOR_4);
	init_pair(32 + 10, COLOR_EMPTY, COLOR_4);
	init_pair(64 + 10, COLOR_EMPTY, COLOR_4);
	init_pair(128 + 10, COLOR_EMPTY, COLOR_4);
	init_pair(256 + 10, COLOR_EMPTY, COLOR_4);
	init_pair(512 + 10, COLOR_EMPTY, COLOR_4);
	init_pair(5 + 10, 0, COLOR_BG);
}

int		main(void)
{
	int		y_max;
	int		x_max;
	int		y_new;
	int		x_new;
	int		**tab;
	int		ch;

	ch = 0;
	tab = (int **)malloc(sizeof(int *) * SIZE);
	int i = 0;
	while (i < SIZE)
	{
		tab[i] = (int *)malloc(sizeof(int) * SIZE);
		int j = 0;
		while (j < SIZE)
		{
			tab[i][j] = 3;
			j++;
		}
		i++;
	}
	ft_init();
	tab[0][0] = 2;
	tab[0][1] = 4;
	tab[0][2] = 8;
	tab[0][3] = 16;

	getmaxyx(stdscr, y_max, x_max);

	ft_draw_grid(tab);
	refresh();
	while (1)
	{
		//ch = getch();
		//tab1 = ft_keyTrigger(ch);
		getmaxyx(stdscr, y_new, x_new);
		// une fonction qui check si ya un changement dans le int **
		if ((y_new != y_max || x_new != x_max) && y_new > 16 && x_new > 16)
		{
			y_max = y_new;
			x_max = x_new;
			clear();
			ft_draw_grid(tab);
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
