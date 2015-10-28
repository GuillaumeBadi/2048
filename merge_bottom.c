/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_bottom.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 15:41:18 by bsautron          #+#    #+#             */
/*   Updated: 2015/03/03 15:41:19 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

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
