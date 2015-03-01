/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvolberg <dvolberg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 05:01:36 by dvolberg          #+#    #+#             */
/*   Updated: 2015/03/01 22:36:33 by dvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void ascii_2048(int y, int x)
{
	attron(COLOR_PAIR(COLOR_2048));
	ascii_2(y, x + (SIZE - 34 / 2));
	ascii_0(y, x + (SIZE - 34 / 2) + 6);
	ascii_4(y, x + SIZE - 34 / 2 + 14);
	ascii_8(y, x + SIZE - 34 / 2 + 21);
	attroff(COLOR_PAIR(COLOR_2048));
}

void ascii_4096(int y, int x)
{
	attron(COLOR_PAIR(COLOR_4096));
	ascii_4(y, x + (SIZE - 34 / 2));
	ascii_0(y, x + (SIZE - 34 / 2) + 6);
	ascii_9(y, x + SIZE - 34 / 2 + 14);
	ascii_6(y, x + SIZE - 34 / 2 + 21);
	attroff(COLOR_PAIR(COLOR_4096));
}
