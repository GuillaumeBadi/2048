/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvolberg <dvolberg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 00:29:38 by gbadi             #+#    #+#             */
/*   Updated: 2015/03/01 18:26:34 by dvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int					full(t_env *env)
{
	int				i;
	int				j;

	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			if (env->tab[i][j] == EMPTY)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int					**fill_tab(t_env *env)
{
	int				x;
	int				y;

	x = rand() % SIZE;
	y = rand() % SIZE;
	if (env->tab[x][y] != EMPTY)
	{
		if (!full(env))
		{
			return (fill_tab(env));
		}
	}
	else
	{
		env->tab[x][y] = (rand() % 11 > TWO_RATIO) ? 4 : 2;
		return (env->tab);
	}
	return (env->tab);
}

void				free_env(t_env *e)
{
	int				i;

	i = 0;
	while (i < SIZE)
	{
		free(e->tab[i]);
		i++;
	}
	free(e->tab);
	free(e);
	e = NULL;
	e->tab = NULL;
}

int					**make_tab(void)
{
	int				**tab;
	size_t			i;
	size_t			j;

	i = 0;
	if (!(tab = (int **)malloc(sizeof(int *) * (SIZE + 1))))
		return (NULL);
	while (i < SIZE)
	{
		tab[i] = (int *)malloc(sizeof(int) * (SIZE + 1));
		if (tab[i] == NULL)
			return (NULL);
		j = 0;
		while (j < SIZE)
			tab[i][j++] = EMPTY;
		tab[i++][j] = 0;
	}
	tab[i] = 0;
	return (tab);
}
