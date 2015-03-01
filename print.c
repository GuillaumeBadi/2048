/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvolberg <dvolberg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 05:00:03 by dvolberg          #+#    #+#             */
/*   Updated: 2015/03/01 19:44:48 by dvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void print_2(int y, int x)
{
	attron(COLOR_PAIR(COLOR_2));
	ascii_2(y, x + (SIZE - 10 / 2));
	attron(COLOR_PAIR(COLOR_2));
}

void print_4(int y, int x)
{
	attron(COLOR_PAIR(COLOR_4));
	ascii_4(y, x + (SIZE - 10 / 2));
	attron(COLOR_PAIR(COLOR_4));
}

void print_8(int y, int x)
{
	attron(COLOR_PAIR(COLOR_8));
	ascii_8(y, x + (SIZE - 10 / 2));
	attron(COLOR_PAIR(COLOR_8));
}

void ascii_16(int y, int x)
{
	attron(COLOR_PAIR(COLOR_16));
	ascii_1(y, x + (SIZE - 18 / 2));
	ascii_6(y, x + (SIZE - 18 / 2) + 6);
	attroff(COLOR_PAIR(COLOR_16));
}

void ascii_32(int y, int x)
{
	attron(COLOR_PAIR(COLOR_32));
	ascii_3(y, x + (SIZE - 18 / 2));
	ascii_2(y, x + (SIZE - 18 / 2) + 6);
	attron(COLOR_PAIR(COLOR_32));
}
