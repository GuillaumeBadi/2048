/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tout.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <gbadi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 23:35:42 by gbadi             #+#    #+#             */
/*   Updated: 2015/03/01 23:37:33 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	color_init_init(void)
{
	init_color(COLOR_BG, 119 * 3, 110 * 3, 101 * 3);
	init_color(COLOR_EMPTY, 154 * 3, 142 * 3, 139 * 3);
	init_color(COLOR_2, 238 * 3, 228 * 3, 218 * 3);
	init_color(COLOR_4, 234 * 3, 224 * 3, 200 * 3);
	init_color(COLOR_8, 245 * 3, 149 * 3, 99 * 3);
	init_color(COLOR_16, 255 * 3, 102 * 3, 51 * 3);
	init_color(COLOR_32, 255 * 3, 51 * 3, 51 * 3);
	init_color(COLOR_64, 204 * 3, 0 * 3, 0 * 3);
	init_color(COLOR_128, 255 * 3, 204 * 3, 0 * 3);
	init_color(COLOR_256, 255 * 3, 208 * 3, 100 * 3);
	init_color(COLOR_512, 255 * 3, 208 * 3, 150 * 3);
	init_color(COLOR_1024, 255 * 3, 153 * 3, 51 * 3);
	init_color(COLOR_2048, 255 * 3, 51 * 3, 51 * 3);
}

int		ft_print_tout(int val, int x, int y)
{
	int		h;
	int		w;

	getmaxyx(stdscr, h, w);
	if (h <= 35 || (w / SIZE <= 34))
	{
		attron(COLOR_PAIR(ft_get_pair(val)));
		mvprintw(y, x - ft_intlen(val) / 2 + 1, ft_itoa(val));
		attroff(COLOR_PAIR(ft_get_pair(val)));
		return (1);
	}
	return (0);
}
