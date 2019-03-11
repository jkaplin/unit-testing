/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 13:51:07 by jkaplin           #+#    #+#             */
/*   Updated: 2019/02/15 12:09:11 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft.h"

int		cmp_strstr(const char *haystack, const char *needle)
{
	char	*your_result;
	char	*true_result;

	your_result = ft_strstr(haystack, needle);
	true_result = strstr(haystack, needle);
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n");
	printf("haystack = \"%s\" | needle = \"%s\"\n\n", haystack, needle);
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

int		test_strstr()
{
	int		sum;

	printf("char	*ft_strstr(const char *haystack, const char *needle);\n");

	sum = 0;
	sum += cmp_strstr("testing", "t");
	sum += cmp_strstr("testing", "test");
	sum += cmp_strstr("testing", "ing");
	sum += cmp_strstr("testing", "stig");
	sum += cmp_strstr("", "test");
	sum += cmp_strstr("test", "");
	return (sum);
}
