/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_toupper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 19:29:11 by jkaplin           #+#    #+#             */
/*   Updated: 2019/02/15 12:13:23 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>
#include "../libft.h"

int		cmp_toupper(int c)
{
	int		your_result;
	int		true_result;

	your_result = ft_toupper(c);
	true_result = toupper(c);
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

int		test_toupper()
{
	int		sum;

	printf("int		ft_toupper(int c);\n");
	
	sum = 0;	
	sum += cmp_toupper('a');
	sum += cmp_toupper('z');
	sum += cmp_toupper('A');
	sum += cmp_toupper('Z');
	sum += cmp_toupper(0);
	sum += cmp_toupper('&');
	return (sum);
}
