/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strncmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 17:59:36 by jkaplin           #+#    #+#             */
/*   Updated: 2019/02/15 12:12:59 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft.h"

int		cmp_strncmp(const char *s1, const char *s2, size_t n)
{
	int		your_result;
	int		true_result;

	your_result = ft_strncmp(s1, s2, n);
	true_result = strncmp(s1, s2, n);
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

int		test_strncmp()
{
	int		sum;

	printf("int		ft_strncmp(const char *s1, const char *s2, size_t n);\n");

	sum = 0;
	sum += cmp_strncmp("testing", "testing", 4);
	sum += cmp_strncmp("testing", "test", 5);
	sum += cmp_strncmp("testing", "ing", 9);
	sum += cmp_strncmp("testing", "stig", 0);
	sum += cmp_strncmp("", "test", 1);
	sum += cmp_strncmp("test", "", 5);
	sum += cmp_strncmp("test", "", 0);
	sum += cmp_strncmp("", "", 0);
	return (sum);
}
