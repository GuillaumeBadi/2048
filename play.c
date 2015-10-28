/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 16:03:25 by bsautron          #+#    #+#             */
/*   Updated: 2015/03/03 16:03:27 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int	youwin(t_env *env)
{
	int		ch;

	ch = 0;
	wclear(stdscr);
	wrefresh(stdscr);
	printwin();
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

static void	ft_do(t_env *env)
{
	env->y_max = env->y_new;
	env->x_max = env->x_new;
	clear();
	ft_draw_grid(env->tab);
}

static int	ft_pour_le_win_mec(t_env *env)
{
	if (env->win == 0)
		env->status = youwin(env);
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
			gameover();
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
