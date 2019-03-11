/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 09:48:57 by jkaplin           #+#    #+#             */
/*   Updated: 2019/02/24 06:32:58 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft.h"

t_list	*true_lstnew(void const *content, size_t content_size);

int		cmp_lstnew(void const *content, size_t content_size, t_list *true_result)
{
	t_list	*your_result;

	your_result = ft_lstnew(content, content_size);


	int diff = 0;
	if (!((your_result->content == NULL && true_result->content == NULL) || strcmp((char *)(your_result->content), (char *)(true_result->content)) == 0))
		diff++;
	if (!(your_result->next == NULL && true_result->next == NULL))
		diff++;

	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n");
	if (content == NULL)
		printf("content = NULL | content_size = %lu\n\n", content_size);
	else
		printf("content = \"%s\" | content_size = %lu\n\n", (char *)(content), content_size);
	printf("your_result: content = \"%s\"\n", (char *)(your_result->content));
	printf("true_result: content = \"%s\"\n", (char *)(true_result->content));
	printf("your_result: content_size = %lu\n", your_result->content_size);
	printf("true_result: content_size = %lu\n", true_result->content_size);
	if (your_result->next == NULL)
		printf("your_result: next = NULL\n");
	else
		printf("your_result: next != NULL\n");
	printf("true_result: next = NULL\n");

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

int		test_lstnew()
{
	int		sum;

	printf("t_list	*ft_lstnew(void const *content, size_t content_size);\n");

	sum = 0;
	sum += cmp_lstnew("content", 8 * sizeof(char), true_lstnew("content", 8 * sizeof(char)));
	sum += cmp_lstnew("", 1 * sizeof(char), true_lstnew("", 1 * sizeof(char)));
	sum += cmp_lstnew(NULL, 8 * sizeof(char), true_lstnew(NULL, 8 * sizeof(char)));
	return (sum);
}
