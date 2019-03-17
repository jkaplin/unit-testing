/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memdel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 08:42:04 by jkaplin           #+#    #+#             */
/*   Updated: 2019/02/21 09:45:15 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../libft.h"

int		cmp_memdel(void **ap)
{
	char	**your_ap;
	char	**true_ap;
	char	*your_result;
	char	*true_result;

	your_ap = (char **)malloc(sizeof(char *));
	true_ap = (char **)malloc(sizeof(char *));
	if (*(char **)ap == NULL)
	{
		*your_ap = NULL;
		*true_ap = NULL;
	}
	else
	{
		*your_ap = strdup(*(char **)ap);
		*true_ap = strdup(*(char **)ap);
	}

	ft_memdel((void **)your_ap);
	your_result = *your_ap;

	if (*true_ap != NULL)
	{
		free(*true_ap);
		*true_ap = NULL;
	}
	true_result = *true_ap;

	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n");
	if (*((char **)ap) == NULL)
		printf("*ap = NULL\n\n");
	else
		printf("*ap = \"%s\"\n\n", *((char **)ap));
	if (your_result == NULL)
		printf("your_result: *ap = NULL\n");
	else
		printf("your_result: *ap = \"%s\"", your_result);
	printf("true_result: *ap = NULL\n");

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

int		test_memdel()
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

	printf("void	ft_memdel(void **ap);\n");

	sum = 0;
	sum += cmp_memdel((void **)str_p1);
	sum += cmp_memdel((void **)str_p2);
	sum += cmp_memdel((void **)str_p3);
	sum += cmp_memdel((void **)str_p4);
	return (sum);
}
