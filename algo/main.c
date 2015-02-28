/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <gbadi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 03:23:38 by gbadi             #+#    #+#             */
/*   Updated: 2015/03/01 00:15:29 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define SIZE 		4
#define EMPTY 		3
#define TWO_RATIO 	5
#define WIN_NUMBER 	2048

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

int					**move_top(int **tab)
{
	int				i;
	int				j;
	int				k;

	j = 0;
	i = 0;
	while (j < SIZE)
	{
		while (i < SIZE)
		{
			k = 0;
			while (i - k - 1 >= 0 && tab[i][j] != EMPTY && tab[i - k - 1][j] == EMPTY)
				k++;
			if (k)
			{
				tab[i - k][j] = tab[i][j];
				tab[i][j] = EMPTY;
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (tab);
}

int					**move_bottom(int **tab)
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
			while (i + k + 1 < SIZE && tab[i][j] != EMPTY && tab[i + k + 1][j] == EMPTY)
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

int					**merge_bottom(int **tab)
{
	int				i;
	int				j;

	j = 0;
	while (j < SIZE)
	{
		i = 0;
		while (i < SIZE - 1)
		{
			if (tab[i][j] != EMPTY && tab[i + 1][j] == tab[i][j])
			{
				tab[i + 1][j] *= 2;
				tab[i][j] = EMPTY;
			}
			i++;	
		}
		j++;
	}
	return (tab);
}		

int					**move_left(int **tab)
{
	int				i;
	int				j;
	int				k;

	i = -1;
	while (tab[++i])
	{
		j = 0;
		while (tab[i][++j])
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

int					**merge_top(int **tab)
{
	int				i;
	int				j;

	j = 0;
	while (j < SIZE)
	{
		i = 0;
		while (i < SIZE)
		{
			if (tab[i][j] != EMPTY && tab[i + 1][j] == tab[i][j])
			{
				tab[i][j] = tab[i + 1][j] * 2;
				tab[i + 1][j] = EMPTY;
			}
			i++;	
		}
		j++;
	}
	return (tab);
}

int					**merge_left(int **tab)
{
	int				i;
	int				j;

	i = -1;
	while (tab[++i])
	{
		j = SIZE - 1;
		while (tab[i][--j])
		{
			if (tab[i][j] != EMPTY && tab[i][j - 1] == tab[i][j])
			{
				tab[i][j - 1] = tab[i][j] * 2;
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
	while (tab[++i])
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
	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j])
		{
			if (tab[i][j] != EMPTY && tab[i][j + 1] == tab[i][j])
			{
				tab[i][j + 1] = tab[i][j] * 2;
				tab[i][j] = EMPTY;
			}	
		}
	}
	return (tab);
}

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void				print_tab(int **tab)
{
	size_t			i;
	size_t			j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while(tab[i][j])
		{
			dprintf(1, "%d ", (tab[i][j] == EMPTY)? 0 : tab[i][j]);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

int					**make_tab()
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

int					main(void)
{
	int 			**test;

	srand(time(NULL));
	test = make_tab();
	test = fill_tab(test);
	test = fill_tab(test);
	print_tab(test);
	test = move_bottom(test);
	test = merge_bottom(test);
	test = move_bottom(test);
	printf("\n");
	print_tab(test);
	return (0);
}
