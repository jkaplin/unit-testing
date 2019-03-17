/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isalpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 18:56:46 by jkaplin           #+#    #+#             */
/*   Updated: 2019/02/15 12:11:43 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>
#include "../libft.h"

int		cmp_isalpha(int c)
{
	int		your_result;
	int		true_result;

	your_result = ft_isalpha(c);
	true_result = isalpha(c);
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

int		test_isalpha()
{
	int		sum;

	printf("int		ft_isalpha(int c);\n");
	
	sum = 0;	
	sum += cmp_isalpha('a');
	sum += cmp_isalpha('z');
	sum += cmp_isalpha('A');
	sum += cmp_isalpha('Z');
	sum += cmp_isalpha(0);
	sum += cmp_isalpha('&');
	sum += cmp_isalpha('7');
	return (sum);
}
