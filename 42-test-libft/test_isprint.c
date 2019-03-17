/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isprint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 19:25:09 by jkaplin           #+#    #+#             */
/*   Updated: 2019/02/15 12:11:58 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>
#include "../libft.h"

int		cmp_isprint(int c)
{
	int		your_result;
	int		true_result;

	your_result = ft_isprint(c);
	true_result = isprint(c);
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n");
	printf("c = '%c'\n\n", c);
	printf("your_result: %d\n", your_result);
	printf("true_result: %d\n", true_result);
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

int		test_isprint()
{
	int		sum;

	printf("int		ft_isprint(int c);\n");
	
	sum = 0;	
	sum += cmp_isprint(40);
	sum += cmp_isprint(126);
	sum += cmp_isprint(30);
	sum += cmp_isprint(32);
	sum += cmp_isprint(39);
	sum += cmp_isprint(127);
	sum += cmp_isprint(0);
	sum += cmp_isprint(-1);
	sum += cmp_isprint(500);
	return (sum);
}
