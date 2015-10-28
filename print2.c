/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvolberg <dvolberg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 05:00:13 by dvolberg          #+#    #+#             */
/*   Updated: 2015/03/01 19:44:20 by dvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void ascii_64(int y, int x)
{
	attron(COLOR_PAIR(COLOR_64));
	ascii_6(y, x + (SIZE - 18 / 2));
	ascii_4(y, x + (SIZE - 18 / 2) + 8);
	attroff(COLOR_PAIR(COLOR_64));
}

void ascii_128(int y, int x)
{
	attron(COLOR_PAIR(COLOR_128));
	ascii_1(y, x + (SIZE - 26 / 2));
	ascii_2(y, x + (SIZE - 26 / 2) + 6);
	ascii_8(y, x + (SIZE - 26 / 2) + 12);
	attroff(COLOR_PAIR(COLOR_128));
}

void ascii_256(int y, int x)
{
	attron(COLOR_PAIR(COLOR_256));
	ascii_2(y, x + (SIZE - 26 / 2));
	ascii_5(y, x + (SIZE - 26 / 2) + 6);
	ascii_6(y, x + (SIZE - 26 / 2) + 14);
	attroff(COLOR_PAIR(COLOR_256));
}

void ascii_512(int y, int x)
{
	attron(COLOR_PAIR(COLOR_512));
	ascii_5(y, x + (SIZE - 26 / 2));
	ascii_1(y, x + (SIZE - 26 / 2) + 6);
	ascii_2(y, x + (SIZE - 26 / 2) + 14);
	attroff(COLOR_PAIR(COLOR_512));
}

void ascii_1024(int y, int x)
{
	attron(COLOR_PAIR(COLOR_1024));
	ascii_1(y, x + (SIZE - 34 / 2));
	ascii_0(y, x + (SIZE - 34 / 2) + 5);
	ascii_2(y, x + (SIZE - 34 / 2) + 13);
	ascii_4(y, x + (SIZE - 34 / 2) + 20);
	attroff(COLOR_PAIR(COLOR_1024));
}
