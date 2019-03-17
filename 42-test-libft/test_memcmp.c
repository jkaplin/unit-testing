/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memcmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 14:56:36 by jkaplin           #+#    #+#             */
/*   Updated: 2019/03/04 12:22:05 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft.h"

int		cmp_memcmp(const void *s1, const void *s2, size_t n)
{
	int		your_result;
	int		true_result;
	void	*your_s1;
	void	*your_s2;
	void	*true_s1;
	void	*true_s2;
	
	your_s1 = strdup(s1);
	your_s2 = strdup(s2);
	true_s1 = strdup(s1);
	true_s2 = strdup(s2);
	your_result = ft_memcmp(your_s1, your_s2, n);
	true_result = memcmp(true_s1, true_s2, n);
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n");
	printf("s1 = \"%s\" | s2 = \"%s\" | n = %d\n\n", s1, s2, (int)n);
	printf("your_result: %d\n", your_result);
	printf("true_result: %d\n", true_result);
	if (your_result == true_result)
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

int		test_memcmp()
{
	int		sum;

	printf("int		ft_memcmp(const void *s1, const void *s2, size_t n);");

	sum = 0;
	sum += cmp_memcmp("testing", "testing", 3);
	sum += cmp_memcmp("testing", "testing", 7);
	sum += cmp_memcmp("testing", "testing", 9);
	sum += cmp_memcmp("testing", "", 0);
	sum += cmp_memcmp("", "abcdef", 3);
	sum += cmp_memcmp("test", "tegt", 5);
	sum += cmp_memcmp("test", "t", 1);
	sum += cmp_memcmp("ab", "abcdef", 0);
	sum += cmp_memcmp("abcdefg", "abcdef", 9);
	sum += cmp_memcmp("Chris", "Chrisx", 6);
	sum += cmp_memcmp("as\0te", "as\0ti", 5);
	return (sum);
}
