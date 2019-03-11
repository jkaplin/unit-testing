/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstdel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 07:19:26 by jkaplin           #+#    #+#             */
/*   Updated: 2019/03/07 14:18:54 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft.h"
#include <stdlib.h>

void	*true_lstdel(t_list **alst, void (*del)(void *, size_t));

int		cmp_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*lst;
	t_list	*lst2;
	t_list	**your_result;
	t_list	**true_result;
	t_list	*lst3;

	lst3 = (*alst)->next;
	ft_lstdel(alst, del);

	lst = (t_list *)malloc(sizeof(t_list));
	lst->content = (char *)malloc(8 * sizeof(char));
	lst->content_size = 8;
	lst2 = (t_list *)malloc(sizeof(t_list));
	lst2->content = (char *)malloc(8 * sizeof(char));
	lst2->content_size = 8;
	lst2->next = NULL;
	lst->next = lst2;

	true_lstdel(&lst, del);

	your_result = alst;
	true_result = &lst;

	int diff = 0;
	if (!(*alst == NULL))
		diff++;

	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n");

	if ((lst3))
		printf("your_result: alst NOT FREED\n");
	else
		printf("your_result: alst FREED\n");
	printf("true_result: alst FREED");

	if (diff == 0)
	{
		printf("\n- > ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ \e[32m SUCCESS \e[0m\n");
		return (0);
	}
	else
	{
		printf("\n- > ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ \e[31m FAILURE\n \e[0m");
		return (1);
	}
}

static void	del(void *content, size_t size)
{
	if (size && content)
		size++;
}

int		test_lstdel()
{
	int		sum;

	t_list	*lst;
	t_list	*lst2;

	lst = (t_list *)malloc(sizeof(t_list));
	lst->content = (char *)malloc(8 * sizeof(char));
	lst->content_size = 8;
	lst2 = (t_list *)malloc(sizeof(t_list));
	lst2->content = (char *)malloc(8 * sizeof(char));
	lst2->content_size = 8;
	lst2->next = NULL;
	lst->next = lst2;

	printf("void	ft_lstdel(t_list **alst, void (*del)(void *, size_t));\n");

	sum = 0;
	sum += cmp_lstdel(&lst, del);
	return (sum);
}
