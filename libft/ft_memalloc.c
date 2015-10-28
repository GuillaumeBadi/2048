/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvolberg <dvolberg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 15:39:21 by dvolberg          #+#    #+#             */
/*   Updated: 2015/03/03 06:27:22 by dvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*dst;

	dst = NULL;
	if (size)
	{
		dst = malloc(sizeof(dst) * size);
		if (dst)
			ft_bzero(dst, size);
		else
			return (NULL);
	}
	return (dst);
}
