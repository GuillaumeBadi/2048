/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <gbadi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 03:23:38 by gbadi             #+#    #+#             */
/*   Updated: 2015/02/28 03:51:45 by kpedro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define SIZE 4
#define EMPTY 3
#define TWO_RATIO 8

int					**move_right(int **tab)
{
	size_t			i;
	size_t			j;

	i = -1;
	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j])
		{
			if (tab[i][j] != EMPTY && tab[i][j + 1] == EMPTY)
			{
				tab[i][j + 1] = tab[i][j];
				tab[i][j] = EMPTY;
			}
		}
	}
}