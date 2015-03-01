/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <gbadi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 03:23:38 by gbadi             #+#    #+#             */
/*   Updated: 2015/03/01 21:09:47 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void		printmenu( bool sel, WINDOW *new_game, WINDOW *quit_game ) {
	if (sel) {

		wattron(new_game, COLOR_PAIR(3));
		mvwprintw(new_game, 1, 1 , "     New Game     ");
		wattroff(new_game, COLOR_PAIR(3));
		mvwprintw(quit_game, 1, 1 , "     Quit Game    ");
	} else {
		mvwprintw(new_game, 1, 1 , "     New Game     ");
		wattron(quit_game, COLOR_PAIR(3));
		mvwprintw(quit_game, 1, 1 , "     Quit Game    ");
		wattroff(quit_game, COLOR_PAIR(3));
	}
}

int			play(t_env *env)
{
	char	playing;
	int		y_new;
	int		x_new;
	int		y_max;
	int		x_max;
	int		ret;
	int 	ch;

	playing = 1;
	int fd;
	fd = open("pd", O_RDWR | O_APPEND);

		getmaxyx(stdscr, y_max, x_max);
		ft_draw_grid(env->tab);
		refresh();
	while (playing)
	{
		getmaxyx(stdscr, y_new, x_new);
		if (y_new != y_max || x_new != x_max)
		{
			y_max = y_new;
			x_max = x_new;
			clear();
			ft_draw_grid(env->tab);
		}
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
		}/*
		if (y_new != y_max || x_new != x_max)
		{
			//y_max = y_new;
			//x_max = x_new;
		}
		else if (y_new <= 16 || x_new <= 16)
		{
			mvprintw(0, 0, "la fenêtre est trop petite");
			continue ;
		}*/

		ch = getch();
		if (ch != -1)
		{
			env->tab = ft_keytrigger(ch, env);
			ft_draw_grid(env->tab);
		}

		refresh();
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
		printtitle(x);
		printmenu(sel, new_game, quit_game);

		if (ch == KEY_UP)
			sel = true;
		else if (ch == KEY_DOWN)
			sel = false;
		else if (ch == 10)
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
		play(env);
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

	env->tab = (int **)malloc(sizeof(int *) * SIZE);

	getmaxyx(stdscr, y_max, x_max);
	menu(y_max, x_max, env);
	printf("%d\n", env->score);
	return (0);
}
