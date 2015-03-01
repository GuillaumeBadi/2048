/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <gbadi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 22:20:56 by bsautron          #+#    #+#             */
/*   Updated: 2015/03/01 08:01:15 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

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
			i = y * (y_max / SIZE);
			while (i < (y + 1) * y_max / SIZE)
			{
				mvhline(i, j * (x_max / SIZE) + 1, ' ', x_max / SIZE);
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
	char	*number;

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
				mvprintw(y, x - ft_intlen(tab[i][j]) / 2 + 1, (number = ft_itoa(tab[i][j])));
			free(number);
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
	keypad(stdscr, TRUE);
	curs_set(FALSE);
	start_color();
	init_color(COLOR_BG, 119 * 3, 110 * 3, 101 * 3);
	init_color(COLOR_EMPTY, 154 * 3, 142 * 3, 139 * 3);
	init_color(COLOR_2, 255 * 3, 248 * 3, 29 * 3);
	init_color(COLOR_4, 155 * 3, 208 * 3, 19 * 3);
	init_color(COLOR_8, 15 * 3, 28 * 3, 239 * 3);
	init_color(COLOR_16, 155 * 3, 208 * 3, 29 * 3);
	init_color(COLOR_32, 15 * 3, 208 * 3, 39 * 3);
	init_color(COLOR_64, 155 * 3, 100 * 3, 23 * 3);
	init_color(COLOR_128, 155 * 3, 208 * 3, 239 * 3);
	init_color(COLOR_256, 155 * 3, 208 * 3, 239 * 3);
	init_color(COLOR_512, 155 * 3, 28 * 3, 29 * 3);
	init_pair(1, COLOR_BLACK, COLOR_WHITE);
	init_pair(13, COLOR_BLACK, COLOR_EMPTY);
	init_pair(2 + 10, COLOR_EMPTY, COLOR_2);
	init_pair(4 + 10, COLOR_EMPTY, COLOR_4);
	init_pair(8 + 10, COLOR_EMPTY, COLOR_8);
	init_pair(16 + 10, COLOR_EMPTY, COLOR_16);
	init_pair(32 + 10, COLOR_EMPTY, COLOR_32);
	init_pair(64 + 10, COLOR_EMPTY, COLOR_64);
	init_pair(128 + 10, COLOR_EMPTY, COLOR_128);
	init_pair(256 + 10, COLOR_EMPTY, COLOR_256);
	init_pair(512 + 10, COLOR_EMPTY, COLOR_512);
	init_pair(5 + 10, 0, COLOR_BG);
}
