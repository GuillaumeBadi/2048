/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_1024.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvolberg <dvolberg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 05:00:13 by dvolberg          #+#    #+#             */
/*   Updated: 2015/03/03 02:32:51 by dvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void ascii_1024(int y, int x)
{
	attron(COLOR_PAIR(COLOR_1024));
	ascii_1(y, x + (SIZE - 34 / 2));
	ascii_0(y, x + (SIZE - 34 / 2) + 5);
	ascii_2(y, x + (SIZE - 34 / 2) + 13);
	ascii_4(y, x + (SIZE - 34 / 2) + 20);
	attroff(COLOR_PAIR(COLOR_1024));
}
