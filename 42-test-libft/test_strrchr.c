/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strrchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 13:42:36 by jkaplin           #+#    #+#             */
/*   Updated: 2019/02/15 12:13:10 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft.h"

int		cmp_strrchr(const char *s, int c)
{
	char	*s1;
	char	*s2;
	char	*your_result;
	char	*true_result;

	s1 = strdup(s);
	s2 = strdup(s);
	your_result = ft_strrchr(s1, c);
	true_result = strrchr(s2, c);
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n");
	printf("s = \"%s\" | c = '%c'\n\n", s, c);
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

int		test_strrchr()
{
	int		sum;

	printf("char	*ft_strrchr(const char *s, int c);\n");

	sum = 0;
	sum += cmp_strrchr("testing", 't');
	sum += cmp_strrchr("", 'i');
	sum += cmp_strrchr("test", 0);
	return (sum);
}
