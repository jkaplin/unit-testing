/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strcmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 14:21:48 by jkaplin           #+#    #+#             */
/*   Updated: 2019/02/23 11:06:53 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft.h"

int		cmp_strcmp(const char *s1, const char *s2)
{
	int		your_result;
	int		true_result;

	your_result = ft_strcmp(s1, s2);
	true_result = strcmp(s1, s2);
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

int		test_strcmp()
{
	int		sum;

	printf("int		ft_strcmp(const char *s1, const char *s2);\n");

	sum = 0;
	sum += cmp_strcmp("testing", "testing");
	sum += cmp_strcmp("testing", "test");
	sum += cmp_strcmp("testing", "ing");
	sum += cmp_strcmp("testing", "stig");
	sum += cmp_strcmp("", "test");
	sum += cmp_strcmp("test", "");
	return (sum);
}
