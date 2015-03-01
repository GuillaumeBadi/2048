/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <gbadi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 00:29:38 by gbadi             #+#    #+#             */
/*   Updated: 2015/03/01 00:42:16 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithme.h"

int					**fill_tab(int **tab)
{
	int				x;
	int				y;

	x = rand() % 4;
	y = rand() % 4;
	if (tab[x][y] != 3)
		return (fill_tab(tab));
	else
	{
		tab[x][y] = (rand() % 11 > TWO_RATIO) ? 4 : 2;
		return (tab);
	}
}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void				print_tab(int **tab)
{
	size_t			i;
	size_t			j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			dprintf(1, "%d ", (tab[i][j] == EMPTY) ? 0 : tab[i][j]);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
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
