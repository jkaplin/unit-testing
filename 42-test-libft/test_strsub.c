/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strsub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 07:02:11 by jkaplin           #+#    #+#             */
/*   Updated: 2019/02/22 07:19:43 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft.h"

int		cmp_strsub(const char *s, unsigned int start, size_t len)
{
	char	*s1;
	char	*s2;
	char	*your_result;
	char	*true_result;
	char	*sub;

	s1 = strdup(s);
	s2 = strdup(s);

	unsigned int	i;
	unsigned int	copy_start = start;

	sub = ft_strnew(len);
	i = 0;
	while (s1[copy_start] && i < (unsigned int)len)
	{
		sub[i] = s1[copy_start];
		copy_start++;
		i++;
	}
	true_result = sub;

	your_result = ft_strsub(s2, start, len);
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n");
	printf("s = \"%s\" | start = %d | len = %lu\n\n", s, start, len);
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

int		test_strsub()
{
	int		sum;

	printf("char	*ft_strsub(const char *s, unsigned int start, size_t len);\n");

	sum = 0;
	sum += cmp_strsub("testing this Sub Sandwitch", 13, 8);
	sum += cmp_strsub("testing this Sub Sandwitch", 17, 4);
	sum += cmp_strsub("testing this Sub Sandwitch", 21, 5);
	sum += cmp_strsub("testing this Sub Sandwitch", 21, 9);
	sum += cmp_strsub("test", 0, 0);
	sum += cmp_strsub("testing", 1, 0);
	sum += cmp_strsub("testing", 10, 1);
	sum += cmp_strsub("testing", 0, 6);
	sum += cmp_strsub("testing", 3, 7);
	sum += cmp_strsub("testing", 7, 1);
	sum += cmp_strsub("testing", 1, 0);
	return (sum);
}
