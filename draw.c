/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <gbadi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 10:45:11 by dvolberg          #+#    #+#             */
/*   Updated: 2015/03/01 21:30:18 by gbadi            ###   ########.fr       */
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
			attron(COLOR_PAIR(ft_get_pair(tab[y][j])));
			i = y * (y_max / SIZE);
			while (i < (y + 1) * y_max / SIZE)
			{
				mvhline(i, j * (x_max / SIZE) + 1, ' ', x_max / SIZE);
				i++;
			}
			attroff(COLOR_PAIR(ft_get_pair(tab[y][j])));
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

void	ft_draw_grid(int **tab)
{
	int		y_max;
	int		x_max;

	wclear(stdscr);
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
	wrefresh(stdscr);
}
