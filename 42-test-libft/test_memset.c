/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 17:58:12 by jkaplin           #+#    #+#             */
/*   Updated: 2019/02/15 12:12:25 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft.h"

int		cmp_memset(void *b, int c, size_t len)
{
	void	*b1;
	void	*b2;
	void	*your_result;
	void	*true_result;

	b1 = strdup(b);
	b2 = strdup(b);
	your_result = ft_memset(b1, c, len);
	true_result = memset(b2, c, len);
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n");
	printf("b = \"%s\" | c = '%c' | len = %d\n\n", b, c, (int)len);
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

int		test_memset()
{
	int		sum;

	printf("void	*ft_memset(void *b, int c, size_t len);\n");
	
	sum = 0;	
	sum += cmp_memset("testing", 'X', 3);
	sum += cmp_memset("testing", 'X', 7);
	sum += cmp_memset("testing", 'X', 9);
	sum += cmp_memset("testing", 'X', 0);
	sum += cmp_memset("", 'X', 3);
	return (sum);
}
