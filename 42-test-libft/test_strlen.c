/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 15:20:42 by jkaplin           #+#    #+#             */
/*   Updated: 2019/02/15 12:08:44 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft.h"

int		cmp_strlen(const char *s)
{
	char	*s1;
	char	*s2;
	int		your_result;
	int		true_result;

	s1 = strdup(s);
	s2 = strdup(s);
	your_result = ft_strlen(s1);
	true_result = strlen(s2);
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n");
	printf("s = \"%s\"\n\n", s);
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

int		test_strlen()
{
	int		sum;

	printf("size_t	ft_strlen(const char *s);\n");

	sum = 0;
	sum += cmp_strlen("testing");
	sum += cmp_strlen("");
	sum += cmp_strlen("testing more");
	return (sum);
}
