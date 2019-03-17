/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strnequ.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 06:54:06 by jkaplin           #+#    #+#             */
/*   Updated: 2019/02/22 06:58:15 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft.h"

int		cmp_strnequ(const char *s1, const char *s2, size_t n)
{
	int		your_result;
	int		true_result;

	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n)
		i++;
	if (i == n || s1[i] == s2[i])
		true_result = 1;
	else
		true_result = 0;

	your_result = ft_strnequ(s1, s2, n);

	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n");
	printf("s1 = \"%s\" | s2 = \"%s\" | n = %d\n\n", s1, s2, (int)n);
	printf("your_result: %d\n", your_result);
	printf("true_result: %d\n", true_result);
	if(your_result == true_result)
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

int		test_strnequ()
{
	int		sum;

	printf("int		ft_strnequ(const char *s1, const char *s2, size_t n);\n");

	sum = 0;
	sum += cmp_strnequ("testing", "testing", 4);
	sum += cmp_strnequ("testing", "test", 5);
	sum += cmp_strnequ("testing", "ing", 9);
	sum += cmp_strnequ("testing", "stig", 0);
	sum += cmp_strnequ("", "test", 1);
	sum += cmp_strnequ("test", "", 5);
	sum += cmp_strnequ("test", "", 0);
	sum += cmp_strnequ("", "", 0);
	return (sum);
}
