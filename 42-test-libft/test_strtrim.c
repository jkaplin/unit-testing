/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strtrim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 07:29:33 by jkaplin           #+#    #+#             */
/*   Updated: 2019/02/22 07:37:27 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft.h"

int		cmp_strtrim(const char *s)
{
	char	*s1;
	char	*your_result;
	char	*true_result;


	char	*trimmed;
	int		start;
	int		end;
	int		i;

	s1 = strdup(s);

	start = 0;
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	end = 0;
	while (s[end])
		end++;
	end--;
	while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
		end--;
	trimmed = ft_strnew(end - start);
	i = 0;
	while (start <= end)
	{
		trimmed[i] = s[start];
		i++;
		start++;
	}
	trimmed[i] = '\0';
	true_result = trimmed;

	your_result = ft_strtrim(s1);

	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n");
	printf("s = \"%s\"\n\n", s);
	printf("your_result: \"%s\"\n", your_result);
	printf("true_result: \"%s\"\n", true_result);
	if ((your_result == NULL && true_result == NULL) || strcmp(your_result, true_result) == 0)
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

int		test_strtrim()
{
	int		sum;

	printf("char	*ft_strtrim(char const *s);\n");

	sum = 0;
	sum += cmp_strtrim("testing");
	sum += cmp_strtrim("");
	sum += cmp_strtrim("   test      ");
	sum += cmp_strtrim("  t  e  s  t   ");
	sum += cmp_strtrim("te               st\n");
	sum += cmp_strtrim("\n    check\tthis    \t");
	return (sum);
}
