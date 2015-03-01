/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <gbadi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 00:43:07 by gbadi             #+#    #+#             */
/*   Updated: 2015/03/01 01:24:24 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithme.h"

static int			check_movement(int **tab)
{
	int				i;
	int				j;

	i = -1;
	while (++i < SIZE - 1)
	{
		j = -1;
		while (++j < SIZE - 1)
		{
			if (tab[i][j] == tab[i][j + 1] || tab[i][j] == tab[i + 1][j])
				return (0);
		}
	}
	return (-1);
}

int					check(int **tab)
{
	int				max;
	int				i;
	int				j;
	int				vide;

	i = -1;
	max = 0;
	while (++i < SIZE)
	{
		j = -1;
		while (++j < SIZE)
		{
			max = (max > tab[i][j]) ? max : tab[i][j];
			vide = (tab[i][j] == EMPTY) ? 1 : 0;
		}
	}
	if (max == WIN_VALUE)
		return (1);
	if (!vide)
		return (check_movement(tab));
	return (0);
}
