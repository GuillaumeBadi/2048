/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvolberg <dvolberg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 22:20:56 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/28 04:37:18 by dvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int		main(void)
{
	int x_max;
	int	y_max;
	int	x;
	int	y;
	WINDOW *field;

	initscr();
	noecho();
	curs_set(FALSE);
	getmaxyx(stdscr, y_max, x_max);
	field = newwin(y_max, x_max, 0, 0);
	y = 0;
	while (y < y_max)
	{
		x = 0;
		while (x < x_max)
		{
			mvwprintw(field, y, x, "+");
			x += x_max / 4;
		}
		y += y_max / 4;
	}


	wrefresh(field);
	sleep(5);
	delwin(field);
	endwin();

	return (0);
}
