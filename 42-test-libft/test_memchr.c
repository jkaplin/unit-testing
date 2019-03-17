/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 14:49:44 by jkaplin           #+#    #+#             */
/*   Updated: 2019/02/15 12:10:00 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft.h"

int		cmp_memchr(const void *s, int c, size_t n)
{
	char	*s1;
	char	*s2;
	char	*your_result;
	char	*true_result;

	s1 = strdup(s);
	s2 = strdup(s);
	your_result = ft_memchr(s1, c, n);
	true_result = memchr(s2, c, n);
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n");
	printf("s = \"%s\" | c = '%c' | n = %d\n\n", s, (char)c, (int)n);
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

int		test_memchr()
{
	int		sum;

	printf("void	*ft_memchr(const void *s, int c, size_t n);\n");

	sum = 0;
	sum += cmp_memchr("testing", 'X', 3);
	sum += cmp_memchr("testing", 's', 6);
	sum += cmp_memchr("testing", 'g', 9);
	sum += cmp_memchr("testing", 't', 0);
	sum += cmp_memchr("", 'f', 3);
	return (sum);
}
