/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvolberg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 16:43:50 by dvolberg          #+#    #+#             */
/*   Updated: 2014/11/08 16:42:08 by dvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_lstdel2(t_list **alst, void (*del)(void *, size_t))
{
	if (*alst)
	{
		ft_lstdel2(&(*alst)->next, del);
		ft_lstdelone(alst, del);
	}
}

void			ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	ft_lstdel2(alst, del);
	*alst = NULL;
}
