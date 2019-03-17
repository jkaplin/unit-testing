/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 09:58:04 by jkaplin           #+#    #+#             */
/*   Updated: 2019/02/21 10:05:10 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../libft.h"

int		cmp_strnew(size_t size)
{
	char	*your_result;
	char	*true_result;
	size_t	i;

	your_result = ft_strnew(size);
	true_result = (char *)malloc(size + 1);
	i = 0;
	while (i < size + 1)
	{
		true_result[i] = '\0';
		i++;
	}
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n");
	printf("size = %d\n\n", (int)size);
	printf("your_result: [");
	i = 0;
	while (i < size + 1)
	{
		if (i == size)
			printf("%d", your_result[i]);
		else
			printf("%d, ", your_result[i]);
		i++;
	}
	printf("]\n");
	printf("true_result: [");
	i = 0;
	while (i < size + 1)
	{
		if (i == size)
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

int		test_strnew()
{
	int		sum;

	printf("char	*ft_strnew(size_t size);\n");

	sum = 0;
	sum += cmp_strnew(3);
	sum += cmp_strnew(9);
	sum += cmp_strnew(0);
	return (sum);
}
