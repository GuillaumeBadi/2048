/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <gbadi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 03:23:38 by gbadi             #+#    #+#             */
/*   Updated: 2015/03/01 01:30:09 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithme.h"

size_t				get_highscore(void)
{
	int				fd;

	if (fd = open("score.txt", O_RDONLY) < 0)
		return (0);

}

int					main(void)
{
	t_env			*e;

	srand(time(NULL));
	if (WIN_VALUE % 2)
	{
		ft_putendl("Please use a power of two as the win value");
		return (-1);
	}
	e = (t_env *)malloc(sizeof(t_env));
	e->tab = make_tab();
	e->score = 0;
	e->highscore = get_highscore();
	return (0);
}
