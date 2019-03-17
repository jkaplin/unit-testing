/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memmove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 16:21:36 by jkaplin           #+#    #+#             */
/*   Updated: 2019/02/18 12:37:38 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft.h"

int		cmp_memmove(void *dst, const void *src, size_t len)
{
	char	*dst1;
	char	*dst2;
	char	*your_result;
	char	*true_result;

	dst1 = strdup(dst);
	dst2 = strdup(dst);
	your_result = ft_memmove(dst1, src, len);
	true_result = memmove(dst2, src, len);
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n");
	printf("dst = \"%s\" | src = \"%s\" | len = %d\n\n", dst, src, (int)len);
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

int		test_memmove()
{
	int		sum;
	char	*str = (char *)malloc(sizeof(char) * 5);
	str = "test";

	printf("void	*ft_memmove(void *dst, const void *src, size_t len);\n");

	sum = 0;
	sum += cmp_memmove("testing", "abcdef", 3);
	sum += cmp_memmove("testing", "abcdef", 6);
	sum += cmp_memmove("testing", "abcdef", 9);
	sum += cmp_memmove("testing", "abcdef", 0);
	sum += cmp_memmove("", "abcdef", 3);
	sum += cmp_memmove(str, str + 2, 3);
	sum += cmp_memmove(str + 2, str, 3);
	return (sum);
}