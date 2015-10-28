/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 15:40:58 by bsautron          #+#    #+#             */
/*   Updated: 2015/03/03 15:40:59 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int			check_movement(t_env *env)
{
	int				i;
	int				j;

	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			if ((j + 1 < SIZE && env->tab[i][j] == env->tab[i][j + 1]) ||
				(i + 1 < SIZE && env->tab[i][j] == env->tab[i + 1][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (-1);
}

int					check(t_env *env)
{
	int				max;
	int				i;
	int				j;
	int				vide;

	i = -1;
	max = 0;
	vide = 0;
	while (++i < SIZE)
	{
		j = -1;
		while (++j < SIZE)
		{
			max = (max > env->tab[i][j]) ? max : env->tab[i][j];
			vide = (env->tab[i][j] == EMPTY) ? 1 : vide;
		}
	}
	if (max == WIN_VALUE)
		return (1);
	if (vide == 0)
		return (check_movement(env));
	return (0);
}
