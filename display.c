/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvolberg <dvolberg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 22:20:56 by bsautron          #+#    #+#             */
/*   Updated: 2015/03/01 14:42:04 by dvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	ft_putnbr_to_grid(int y_max, int x_max, int **tab)
{
	int		y_increm;
	int		x_increm;
	char	*number;
	int		x;
	int		y;
	int		i;
	int		j;
	int		h;
	int		w;

	y_increm = y_max / SIZE;
	x_increm = x_max / SIZE;
	i = 0;
	y = y_increm / 2;
	while (i < SIZE)
	{
		j = 0;
		x = x_increm / 2;
		while (j < SIZE)
		{
			if (tab[i][j] != 3)
			{
				getmaxyx(stdscr, h, w);
				if (h <= 35 || w <= 170)
				{
					attron(COLOR_PAIR(tab[i][j]));
					mvprintw(y, x - ft_intlen(tab[i][j]) / 2 + 1, ft_itoa(tab[i][j]));
					attroff(COLOR_PAIR(tab[i][j]));
				}
				else
				{
					if (ft_strcmp(ft_itoa(tab[i][j]), "2") == 0)
						print_2(y, x);
					else if (ft_strcmp(ft_itoa(tab[i][j]), "4") == 0)
						print_4(y, x);
					else if (ft_strcmp(ft_itoa(tab[i][j]), "8") == 0)
						print_8(y, x);
					else if (ft_strcmp(ft_itoa(tab[i][j]), "16") == 0)
						ascii_16(y, x);
					else if (ft_strcmp(ft_itoa(tab[i][j]), "32") == 0)
						ascii_32(y, x);
					else if (ft_strcmp(ft_itoa(tab[i][j]), "64") == 0)
						ascii_64(y, x);
					else if (ft_strcmp(ft_itoa(tab[i][j]), "128") == 0)
						ascii_128(y, x);
					else if (ft_strcmp(ft_itoa(tab[i][j]), "256") == 0)
						ascii_256(y, x);
					else if (ft_strcmp(ft_itoa(tab[i][j]), "512") == 0)
						ascii_512(y, x);
					else if (ft_strcmp(ft_itoa(tab[i][j]), "1024") == 0)
						ascii_1024(y, x);
					else if (ft_strcmp(ft_itoa(tab[i][j]), "2048") == 0)
						ascii_2048(y, x);
				}
			}
			x += x_increm;
			j++;
		}
		i++;
		y += y_increm;
	}
	(void)tab;
}

void	color_init(void)
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
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(3, COLOR_BLACK, COLOR_WHITE);
	init_pair(2, COLOR_BG, COLOR_2);
	init_pair(4, COLOR_BG, COLOR_4);
	init_pair(8, COLOR_BG, COLOR_8);
	init_pair(16, COLOR_BG, COLOR_16);
	init_pair(32, COLOR_BG, COLOR_32);
	init_pair(64, COLOR_BG, COLOR_64);
	init_pair(128, COLOR_BG, COLOR_128);
	init_pair(256, COLOR_BG, COLOR_256);
	init_pair(512, COLOR_BG, COLOR_512);
	init_pair(13, COLOR_BLACK, COLOR_EMPTY);
	init_pair(2 + 10, COLOR_BG, COLOR_2);
	init_pair(4 + 10, COLOR_BG, COLOR_4);
	init_pair(8 + 10, COLOR_BG, COLOR_8);
	// init_pair(16 + 10, COLOR_BG, COLOR_16); // A refaire
	init_pair(32 + 10, COLOR_BG, COLOR_32);
	init_pair(64 + 10, COLOR_BG, COLOR_64);
	init_pair(128 + 10, COLOR_BG, COLOR_128);
	init_pair(256 + 10, COLOR_BG, COLOR_256);
	init_pair(512 + 10, COLOR_BG, COLOR_512);
	init_pair(5 + 10, 0, COLOR_BG);
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
	color_init();
}
