/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_64.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvolberg <dvolberg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 05:00:13 by dvolberg          #+#    #+#             */
/*   Updated: 2015/03/03 02:30:40 by dvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void ascii_64(int y, int x)
{
	attron(COLOR_PAIR(COLOR_64));
	ascii_6(y, x + (SIZE - 18 / 2));
	ascii_4(y, x + (SIZE - 18 / 2) + 8);
	attroff(COLOR_PAIR(COLOR_64));
}
