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
