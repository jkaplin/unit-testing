/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_striter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 11:31:48 by jkaplin           #+#    #+#             */
/*   Updated: 2019/03/07 14:20:37 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../libft.h"

int		cmp_striter(char *s, void (*f)(char *))
{
	char	*your_s;
	char	*true_s;
	char	*your_result;
	char	*true_result;
	int		i;
	int		len;

	len = strlen(s);

	your_s = strdup(s);
	true_s = strdup(s);
	ft_striter(your_s, f);
	your_result = your_s;

	i = 0;
	while (i < len)
	{
		f(&true_s[i]);
		i++;
	}
	true_result = true_s;

	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n");

	printf("s = \"%s\"\n\n", s);
	printf("your_result: s = [");
	i = 0;
	while (i < len)
	{
		if (i == len - 1)
			printf("%c", your_result[i]);
		else
			printf("%c, ", your_result[i]);
		i++;
	}
	printf("]\n");
	printf("true_result: s = [");
	i = 0;
	while (i < len)
	{
		if (i == len - 1)
			printf("%c", true_result[i]);
		else
			printf("%c, ", true_result[i]);
		i++;
	}
	printf("]\n");

	if ((your_result == NULL && true_result == NULL) || (strcmp(your_result, true_result) == 0))
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

static void	f_42(char *c_ptr)
{
	*c_ptr = 42;
}

static void	f_plus_1(char *c_ptr)
{
	*c_ptr = *c_ptr + 1;
}

static void	f_capitalize(char *c_ptr)
{
	if (*c_ptr >= 'a' && *c_ptr <= 'z')
		*c_ptr = *c_ptr - 'a' + 'A';
}

static void	f_nul_bomb(char *c_ptr)
{
		*(c_ptr + 1) = *c_ptr - 'a';
}

int		test_striter()
{
	int		sum;

	printf("void	ft_striter(char *s, void (*f)(char *));\n");

	sum = 0;
	sum += cmp_striter("test", f_42);
	sum += cmp_striter("test", f_plus_1);
	sum += cmp_striter("test", f_capitalize);
	sum += cmp_striter("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ", f_nul_bomb);
	sum += cmp_striter("", f_42);

	return (sum);
}
