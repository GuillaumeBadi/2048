/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvolberg <dvolberg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 03:42:10 by dvolberg          #+#    #+#             */
/*   Updated: 2015/02/28 08:26:04 by dvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	right(int x)
{
	int x_max;
	int y_max;

	getmaxyx(stdscr, y_max, x_max);
	if ((x + 1 + x_max) < x)
		x++;
	return;
}

void	left(int x)
{
	int x_max;
	int y_max;

	getmaxyx(stdscr, y_max, x_max);
	if ((x - 1) > 0)
		x--;
	return;
}

void	up(int y)
{
	int x_max;
	int y_max;

	getmaxyx(stdscr, y_max, x_max);
	if ((y - 1) > 0)
		y--;
	return;
}

void	down(int y)
{
	int x_max;
	int y_max;

	getmaxyx(stdscr, y_max, x_max);
	if ((y + 1 + y_max) < y)
		y++;
	return;
}

int		ft_keyTrigger(int keyPress)
{
	int x;
	int y;

	if (keyPress == KEY_UP)
	{
		ft_putendl("Up Key");
		up(y - 2);
	}
	else if (keyPress == KEY_DOWN)
	{
		ft_putendl("Down Key");
		down(y - 2);
	}
	else if (keyPress == KEY_LEFT)
	{
		ft_putendl("Left Key");
		left(x - 1);
	}
	else if (keyPress == KEY_RIGHT)
	{
		ft_putendl("Right Key");
		right(x - 1);
	}
}

