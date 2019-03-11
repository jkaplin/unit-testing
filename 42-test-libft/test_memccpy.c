/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memccpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 15:02:31 by jkaplin           #+#    #+#             */
/*   Updated: 2019/02/15 12:07:26 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft.h"

int		cmp_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*dst1;
	char	*dst2;
	char	*your_result;
	char	*true_result;

	dst1 = strdup(dst);
	dst2 = strdup(dst);
	your_result = ft_memccpy(dst1, src, c, n);
	true_result = memccpy(dst2, src, c, n);
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n");
	printf("dst = \"%s\" | src = \"%s\" | c = '%c' | n = %d\n\n", dst, src, (char)c, (int)n);
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

int		test_memccpy()
{
	int		sum;

	printf("void	*ft_memccpy(void *dst, const void *src, int c, size_t n);");

	sum = 0;
	sum += cmp_memccpy("testing", "abcdef", 'X', 3);
	sum += cmp_memccpy("testing", "abcdef", 'c', 6);
	sum += cmp_memccpy("testing", "abcdef", 'f', 9);
	sum += cmp_memccpy("testing", "abcdef", 'a', 0);
	sum += cmp_memccpy("", "abcdef", 'f', 3);
	return (sum);
}
