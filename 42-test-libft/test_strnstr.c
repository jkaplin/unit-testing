/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strnstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 14:09:34 by jkaplin           #+#    #+#             */
/*   Updated: 2019/02/15 12:11:15 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft.h"

int		cmp_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*your_result;
	char	*true_result;

	your_result = ft_strnstr(haystack, needle, len);
	true_result = strnstr(haystack, needle, len);
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n");
	printf("haystack = \"%s\" | needle = \"%s\" | len = %d\n\n", haystack, needle, (int)len);
	printf("your_result: \"%s\"\n", your_result);
	printf("true_result: \"%s\"\n", true_result);
	if ((your_result == NULL && true_result == NULL) || (your_result != NULL && true_result != NULL && strcmp(your_result, true_result) == 0))
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

int		test_strnstr()
{
	int		sum;

	printf("char	*ft_strnstr(const char *haystack, const char *needle, size_t len);\n");

	sum = 0;
	sum += cmp_strnstr("testing", "t", 1);
	sum += cmp_strnstr("testing", "stig", 0);
	sum += cmp_strnstr("", "test", 1);
	sum += cmp_strnstr("test", "", 7);
	sum += cmp_strnstr("testing", "est", 4);
	sum += cmp_strnstr("testing", "est", 3);
	return (sum);
}
