/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 15:47:58 by jkaplin           #+#    #+#             */
/*   Updated: 2019/02/15 12:08:56 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft.h"

int		cmp_strcpy(char *dst, const char *src)
{
	char	*dst1;
	char	*dst2;
	char	*your_result;
	char	*true_result;

	dst1 = strdup(dst);
	dst2 = strdup(dst);
	your_result = ft_strcpy(dst1, src);
	true_result = strcpy(dst2, src);
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n");
	printf("dst = \"%s\" | src = \"%s\"\n\n", dst, src);
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

int		test_strcpy()
{
	int		sum;

	printf("char	*ft_strcpy(char *dst, const char *src);\n");

	sum = 0;
	sum += cmp_strcpy("testing", "test");
	sum += cmp_strcpy("", "test");
	sum += cmp_strcpy("test", "");
	return (sum);
}
