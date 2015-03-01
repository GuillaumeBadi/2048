/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <gbadi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 03:42:10 by dvolberg          #+#    #+#             */
/*   Updated: 2015/03/01 07:41:12 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int					**ft_keyTrigger(int key_press, t_env *env)
{
	env->pop = 0;
	if (key_press == KEY_UP)
	{
		env->tab = move_top(env);
		env->tab = merge_top(env);
		env->tab = move_top(env);
	}
	else if (key_press == KEY_DOWN)
	{
		env->tab = move_bottom(env);
		env->tab = merge_bottom(env);
		env->tab = move_bottom(env);
	}
	else if (key_press == KEY_LEFT)
	{
		env->tab = move_left(env);
		env->tab = merge_left(env);
		env->tab = move_left(env);
	}
	else if (key_press == KEY_RIGHT)
	{
		env->tab = move_right(env);
		env->tab = merge_right(env);
		env->tab = move_right(env);
	}
	if (env->pop)
	{
		clear();
		env->tab = fill_tab(env);
	}
	return (env->tab);
}

