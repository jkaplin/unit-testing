/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isdigit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 19:07:15 by jkaplin           #+#    #+#             */
/*   Updated: 2019/02/15 12:09:44 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>
#include "../libft.h"

int		cmp_isdigit(int c)
{
	int		your_result;
	int		true_result;

	your_result = ft_isdigit(c);
	true_result = isdigit(c);
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

int		test_isdigit()
{
	int		sum;

	printf("int		ft_isdigit(int c);\n");
	
	sum = 0;	
	sum += cmp_isdigit('a');
	sum += cmp_isdigit('0');
	sum += cmp_isdigit('9');
	sum += cmp_isdigit(0);
	sum += cmp_isdigit('&');
	return (sum);
}
