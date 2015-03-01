/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <gbadi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 00:27:09 by gbadi             #+#    #+#             */
/*   Updated: 2015/03/01 00:38:51 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "agorithme.h"

int					**merge_left(int **tab)
{
	int				i;
	int				j;

	i = -1;
	while (++i < SIZE)
	{
		j = -1;
		while (++j < SIZE - 1)
		{
			if (tab[i][j] != EMPTY && tab[i][j + 1] == tab[i][j])
			{
				tab[i][j + 1] *= 2;
				tab[i][j] = EMPTY;
			}
		}
	}
	return (tab);
}

int					**move_left(int **tab)
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
			while (tab[i][j] != EMPTY && tab[i][j - k - 1] == EMPTY)
				k++;
			if (k)
			{
				tab[i][j - k] = tab[i][j];
				tab[i][j] = EMPTY;
			}
		}
	}
	return (tab);
}

int					**move_right(int **tab)
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
			while (tab[i][j] != EMPTY && tab[i][j + k + 1] == EMPTY)
				k++;
			if (k)
			{
				tab[i][j + k] = tab[i][j];
				tab[i][j] = EMPTY;
			}
		}
	}
	return (tab);
}

int					**merge_right(int **tab)
{
	size_t			i;
	size_t			j;

	i = -1;
	while (++i < SIZE)
	{
		j = SIZE;
		while (--j > 0)
		{
			if (tab[i][j] != EMPTY && tab[i][j - 1] == tab[i][j])
			{
				tab[i][j - 1] *= 2;
				tab[i][j] = EMPTY;
			}
		}
	}
	return (tab);
}
