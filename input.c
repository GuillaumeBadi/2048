/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvolberg <dvolberg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 03:42:10 by dvolberg          #+#    #+#             */
/*   Updated: 2015/03/01 10:49:11 by dvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int		**ft_keytrigger(int key_press, t_env *env)
{
	int	ch;

	env->pop = 0;
	ch = key_press;
	if (ch == 27)
		exit(-1);
	if (ch == KEY_UP)
	{
		env->tab = move_top(env);
		env->tab = merge_top(env);
		env->tab = move_top(env);
	}
	else if (ch == KEY_DOWN)
	{
		env->tab = move_bottom(env);
		env->tab = merge_bottom(env);
		env->tab = move_bottom(env);
	}
	else if (ch == KEY_LEFT)
	{
		env->tab = move_left(env);
		env->tab = merge_left(env);
		env->tab = move_left(env);
	}
	else if (ch == KEY_RIGHT)
	{
		env->tab = move_right(env);
		env->tab = merge_right(env);
		env->tab = move_right(env);
	}
	if (env->pop)
		env->tab = fill_tab(env);
	return (env->tab);
}
