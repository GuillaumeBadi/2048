/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvolberg <dvolberg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 05:01:36 by dvolberg          #+#    #+#             */
/*   Updated: 2015/03/01 10:50:20 by dvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void ascii_2048(int y, int x)
{
	attron(COLOR_PAIR(COLOR_2048));
	ascii_2(y, x);
	ascii_0(y, x + 6);
	ascii_4(y, x + 14);
	ascii_8(y, x + 21);
	attroff(COLOR_PAIR(COLOR_2048));
}
