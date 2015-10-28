/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 15:39:56 by bsautron          #+#    #+#             */
/*   Updated: 2015/03/03 15:39:57 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	ft_print_ascii(int y, int x, int val)
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

static void print(int y, int x, int val)
{
	if (!ft_print_tout(val, x, y))
		ft_print_ascii(y, x, val);
}

static void nop(void)
{
	int ch;

	ch = getch();
	wclear(stdscr);
	mvprintw(1, 1, "Really Nigga ?! Press Ctrl + C to quit");
	endwin();
	if (ch == 27)
		exit(-1);
}

static void	norme(int *x, int *j, int increm)
{
	*x += increm;
	(*j)++;
}

void		ft_putnbr_to_grid(int y_max, int x_max, int **tab)
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
				if (y_max >= 40 || x_max >= 40)
					print(y, x, tab[i][j]);
				else
					nop();
			}
			norme(&x, &j, x_max / SIZE);
		}
		i++;
		y += (y_max / SIZE);
	}
}
