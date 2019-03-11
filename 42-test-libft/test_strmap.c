/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 16:48:58 by jkaplin           #+#    #+#             */
/*   Updated: 2019/02/21 19:47:35 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../libft.h"

int		cmp_strmap(char const *s, char (*f)(char))
{
	char	*your_s;
	char	*true_s;
	char	*your_result;
	char	*true_result;
	int		i;

	your_s = strdup(s);
	true_s = strdup(s);
	your_result = ft_strmap(your_s, f);

	i = 0;
	while (true_s[i])
	{
		true_s[i] = f(true_s[i]);
		i++;
	}
	true_s[i] = '\0';
	true_result = true_s;

	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n");

	printf("s = \"%s\"\n\n", s);

	printf("your_result: \"%s\"\n", your_result);
	printf("true_result: \"%s\"\n", true_result);

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

char	f_42(char c)
{
	if (c)
		return (42);
	return (0);
}

char	f_plus_1(char c)
{
	return (c + 1);
}

char	f_capitalize(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 'a' + 'A');
	return (c);
}

char	f_nul_bomb(char c)
{
	if (c == 's')
		return (0);
	return (c);
}

int		test_strmap()
{
	int		sum;

	printf("char	*ft_strmap(char const *s, char (*f)(char));\n");

	sum = 0;
	sum += cmp_strmap("test", f_42);
	sum += cmp_strmap("test", f_plus_1);
	sum += cmp_strmap("test", f_capitalize);
	sum += cmp_strmap("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ", f_nul_bomb);
	sum += cmp_strmap("", f_42);

	return (sum);
}
