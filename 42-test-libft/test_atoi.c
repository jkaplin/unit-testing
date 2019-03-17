/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 18:38:13 by jkaplin           #+#    #+#             */
/*   Updated: 2019/03/02 12:37:07 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../libft.h"

int		cmp_atoi(const char *str)
{
	int		your_result;
	int		true_result;

	your_result = ft_atoi(str);
	true_result = atoi(str);
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n");
	printf("str = \"%s\"\n\n", str);
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

int		test_atoi()
{
	int		sum;

	printf("int		ft_atoi(const char *str);\n");

	sum = 0;
	sum += cmp_atoi("testing");
	sum += cmp_atoi("123");
	sum += cmp_atoi("   -0456");
	sum += cmp_atoi("  + 789");
	sum += cmp_atoi("915\t423");
	sum += cmp_atoi("+-234");
	sum += cmp_atoi("2147483647");
	sum += cmp_atoi("-2147483648");
	sum += cmp_atoi("-2147483649");
	sum += cmp_atoi("2147483648");
	return (sum);
}
