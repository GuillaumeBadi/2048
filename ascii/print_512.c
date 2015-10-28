/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_512.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvolberg <dvolberg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 05:00:13 by dvolberg          #+#    #+#             */
/*   Updated: 2015/03/03 02:32:26 by dvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void ascii_512(int y, int x)
{
	attron(COLOR_PAIR(COLOR_512));
	ascii_5(y, x + (SIZE - 26 / 2));
	ascii_1(y, x + (SIZE - 26 / 2) + 6);
	ascii_2(y, x + (SIZE - 26 / 2) + 14);
	attroff(COLOR_PAIR(COLOR_512));
}
