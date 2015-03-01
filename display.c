/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <gbadi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 22:20:56 by bsautron          #+#    #+#             */
/*   Updated: 2015/03/01 23:36:59 by gbadi            ###   ########.fr       */
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
