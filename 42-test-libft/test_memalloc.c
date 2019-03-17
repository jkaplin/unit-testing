/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memalloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 07:55:33 by jkaplin           #+#    #+#             */
/*   Updated: 2019/02/21 08:35:42 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../libft.h"

int		cmp_memalloc(size_t size)
{
	char	*your_result;
	char	*true_result;
	size_t	i;

	your_result = (char *)ft_memalloc(size);
	true_result = (char *)malloc(size);
	i = 0;
	while (i < size)
	{
		true_result[i] = 0;
		i++;
	}
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n");
	printf("size = %d\n\n", (int)size);
	printf("your_result: [");
	i = 0;
	while (i < size)
	{
		if (i == size - 1)
			printf("%d", your_result[i]);
		else
			printf("%d, ", your_result[i]);
		i++;
	}
	printf("]\n");
	printf("true_result: [");
	i = 0;
	while (i < size)
	{
		if (i == size - 1)
			printf("%d", true_result[i]);
		else
			printf("%d, ", true_result[i]);
		i++;
	}
	printf("]\n");
	if ((your_result == NULL && true_result == NULL) || (strcmp(your_result, true_result) == 0))
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

int		test_memalloc()
{
	int		sum;

	printf("void	*ft_memalloc(size_t size);\n");

	sum = 0;
	sum += cmp_memalloc(3);
	sum += cmp_memalloc(9);
	sum += cmp_memalloc(0);
	return (sum);
}
