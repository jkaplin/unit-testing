/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strclr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 10:16:46 by jkaplin           #+#    #+#             */
/*   Updated: 2019/02/21 11:29:00 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../libft.h"

int		cmp_strclr(char *s)
{
	char	*your_s;
	char	*true_s;
	char	*your_result;
	char	*true_result;
	int		i;
	int		size;

	size = strlen(s);

	your_s = strdup(s);
	true_s = strdup(s);
	ft_strclr(your_s);
	your_result = your_s;

	if (true_s != NULL)
	{
		i = 0;
		while (s[i])
		{
			true_s[i] = '\0';
			i++;
		}
	}
	true_result = true_s;

	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n");

	printf("s = \"%s\"\n\n", s);
	printf("your_result: s = [");
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
	printf("true_result: s = [");
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

int		test_strclr()
{
	int		sum;

	printf("void	ft_strclr(char *s);\n");

	sum = 0;
	sum += cmp_strclr("test");
	sum += cmp_strclr("");

	return (sum);
}
