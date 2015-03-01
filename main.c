/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvolberg <dvolberg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 03:23:38 by gbadi             #+#    #+#             */
/*   Updated: 2015/03/01 16:17:15 by dvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void		printmenu( bool sel, WINDOW *new_game, WINDOW *quit_game ) {
	if (sel) {

		wattron(new_game, COLOR_PAIR(3));
		// wborder(new_game, ACS_VLINE, ACS_VLINE, ACS_HLINE, ACS_HLINE,
		// ACS_ULCORNER, ACS_URCORNER, ACS_LLCORNER, ACS_LRCORNER);
		mvwprintw(new_game, 1, 1 , "     New Game     ");
		wattroff(new_game, COLOR_PAIR(3));
		// wborder(quit_game, ACS_VLINE, ACS_VLINE, ACS_HLINE, ACS_HLINE,
		// ACS_ULCORNER, ACS_URCORNER, ACS_LLCORNER, ACS_LRCORNER);
		mvwprintw(quit_game, 1, 1 , "     Quit Game    ");
	} else {
		// wborder(new_game, ACS_VLINE, ACS_VLINE, ACS_HLINE, ACS_HLINE,
		// ACS_ULCORNER, ACS_URCORNER, ACS_LLCORNER, ACS_LRCORNER);
		mvwprintw(new_game, 1, 1 , "     New Game     ");
		wattron(quit_game, COLOR_PAIR(3));
		// wborder(quit_game, ACS_VLINE, ACS_VLINE, ACS_HLINE, ACS_HLINE,
		// ACS_ULCORNER, ACS_URCORNER, ACS_LLCORNER, ACS_LRCORNER);
		mvwprintw(quit_game, 1, 1 , "     Quit Game    ");
		wattroff(quit_game, COLOR_PAIR(3));
	}
}

int			play(int y_max, int x_max, t_env *env)
{
	char	playing;
	int		y_new;
	int		x_new;
	int		ret;
	int 	ch;

	playing = 1;
	int		fd;
	fd = open("toto", O_WRONLY | O_TRUNC);
	while (playing)
	{
		ret = check(env);
		if (ret == -1)
		{
			gameover(x_max);
			playing = 0;
			// free_env(env);
			return (-1);
		}
		else if (ret == 1)
		{
			playing = 0;
			// free_env(env);
			return (42);
		}
		getmaxyx(stdscr, y_new, x_new);
		if (y_new != y_max || x_new != x_max)
		{
			y_max = y_new;
			x_max = x_new;
			clear();
			ft_draw_grid(env->tab);
		}
		else if (y_new <= 16 || x_new <= 16)
		{
			mvprintw(0, 0, "la fenêtre est trop petite");
			continue ;
		}

		ch = getch();
		if (ch != -1)
		{
			env->tab = ft_keytrigger(ch, env);
			ft_draw_grid(env->tab);
		}

	}
	return(0);
}

void		menu(int y, int x, t_env *env) {
	int		ch = 10;
	bool	sel = true;
	WINDOW	*new_game = newwin(30, 20 , 17, (x / 2) - 10);
	WINDOW	*quit_game = newwin(30, 20, 20, (x / 2) - 10);

	while (1)
	{
		ch = getch();
		printTitle(x);
		printmenu(sel, new_game, quit_game);

		if (ch == KEY_UP)
			sel = true;
		else if (ch == KEY_DOWN)
			sel = false;
		else if (ch == 10)  // 10 = KEY_ENTER
			break;
		if (ch == 27)
			break;
		wrefresh(stdscr);
		wrefresh(new_game);
		wrefresh(quit_game);
	}
	delwin(new_game);
	delwin(quit_game);
	if (sel)
	{
		env->tab = ft_keytrigger(ch, env);
		ft_draw_grid(env->tab);
		play(y, x, env);
	}
	endwin();
}

int			main(void)
{

	t_env	*env;
	int		y_max;
	int		x_max;

	srand(time(NULL));
	ft_init();
	if (WIN_VALUE % 2)
	{
		ft_putendl("Please use a power of two as the win value");
		return (-1);
	}
	env = (t_env *)malloc(sizeof(t_env));
	env->tab = make_tab();
	env->score = 0;
	env->tab = fill_tab(env);
	env->tab = fill_tab(env);
	getmaxyx(stdscr, y_max, x_max);
	menu(y_max, x_max, env);
	return (0);
}
