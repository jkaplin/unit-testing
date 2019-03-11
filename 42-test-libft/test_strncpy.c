/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strncpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 19:19:37 by jkaplin           #+#    #+#             */
/*   Updated: 2019/02/15 12:09:02 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft.h"

int		cmp_strncpy(char *dst, const char *src, size_t len)
{
	char	*dst1;
	char	*dst2;
	char	*your_result;
	char	*true_result;

	dst1 = strdup(dst);
	dst2 = strdup(dst);
	your_result = ft_strncpy(dst1, src, len);
	true_result = strncpy(dst2, src, len);
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

int		test_strncpy()
{
	int		sum;

	printf("char	*ft_strncpy(char *dst, const char *src, size_t len);\n");

	sum = 0;
	sum += cmp_strncpy("testing", "game", 3);
	sum += cmp_strncpy("", "test", 2);
	sum += cmp_strncpy("test", "", 7);
	sum += cmp_strncpy("test", "", 0);
	sum += cmp_strncpy("", "", 0);
	return (sum);
}
