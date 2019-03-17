/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   true_lstdel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 08:01:57 by jkaplin           #+#    #+#             */
/*   Updated: 2019/02/24 08:01:58 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	true_lstdelone(t_list **alst, void (*del)(void *, size_t));

void	true_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	while ((*alst))
	{
		tmp = *alst;
		alst = &((*alst)->next);
		true_lstdelone(&tmp, del);
	}
}
