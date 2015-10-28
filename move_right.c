/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 16:03:01 by bsautron          #+#    #+#             */
/*   Updated: 2015/03/03 16:03:05 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

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
