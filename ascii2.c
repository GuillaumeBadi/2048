/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ascii2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvolberg <dvolberg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 04:58:23 by dvolberg          #+#    #+#             */
/*   Updated: 2015/03/01 10:31:44 by dvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void ascii_5(int y, int x)
{
	mvprintw(y, x, " 888888");
	mvprintw(y + 1, x, " 88oo.\"");
	mvprintw(y + 2, x, "    `8b");
	mvprintw(y + 3, x, " 8888P'");
}

void ascii_6(int y, int x)
{
	mvprintw(y, x, "   dP'  ");
	mvprintw(y + 1, x, " .d8'   ");
	mvprintw(y + 2, x, " 8P\"\"\"Yb");
	mvprintw(y + 3, x, " `YboodP");
}

void ascii_8(int y, int x)
{
	mvprintw(y, x, " .dP\"o.");
	mvprintw(y + 1, x, " `8b.d'");
	mvprintw(y + 2, x, " d'`Y8b");
	mvprintw(y + 3, x, " `bodP'");
}

void ascii_9(int y, int x)
{
	mvprintw(y, x, " dP\"\"Yb");
	mvprintw(y + 1, x, " Ybood8");
	mvprintw(y + 2, x, "   .8P'");
	mvprintw(y + 3, x, "  .dP' ");
}
