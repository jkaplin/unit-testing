/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strmapi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 19:49:05 by jkaplin           #+#    #+#             */
/*   Updated: 2019/03/07 14:21:20 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../libft.h"

int		cmp_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*your_s;
	char	*true_s;
	char	*your_result;
	char	*true_result;
	int		i;

	your_s = strdup(s);
	true_s = strdup(s);
	your_result = ft_strmapi(your_s, f);

	i = 0;
	while (true_s[i])
	{
		true_s[i] = f(i, true_s[i]);
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

static char	f_i(unsigned int i, char c)
{
	if (c)
		return ('a' + i);
	return (c);
}

static char	f_plus_i(unsigned int i, char c)
{
	return (c + i);
}

static char	f_capitalize_i(unsigned int i, char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 'a' + 'A' + i);
	return (c);
}

static char	f_nul_bomb(unsigned int i, char c)
{
	if ((unsigned char)c == 'a' + i)
		return (0);
	return (c);
}

int		test_strmapi()
{
	int		sum;

	printf("char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));\n");

	sum = 0;
	sum += cmp_strmapi("test", f_i);
	sum += cmp_strmapi("test", f_plus_i);
	sum += cmp_strmapi("test", f_capitalize_i);
	sum += cmp_strmapi("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ", f_nul_bomb);
	sum += cmp_strmapi("", f_i);

	return (sum);
}
