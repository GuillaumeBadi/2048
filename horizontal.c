/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <gbadi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 00:27:09 by gbadi             #+#    #+#             */
/*   Updated: 2015/03/01 21:17:57 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int					**merge_left(t_env *env)
{
	int				i;
	int				j;

	i = -1;
	while (++i < SIZE)
	{
		j = -1;
		while (++j < SIZE - 1)
		{
			if (env->tab[i][j] != EMPTY && env->tab[i][j + 1] == env->tab[i][j])
			{
				env->tab[i][j] *= 2;
				env->score += env->tab[i][j];
				env->tab[i][j + 1] = EMPTY;
				env->pop = 1;
			}
		}
	}
	return (env->tab);
}

int					**move_left(t_env *env)
{
	int				i;
	int				j;
	int				k;

	i = -1;
	while (++i < SIZE)
	{
		j = 0;
		while (++j < SIZE)
		{
			k = 0;
			while (env->tab[i][j] != EMPTY && env->tab[i][j - k - 1] == EMPTY)
				k++;
			if (k)
			{
				env->pop = k;
				env->tab[i][j - k] = env->tab[i][j];
				env->tab[i][j] = EMPTY;
			}
		}
	}
	return (env->tab);
}

int					**move_right(t_env *env)
{
	int				i;
	int				j;
	int				k;

	i = -1;
	while (++i < SIZE)
	{
		j = SIZE - 1;
		while (--j >= 0)
		{
			k = 0;
			while (env->tab[i][j] != EMPTY && env->tab[i][j + k + 1] == EMPTY)
				k++;
			if (k)
			{
				env->pop = k;
				env->tab[i][j + k] = env->tab[i][j];
				env->tab[i][j] = EMPTY;
			}
		}
	}
	return (env->tab);
}

int					**merge_right(t_env *env)
{
	int				i;
	int				j;

	i = -1;
	while (++i < SIZE)
	{
		j = SIZE;
		while (--j > 0)
		{
			if (env->tab[i][j] != EMPTY && env->tab[i][j - 1] == env->tab[i][j])
			{
				env->tab[i][j] *= 2;
				env->score += env->tab[i][j];
				env->tab[i][j - 1] = EMPTY;
				env->pop = 1;
			}
		}
	}
	return (env->tab);
}
