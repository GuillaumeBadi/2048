/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_16.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvolberg <dvolberg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 05:00:03 by dvolberg          #+#    #+#             */
/*   Updated: 2015/03/03 02:29:31 by dvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void ascii_16(int y, int x)
{
	attron(COLOR_PAIR(COLOR_16));
	ascii_1(y, x + (SIZE - 18 / 2));
	ascii_6(y, x + (SIZE - 18 / 2) + 6);
	attroff(COLOR_PAIR(COLOR_16));
}
