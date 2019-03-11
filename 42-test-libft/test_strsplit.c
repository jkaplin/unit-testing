/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strsplit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 08:22:50 by jkaplin           #+#    #+#             */
/*   Updated: 2019/02/22 11:36:00 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft.h"

char	**true_strsplit(char const *s, char c);

int		cmp_strsplit(const char *s, char c, char **true_result)
{
	char	*s1;
	char	**your_result;

	s1 = strdup(s);

	your_result = ft_strsplit(s1, c);

	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n");
	printf("s = \"%s\" | c = '%c'\n\n", s, c);
	
	int diff = 0;
	int	i = 0;
	while (true_result[i])
	{
		printf("your_result[%d]: \"%s\"\n", i, your_result[i]);
		printf("true_result[%d]: \"%s\"\n\n", i, true_result[i]);
		if (!((your_result[i] == NULL && true_result[i] == NULL) || strcmp(your_result[i], true_result[i]) == 0))
			diff++;
		i++;
	}
	if (!(your_result[i] == NULL && true_result[i] == NULL))
	{
		diff++;
		printf("your_result[%d]: \"%s\" (not NULL)\n", i, your_result[i]);
		printf("true_result[%d]: NULL\n", i);
	}
	else
	{
		printf("your_result[%d]: NULL\n", i);
		printf("true_result[%d]: NULL\n", i);
	}

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

int		test_strsplit()
{
	int		sum;

	printf("char	**ft_strsplit(char const *s, char c);\n");

	sum = 0;
	sum += cmp_strsplit("testing the split", ' ', true_strsplit("testing the split", ' '));
	sum += cmp_strsplit("testing the split", 't', true_strsplit("testing the split", 't'));
	sum += cmp_strsplit("testing the split", 'i', true_strsplit("testing the split", 'i'));
	sum += cmp_strsplit("", ' ', true_strsplit("", ' '));
	sum += cmp_strsplit("", '\0', true_strsplit("", '\0'));
	sum += cmp_strsplit("a", 't', true_strsplit("a", 't'));
	sum += cmp_strsplit("    ", ' ', true_strsplit("    ", ' '));
	sum += cmp_strsplit("a   a   a", ' ', true_strsplit("a   a   a", ' '));
	sum += cmp_strsplit("a   a   a", 'a', true_strsplit("a   a   a", 'a'));
	return (sum);
}
