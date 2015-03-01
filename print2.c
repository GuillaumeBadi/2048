/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvolberg <dvolberg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 05:00:13 by dvolberg          #+#    #+#             */
/*   Updated: 2015/03/01 13:11:21 by dvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void ascii_64(int y, int x)
{
	attron(COLOR_PAIR(COLOR_64));
	ascii_6(y, x);
	ascii_4(y, x + 8);
	attroff(COLOR_PAIR(COLOR_64));
}

void ascii_128(int y, int x)
{
	attron(COLOR_PAIR(COLOR_128));
	ascii_1(y, x);
	ascii_2(y, x + 6);
	ascii_8(y, x + 12);
	attroff(COLOR_PAIR(COLOR_128));
}

void ascii_256(int y, int x)
{
	attron(COLOR_PAIR(COLOR_256));
	ascii_2(y, x);
	ascii_5(y, x + 6);
	ascii_6(y, x + 14);
	attroff(COLOR_PAIR(COLOR_256));
}

void ascii_512(int y, int x)
{
	attron(COLOR_PAIR(COLOR_512));
	ascii_5(y, x);
	ascii_1(y, x + 6);
	ascii_2(y, x + 14);
	attroff(COLOR_PAIR(COLOR_512));
}

void ascii_1024(int y, int x)
{
	attron(COLOR_PAIR(COLOR_1024));
	ascii_1(y, x);
	ascii_0(y, x + 5);
	ascii_2(y, x + 13);
	ascii_4(y, x + 20);
	attroff(COLOR_PAIR(COLOR_1024));
}
