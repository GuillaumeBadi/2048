/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <gbadi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 00:28:40 by gbadi             #+#    #+#             */
/*   Updated: 2015/03/01 21:09:23 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int					**move_bottom(t_env *env)
{
	int				i;
	int				j;
	int				k;

	j = -1;
	while (++j < SIZE)
	{
		i = SIZE - 1;
		while (--i >= 0)
		{
			k = 0;
			while (i + k + 1 < SIZE
				&& env->tab[i][j] != EMPTY && env->tab[i + k + 1][j] == EMPTY)
				k++;
			if (k)
			{
				env->pop = k;
				env->tab[i + k][j] = env->tab[i][j];
				env->tab[i][j] = EMPTY;
			}
		}
	}
	return (env->tab);
}

int					**merge_bottom(t_env *env)
{
	int				i;
	int				j;

	j = -1;
	while (++j < SIZE)
	{
		i = SIZE;
		while (--i > 0)
		{
			if (env->tab[i][j] != EMPTY && env->tab[i - 1][j] == env->tab[i][j])
			{
				env->tab[i][j] *= 2;
				env->score += env->tab[i][j];
				env->tab[i - 1][j] = EMPTY;
				env->pop = 1;
			}
		}
	}
	return (env->tab);
}

int					**move_top(t_env *env)
{
	int				i;
	int				j;
	int				k;

	j = -1;
	while (++j < SIZE)
	{
		i = 0;
		while (++i < SIZE)
		{
			k = 0;
			while (i - k - 1 >= 0
				&& env->tab[i][j] != EMPTY && env->tab[i - k - 1][j] == EMPTY)
				k++;
			if (k)
			{
				env->pop = k;
				env->tab[i - k][j] = env->tab[i][j];
				env->tab[i][j] = EMPTY;
			}
		}
	}
	return (env->tab);
}

int					**merge_top(t_env *env)
{
	int				i;
	int				j;

	j = -1;
	while (++j < SIZE)
	{
		i = -1;
		while (++i < SIZE - 1)
		{
			if (env->tab[i][j] != EMPTY && env->tab[i + 1][j] == env->tab[i][j])
			{
				env->tab[i][j] *= 2;
				env->score += env->tab[i][j];
				env->tab[i + 1][j] = EMPTY;
				env->pop = 1;
			}
		}
	}
	return (env->tab);
}
