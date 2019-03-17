/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tolower.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 19:32:02 by jkaplin           #+#    #+#             */
/*   Updated: 2019/02/15 12:11:32 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>
#include "../libft.h"

int		cmp_tolower(int c)
{
	int		your_result;
	int		true_result;

	your_result = ft_tolower(c);
	true_result = tolower(c);
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n");
	printf("c = '%c'\n\n", c);
	printf("your_result: '%c'\n", your_result);
	printf("true_result: '%c'\n", true_result);
	if (your_result == true_result)
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

int		test_tolower()
{
	int		sum;

	printf("int		ft_tolower(int c);\n");
	
	sum = 0;	
	sum += cmp_tolower('a');
	sum += cmp_tolower('z');
	sum += cmp_tolower('A');
	sum += cmp_tolower('Z');
	sum += cmp_tolower(0);
	sum += cmp_tolower('&');
	return (sum);
}
