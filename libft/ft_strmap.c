/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvolberg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 17:40:16 by dvolberg          #+#    #+#             */
/*   Updated: 2014/11/07 21:25:32 by dvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new_s;
	int		i;

	i = 0;
	new_s = NULL;
	if (s && f)
	{
		new_s = ft_strnew(ft_strlen(s));
		while (s[i])
		{
			new_s[i] = (*f)(s[i]);
			i++;
		}
	}
	return (new_s);
}
