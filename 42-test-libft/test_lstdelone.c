/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstdelone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 06:35:57 by jkaplin           #+#    #+#             */
/*   Updated: 2019/03/07 14:19:30 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft.h"
#include <stdlib.h>

void	*true_lstdelone(t_list **alst, void (*del)(void *, size_t));

int		cmp_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*lst;
	t_list	**your_result;
	t_list	**true_result;

	ft_lstdelone(alst, del);

	lst = (t_list *)malloc(sizeof(t_list));
	lst->content = (char *)malloc(8 * sizeof(char));
	lst->content_size = 8;

	true_lstdelone(&lst, del);

	your_result = alst;
	true_result = &lst;

	int diff = 0;
	if (!((*your_result == NULL && *true_result == NULL)))
		diff++;

	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n");

	if (*your_result)
		printf("your_result: *alst NOT FREED \n");
	else
		printf("your_result: *alst FREED\n");
	printf("true_result: *alst FREED");

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
		free(content);
}

int		test_lstdelone()
{
	int		sum;

	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	lst->content = (char *)malloc(8 * sizeof(char));
	lst->content_size = 8;

	printf("void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t));\n");

	sum = 0;
	sum += cmp_lstdelone(&lst, del);
	return (sum);
}
