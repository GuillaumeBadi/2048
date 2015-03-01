/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <gbadi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 03:23:38 by gbadi             #+#    #+#             */
/*   Updated: 2015/03/01 05:52:17 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int					main(void)
{
	char			playing;
	t_env			*env;
	int				ret;
	int 			ch;
	int				y_max;
	int				x_max;
	int				y_new;
	int				x_new;

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
	ft_draw_grid(env->tab);
	getmaxyx(stdscr, y_max, x_max);

	playing = 1;
	while (playing)
	{
		ret = check(env);
		if (ret == -1)
		{
			printf("%s\n", "perdu");
			playing = 0;
			return (-1);
		}
		else if (ret == 1)
		{
			printf("%s\n", "gagne");
			playing = 0;
			return (42);
		}
		getmaxyx(stdscr, y_new, x_new);
		if ((y_new != y_max || x_new != x_max) && y_new > 16 && x_new > 16)
		{
			y_max = y_new;
			x_max = x_new;
		}
		else if (y_new <= 16 || x_new <= 16)
		{
			mvprintw(0, 0, "la fenêtre est trop petite");
			continue ;
		}

		//clear();
		ch = getch();
		env->tab = ft_keyTrigger(ch, env);
		// print_tab(env->tab);
		// env->tab = move_right(env->tab);
		// env->tab = merge_right(env->tab);
		// env->tab = move_right(env->tab);
		// dprintf(1, "%s\n", "okok");
		ft_draw_grid(env->tab);
		refresh();
	}
	// endwin();
	return (0);
}
