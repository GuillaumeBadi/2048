/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcheck_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvolberg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/19 04:30:59 by dvolberg          #+#    #+#             */
/*   Updated: 2014/11/19 07:56:02 by dvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcheck_char(char *str, char *letter)
{
	int		i;
	int		j;

	if (letter == NULL || str == NULL)
		return (0);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == letter[j])
			j++;
		i++;
	}
	if (letter[j] == str[i])
		return (1);
	return (0);
}
