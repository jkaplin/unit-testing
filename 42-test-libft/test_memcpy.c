/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 14:25:06 by jkaplin           #+#    #+#             */
/*   Updated: 2019/02/15 12:07:43 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft.h"

int		cmp_memcpy(void *dst, const void *src, size_t n)
{
	void	*dst1;
	void	*dst2;
	void	*your_result;
	void	*true_result;

	dst1 = strdup(dst);
	dst2 = strdup(dst);
	your_result = ft_memcpy(dst1, src, n);
	true_result = memcpy(dst2, src, n);
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n");
	printf("dst = \"%s\" | src = \"%s\" | n = %d\n\n", dst, src, (int)n);
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

int		test_memcpy()
{
	int		sum;

	printf("void	*ft_memcpy(void *dst, const void *src, size_t n);\n");

	sum = 0;
	sum += cmp_memcpy("testing", "abcdef", 3);
	sum += cmp_memcpy("testing", "abcdef", 6);
	sum += cmp_memcpy("testing", "abcdef", 9);
	sum += cmp_memcpy("testing", "abcdef", 0);
	sum += cmp_memcpy("", "abcdef", 3);
	return (sum);
}
