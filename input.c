/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <gbadi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 03:42:10 by dvolberg          #+#    #+#             */
/*   Updated: 2015/03/01 05:57:05 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int					**ft_keyTrigger(int key_press, t_env *env)
{
	int 			ch;

	env->pop = 0;
	if (key_press == '\033')
		getch();
	ch = getch();
	if (ch == 'A')
	{
		env->tab = move_top(env);
		env->tab = merge_top(env);
		env->tab = move_top(env);
	}
	else if (ch == 'B')
	{
		env->tab = move_bottom(env);
		env->tab = merge_bottom(env);
		env->tab = move_bottom(env);
	}
	else if (ch == 'D')
	{
		env->tab = move_left(env);
		env->tab = merge_left(env);
		env->tab = move_left(env);
	}
	else if (ch == 'C')
	{
		env->tab = move_right(env);
		env->tab = merge_right(env);
		env->tab = move_right(env);
	}
	if (env->pop)
		env->tab = fill_tab(env);
	return (env->tab);
}

