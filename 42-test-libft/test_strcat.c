/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strcat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 19:36:29 by jkaplin           #+#    #+#             */
/*   Updated: 2019/02/15 12:11:05 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft.h"

int		cmp_strcat(char *s1, const char *s2)
{
	char	*your_s1;
	char	*true_s1;
	char	*your_result;
	char	*true_result;

	your_s1 = strdup(s1);
	true_s1 = strdup(s1);
	your_result = ft_strcat(your_s1, s2);
	true_result = strcat(true_s1, s2);
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n");
	printf("s1 = \"%s\" | s2 = \"%s\"\n\n", s1, s2);
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

int		test_strcat()
{
	int		sum;

	printf("char	*ft_strcat(char *s1, const char *s2);\n");

	sum = 0;
	sum += cmp_strcat("testing", "game");
	sum += cmp_strcat("", "test");
	sum += cmp_strcat("test", "");
	return (sum);
}
