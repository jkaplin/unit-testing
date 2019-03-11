/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strdel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 10:06:41 by jkaplin           #+#    #+#             */
/*   Updated: 2019/02/21 10:12:22 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../libft.h"

int		cmp_strdel(char **as)
{
	char	**your_as;
	char	**true_as;
	char	*your_result;
	char	*true_result;

	your_as = (char **)malloc(sizeof(char *));
	true_as = (char **)malloc(sizeof(char *));
	if (*as == NULL)
	{
		*your_as = NULL;
		*true_as = NULL;
	}
	else
	{
		*your_as = strdup(*as);
		*true_as = strdup(*as);
	}

	ft_strdel(your_as);
	your_result = *your_as;

	if (*true_as != NULL)
	{
		free(*true_as);
		*true_as = NULL;
	}
	true_result = *true_as;

	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n");
	if (*as == NULL)
		printf("*as = NULL\n\n");
	else
		printf("*as = \"%s\"\n\n", *as);
	if (your_result == NULL)
		printf("your_result: *as = NULL\n");
	else
		printf("your_result: *as = \"%s\"", your_result);
	printf("true_result: *as = NULL\n");

	if (your_result == NULL && true_result == NULL)
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

int		test_strdel()
{
	int		sum;
	char	**str_p1;
	char	**str_p2;
	char	**str_p3;
	char	**str_p4;

	str_p1 = (char **)malloc(sizeof(char *));
	str_p2 = (char **)malloc(sizeof(char *));
	str_p3 = (char **)malloc(sizeof(char *));
	str_p4 = (char **)malloc(sizeof(char *));
	*str_p1 = strdup("test");
	*str_p2 = strdup("testing");
	*str_p3 = strdup("");
	*str_p4 = NULL;

	printf("void	ft_strdel(char **as);\n");

	sum = 0;
	sum += cmp_strdel(str_p1);
	sum += cmp_strdel(str_p2);
	sum += cmp_strdel(str_p3);
	sum += cmp_strdel(str_p4);
	return (sum);
}
