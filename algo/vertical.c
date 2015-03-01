/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <gbadi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 00:28:40 by gbadi             #+#    #+#             */
/*   Updated: 2015/03/01 01:30:13 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "agorithme.h"

int					**move_botom(int **tab)
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
				&& tab[i][j] != EMPTY && tab[i + k + 1][j] == EMPTY)
				k++;
			if (k)
			{
				tab[i + k][j] = tab[i][j];
				tab[i][j] = EMPTY;
			}
		}
	}
	return (tab);
}

int					**merge_botom(int **tab)
{
	int				i;
	int				j;

	j = -1;
	while (++j < SIZE)
	{
		i = SIZE;
		while (--i > 0)
		{
			if (tab[i][j] != EMPTY && tab[i - 1][j] == tab[i][j])
			{
				tab[i - 1][j] *= 2;
				tab[i][j] = EMPTY;
			}
		}
	}
	return (tab);
}

int					**move_top(int **tab)
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
				&& tab[i][j] != EMPTY && tab[i - k - 1][j] == EMPTY)
				k++;
			if (k)
			{
				tab[i - k][j] = tab[i][j];
				tab[i][j] = EMPTY;
			}
		}
	}
	return (tab);
}

int					**merge_top(int **tab)
{
	int				i;
	int				j;

	j = -1;
	while (++j < SIZE)
	{
		i = -1;
		while (++i < SIZE - 1)
		{
			if (tab[i][j] != EMPTY && tab[i + 1][j] == tab[i][j])
			{
				tab[i][j] = tab[i + 1][j] * 2;
				tab[i + 1][j] = EMPTY;
			}
		}
	}
	return (tab);
}
