/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvolberg <dvolberg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 22:20:56 by bsautron          #+#    #+#             */
/*   Updated: 2015/03/01 22:00:54 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	ft_print_ascii(int y, int x, int val)
{
	if (ft_strcmp(ft_itoa(val), "2") == 0)
		print_2(y, x);
	else if (ft_strcmp(ft_itoa(val), "4") == 0)
		print_4(y, x);
	else if (ft_strcmp(ft_itoa(val), "8") == 0)
		print_8(y, x);
	else if (ft_strcmp(ft_itoa(val), "16") == 0)
		ascii_16(y, x);
	else if (ft_strcmp(ft_itoa(val), "32") == 0)
		ascii_32(y, x);
	else if (ft_strcmp(ft_itoa(val), "64") == 0)
		ascii_64(y, x);
	else if (ft_strcmp(ft_itoa(val), "128") == 0)
		ascii_128(y, x);
	else if (ft_strcmp(ft_itoa(val), "256") == 0)
		ascii_256(y, x);
	else if (ft_strcmp(ft_itoa(val), "512") == 0)
		ascii_512(y, x);
	else if (ft_strcmp(ft_itoa(val), "1024") == 0)
		ascii_1024(y, x);
	else if (ft_strcmp(ft_itoa(val), "2048") == 0)
		ascii_2048(y, x);
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

void	ft_putnbr_to_grid(int y_max, int x_max, int **tab)
{
	int		x;
	int		y;
	int		i;
	int		j;

	i = 0;
	y = (y_max / SIZE) / 2;
	while (i < SIZE)
	{
		j = 0;
		x = (x_max / SIZE) / 2;
		while (j < SIZE)
		{
			if (tab[i][j] != 3)
			{
				if (!ft_print_tout(tab[i][j], x, y))
					ft_print_ascii(y, x, tab[i][j]);
			}
			x += (x_max / SIZE);
			j++;
		}
		i++;
		y += (y_max / SIZE);
	}
}

void	color_init_init(void)
{
	init_color(COLOR_BG, 119 * 3, 110 * 3, 101 * 3);
	init_color(COLOR_EMPTY, 154 * 3, 142 * 3, 139 * 3);
	init_color(COLOR_2, 255 * 3, 248 * 3, 29 * 3);
	init_color(COLOR_4, 155 * 3, 208 * 3, 19 * 3);
	init_color(COLOR_8, 15 * 3, 28 * 3, 239 * 3);
	init_color(COLOR_16, 155 * 3, 208 * 3, 29 * 3);
	init_color(COLOR_32, 15 * 3, 208 * 3, 39 * 3);
	init_color(COLOR_64, 155 * 3, 100 * 3, 23 * 3);
	init_color(COLOR_128, 155 * 3, 208 * 3, 239 * 3);
	init_color(COLOR_256, 155 * 3, 208 * 3, 239 * 3);
	init_color(COLOR_512, 155 * 3, 28 * 3, 29 * 3);
	init_color(COLOR_1024, 155 * 3, 28 * 3, 29 * 3);
	init_color(COLOR_2048, 155 * 3, 28 * 3, 29 * 3);
}

void	color_init_pair1(void)
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

void	color_init_pair2(void)
{
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(3, COLOR_BLACK, COLOR_WHITE);
	init_pair(13, 0, COLOR_EMPTY);
	init_pair(15, 0, COLOR_BG);
	init_pair(31, COLOR_BG, COLOR_2);
	init_pair(32, COLOR_BG, COLOR_4);
	init_pair(33, COLOR_BG, COLOR_8);
	init_pair(34, COLOR_BG, COLOR_16);
	init_pair(35, COLOR_BG, COLOR_32);
	init_pair(36, COLOR_BG, COLOR_64);
	init_pair(37, COLOR_BG, COLOR_128);
	init_pair(38, COLOR_BG, COLOR_256);
	init_pair(39, COLOR_BG, COLOR_512);
	init_pair(40, COLOR_BG, COLOR_1024);
	init_pair(41, COLOR_BG, COLOR_2048);
	init_pair(42, COLOR_BG, COLOR_4098);
}

void	ft_init(void)
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
