/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvolberg <dvolberg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 22:20:56 by dvolberg          #+#    #+#             */
/*   Updated: 2015/03/03 05:22:09 by dvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	color_init_pair1(void)
{
	init_pair(10, 231, COLOR_BLACK);
	init_pair(20, 251, COLOR_BLACK);
	init_pair(21, 249, COLOR_BLACK);
	init_pair(22, 247, COLOR_BLACK);
	init_pair(23, 245, COLOR_BLACK);
	init_pair(24, 243, COLOR_BLACK);
	init_pair(25, 241, COLOR_BLACK);
	init_pair(26, 239, COLOR_BLACK);
	init_pair(27, 237, COLOR_BLACK);
	init_pair(28, 235, COLOR_BLACK);
	init_pair(29, 233, COLOR_BLACK);
	init_pair(30, 232, COLOR_BLACK);
}

static void	color_init_pair2(void)
{
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(3, COLOR_BLACK, COLOR_WHITE);
	init_pair(13, 0, COLOR_EMPTY);
	init_pair(15, 0, COLOR_BG);
	init_pair(31, COLOR_BLACK, COLOR_2);
	init_pair(32, COLOR_BLACK, COLOR_4);
	init_pair(33, COLOR_WHITE, COLOR_8);
	init_pair(34, COLOR_WHITE, COLOR_16);
	init_pair(35, COLOR_WHITE, COLOR_32);
	init_pair(36, COLOR_WHITE, COLOR_64);
	init_pair(37, COLOR_WHITE, COLOR_128);
	init_pair(38, COLOR_WHITE, COLOR_256);
	init_pair(39, COLOR_WHITE, COLOR_512);
	init_pair(40, COLOR_WHITE, COLOR_1024);
	init_pair(41, COLOR_WHITE, COLOR_2048);
	init_pair(42, COLOR_WHITE, COLOR_4096);
}

static void	color_init_init(void)
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

void		ft_init(void)
{
	initscr();
	noecho();
	cbreak();
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);
	curs_set(FALSE);
	start_color();
	color_init_init();
	color_init_pair1();
	color_init_pair2();
}
