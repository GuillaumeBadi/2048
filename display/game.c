/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <gbadi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 03:42:10 by dvolberg          #+#    #+#             */
/*   Updated: 2015/03/01 01:55:30 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int		**ft_keyTrigger(int keyPress, int **tab)
{
	if (keyPress == KEY_UP)
	{
		tab = move_top(tab);
		tab = merge_top(tab);
		tab = move_top(tab);
	}
	else if (keyPress == KEY_DOWN)
	{
		tab = move_down(tab);
		tab = merge_down(tab);
		tab = move_down(tab);
	}
	else if (keyPress == KEY_LEFT)
	{
		tab = move_left(tab);
		tab = merge_left(tab);
		tab = move_left(tab);
	}
	else if (keyPress == KEY_RIGHT)
	{
		tab = move_right(tab);
		tab = merge_right(tab);
		tab = move_right(tab);
	}
	return (tab);
}

