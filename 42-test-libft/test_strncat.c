/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strncat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 19:49:01 by jkaplin           #+#    #+#             */
/*   Updated: 2019/02/15 12:10:59 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft.h"

int		cmp_strncat(char *s1, const char *s2, size_t n)
{
	char	*your_s1;
	char	*true_s1;
	char	*your_result;
	char	*true_result;

	your_s1 = strdup(s1);
	true_s1 = strdup(s1);
	your_result = ft_strncat(your_s1, s2, n);
	true_result = strncat(true_s1, s2, n);
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n");
	printf("s1 = \"%s\" | s2 = \"%s\" | n = %d\n\n", s1, s2, (int)n);
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

int		test_strncat()
{
	int		sum;

	printf("char	*ft_strncat(char *s1, const char *s2, size_t n);\n");

	sum = 0;
	sum += cmp_strncat("testing", "game", 5);
	sum += cmp_strncat("", "test", 2);
	sum += cmp_strncat("test", "", 0);
	return (sum);
}
