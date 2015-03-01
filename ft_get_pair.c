/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_pair.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <gbadi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 19:07:51 by gbadi             #+#    #+#             */
/*   Updated: 2015/03/01 21:30:03 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int		ft_get_pair(int val)
{
	int		i;
	int		ret;

	i = 2;
	ret = 31;
	if (val == EMPTY)
		return (COLOR_EMPTY);
	while (i < 100000)
	{
		if (i == val)
			return (ret);
		i *= 2;
		ret++;
	}
	return (0);
}
