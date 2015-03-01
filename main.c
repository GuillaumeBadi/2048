/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <gbadi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 03:23:38 by gbadi             #+#    #+#             */
/*   Updated: 2015/03/01 23:39:11 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void		printmenu(int *sel, WINDOW *new_game, WINDOW *quit_game, int ch)
{
	if (*sel)
	{
		wattron(new_game, COLOR_PAIR(3));
		mvwprintw(new_game, 1, 1, "     New Game     ");
		wattroff(new_game, COLOR_PAIR(3));
		mvwprintw(quit_game, 1, 1, "     Quit Game    ");
	}
	else
	{
		mvwprintw(new_game, 1, 1, "     New Game     ");
		wattron(quit_game, COLOR_PAIR(3));
		mvwprintw(quit_game, 1, 1, "     Quit Game    ");
		wattroff(quit_game, COLOR_PAIR(3));
	}
	if (ch == KEY_UP)
		*sel = 1;
	else if (ch == KEY_DOWN)
		*sel = 0;
}

void		menu(int x, int y, t_env *env)
{
	int		sel;
	WINDOW	*new_game;
	WINDOW	*quit_game;

	new_game = newwin(30, 20, 17, (x / 2) - 10);
	quit_game = newwin(30, 20, 20, (x / 2) - 10);
	sel = 1;
	while (1)
	{
		env->ch = getch();
		printtitle(x);
		printmenu(&sel, new_game, quit_game, env->ch);
		if (env->ch == 10 || env->ch == 27)
			break ;
		wrefresh(stdscr);
		wrefresh(new_game);
		wrefresh(quit_game);
	}
	delwin(new_game);
	delwin(quit_game);
	if (sel && ((env->tab = ft_keytrigger(env->ch, env))))
		play(env);
	endwin();
	(void)x;
	(void)y;
}

int			ft_pow(int b, int n)
{
	if (n == 0)
		return (1);
	else if (n == 1)
		return (b);
	else
		return (b * ft_pow(b, n - 1));
}

int			ft_check_win_value(void)
{
	int		i;

	i = 0;
	while (i < 31)
	{
		if (ft_pow(2, i) == WIN_VALUE)
			return (1);
		i++;
	}
	return (0);
}

int			main(void)
{
	t_env	*env;
	int		y_max;
	int		x_max;

	if (!ft_check_win_value())
	{
		ft_putendl_fd("Please use a power of two as the win value", 2);
		return (-1);
	}
	if (SIZE < 1 || SIZE > 10)
	{
		ft_putendl_fd("Please use a size between 1 - 10", 2);
		return (1);
	}
	srand(time(NULL));
	ft_init();
	env = (t_env *)malloc(sizeof(t_env));
	env->tab = make_tab();
	env->score = 0;
	env->tab = fill_tab(env);
	env->tab = fill_tab(env);
	env->win = 0;
	getmaxyx(stdscr, y_max, x_max);
	menu(x_max, y_max, env);
	return (0);
}
