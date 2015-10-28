/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_32.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvolberg <dvolberg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 05:00:03 by dvolberg          #+#    #+#             */
/*   Updated: 2015/03/03 02:29:53 by dvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void ascii_32(int y, int x)
{
	attron(COLOR_PAIR(COLOR_32));
	ascii_3(y, x + (SIZE - 18 / 2));
	ascii_2(y, x + (SIZE - 18 / 2) + 6);
	attron(COLOR_PAIR(COLOR_32));
}
