/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_pair.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 15:40:28 by bsautron          #+#    #+#             */
/*   Updated: 2015/03/03 15:40:29 by bsautron         ###   ########.fr       */
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
