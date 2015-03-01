/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvolberg <dvolberg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 05:00:03 by dvolberg          #+#    #+#             */
/*   Updated: 2015/03/01 10:50:11 by dvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void print_2(int y, int x)
{
	attron(COLOR_PAIR(COLOR_2));
	ascii_2(y, x);
	attron(COLOR_PAIR(COLOR_2));
}

void print_4(int y, int x)
{
	attron(COLOR_PAIR(COLOR_4));
	ascii_4(y, x);
	attron(COLOR_PAIR(COLOR_4));
}

void print_8(int y, int x)
{
	attron(COLOR_PAIR(COLOR_8));
	ascii_8(y, x);
	attron(COLOR_PAIR(COLOR_8));
}

void ascii_16(int y, int x)
{
	attron(COLOR_PAIR(COLOR_16));
	ascii_1(y, x);
	ascii_6(y, x + 6);
	attroff(COLOR_PAIR(COLOR_16));
}

void ascii_32(int y, int x)
{
	attron(COLOR_PAIR(COLOR_32));
	ascii_3(y, x);
	ascii_2(y, x + 6);
	attron(COLOR_PAIR(COLOR_32));
}
