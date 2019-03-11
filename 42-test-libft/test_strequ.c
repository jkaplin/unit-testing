/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strequ.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 06:49:10 by jkaplin           #+#    #+#             */
/*   Updated: 2019/02/22 06:52:08 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft.h"

int		cmp_strequ(const char *s1, const char *s2)
{
	int		your_result;
	int		true_result;

	int		i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (s1[i] == s2[i])
		true_result = 1;
	else
		true_result = (0);

	your_result = ft_strequ(s1, s2);

	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n");
	printf("s1 = \"%s\" | s2 = \"%s\"\n\n", s1, s2);
	printf("your_result: %d\n", your_result);
	printf("true_result: %d\n", true_result);
	if(your_result == true_result)
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

int		test_strequ()
{
	int		sum;

	printf("int		ft_strequ(const char *s1, const char *s2);\n");

	sum = 0;
	sum += cmp_strequ("testing", "testing");
	sum += cmp_strequ("testing", "test");
	sum += cmp_strequ("inga", "ing");
	sum += cmp_strequ("testing", "stig");
	sum += cmp_strequ("", "test");
	sum += cmp_strequ("test", "");
	sum += cmp_strequ("", "");
	return (sum);
}
