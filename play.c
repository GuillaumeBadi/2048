/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <gbadi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 10:54:28 by dvolberg          #+#    #+#             */
/*   Updated: 2015/03/01 23:03:24 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void		part2(void)
{
	attron(COLOR_PAIR(25));
	mvprintw(9, (COLS / 2) - 31,
		"      d8888*`  88888X   88888X   :F   8888R     \"*8888888888i  ");
	attron(COLOR_PAIR(26));
	mvprintw(10, (COLS / 2) - 31,
		"    z8**\"`   : 88888X   88888f  x\"    8888R     .zf\"\"*8888888L ");
	attron(COLOR_PAIR(27));
	mvprintw(11, (COLS / 2) - 31,
		"  :?.....  ..F 48888X   88888  d8eeeee88888eer d8F      ^%%888E ");
	attron(COLOR_PAIR(28));
	mvprintw(12, (COLS / 2) - 31,
		" <\"\"888888888~  ?888X   8888\"         8888R    88>        `88~ ");
	attron(COLOR_PAIR(29));
	mvprintw(13, (COLS / 2) - 31,
		" 8:  \"888888*    \"88X   88*`          8888R    '%%N.       d*\"  ");
	attron(COLOR_PAIR(30));
	mvprintw(14, (COLS / 2) - 31,
		" \"\"    \"**\"`       ^\"===\"`         \"*%%%%%%%%%%%%**~    ^\"==");
}

int			youwin(int x, t_env *env)
{
	int				ch;

	(void)x;
	ch = 0;
	wclear(stdscr);
	wrefresh(stdscr);
	env->win = 1;
	while (1)
	{
		ch = getch();
		if (ch == 'q' || ch == 'Q' || ch == 27)
		{
			endwin();
			ft_draw_grid(env->tab);
			return (0);
		}
		if (ch == 10)
		{
			wclear(stdscr);
			ft_draw_grid(env->tab);
			return (1);
		}
		refresh();
	}
	return (0);
}

void		ft_do(t_env *env)
{
	env->y_max = env->y_new;
	env->x_max = env->x_new;
	clear();
	ft_draw_grid(env->tab);
}

int			ft_pour_le_win_mec(t_env *env)
{
	if (env->win == 0)
		env->status = youwin(env->x_max, env);
	if (env->status == 0)
		return (42);
	return (0);
}

int			play(t_env *env)
{
	wclear(stdscr);
	getmaxyx(stdscr, env->y_max, env->x_max);
	ft_draw_grid(env->tab);
	refresh();
	while (1)
	{
		getmaxyx(stdscr, env->y_new, env->x_new);
		if (env->y_new != env->y_max || env->x_new != env->x_max)
			ft_do(env);
		env->ret = check(env);
		if (env->ret == -1)
		{
			gameover(env->x_max);
			return (-1);
		}
		else if (env->ret == 1)
			if (ft_pour_le_win_mec(env) == 42)
				return (42);
		env->ch = getch();
		if (env->ch != -1)
			env->tab = ft_keytrigger(env->ch, env);
		refresh();
	}
	return (0);
}
