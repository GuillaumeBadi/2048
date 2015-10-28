/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_2048.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvolberg <dvolberg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 05:01:36 by dvolberg          #+#    #+#             */
/*   Updated: 2015/03/03 02:34:09 by dvolberg         ###   ########.fr       */
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
