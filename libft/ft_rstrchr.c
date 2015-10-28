/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rstrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvolberg <dvolberg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 22:20:16 by dvolberg          #+#    #+#             */
/*   Updated: 2015/02/04 22:20:44 by dvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_rstrchr(const char *str, char c)
{
	size_t	i;
	char	*dst;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	dst = ft_strsub(str, 0, i);
	return (dst);
}
