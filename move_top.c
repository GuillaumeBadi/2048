/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_top.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 16:03:15 by bsautron          #+#    #+#             */
/*   Updated: 2015/03/03 16:03:18 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

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
