/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bzero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 17:58:30 by jkaplin           #+#    #+#             */
/*   Updated: 2019/03/02 12:35:01 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft.h"

int		cmp_bzero(void *s, size_t n)
{
	char	*s_ptr;
	char	*s1;
	char	*s2;
	int		i;
	
	s_ptr = s;
	s1 = strdup(s);
	s2 = strdup(s);
	ft_bzero(s1, n);
	bzero(s2, n);
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n");
	printf("s = \"%s\" | n = %d\n\n", s_ptr, (int)n);
	printf("your_result: s =");
	i = 0;
	while (s_ptr[i])
	{
		if (s1[i] == '\0')
			printf(" \\0 ");
		else
			printf(" %c ", s1[i]);
		i++;
	}
	printf("\n");
	printf("true_result: s = ");
	i = 0;
	while (s_ptr[i])
	{
		if (s2[i] == '\0')
			printf(" \\0 ");
		else
			printf(" %c ", s2[i]);
		i++;
	}
	printf("\n");
	if ((s1 == NULL && s2 == NULL) || strcmp(s1, s2) == 0)
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

int		test_bzero()
{
	int		sum;

	printf("void	ft_bzero(void *s, size_t n);\n");

	sum = 0;
	sum += cmp_bzero("testing", 3);
	sum += cmp_bzero("testing", 7);
	sum += cmp_bzero("testing", 9);
	sum += cmp_bzero("testing", 0);
	sum += cmp_bzero("", 3);
	return (sum);
}
