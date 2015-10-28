/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ascii.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvolberg <dvolberg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 04:56:42 by dvolberg          #+#    #+#             */
/*   Updated: 2015/03/01 19:06:15 by dvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void ascii_0(int y, int x)
{
	mvprintw(y, x, "  dP\"Yb ");
	mvprintw(y + 1, x, " dP   Yb");
	mvprintw(y + 2, x, " Yb   dP");
	mvprintw(y + 3, x, "  YbodP ");
}

void ascii_1(int y, int x)
{
	mvprintw(y, x, "   .d");
	mvprintw(y + 1, x, " .d88");
	mvprintw(y + 2, x, "   88");
	mvprintw(y + 3, x, "   88");
}

void ascii_2(int y, int x)
{
	mvprintw(y, x, " oP\"Yb.");
	mvprintw(y + 1, x, " \"' dP'");
	mvprintw(y + 2, x, "   dP' ");
	mvprintw(y + 3, x, " .d8888");
}

void ascii_3(int y, int x)
{
	mvprintw(y, x, " 88888");
	mvprintw(y + 1, x, "   .dP");
	mvprintw(y + 2, x, " o `Yb");
	mvprintw(y + 3, x, " YbodP");
}

void ascii_4(int y, int x)
{
	mvprintw(y, x, "   dP88 ");
	mvprintw(y + 1, x, "  dP 88 ");
	mvprintw(y + 2, x, " d888888");
	mvprintw(y + 3, x, "     88 ");
}
