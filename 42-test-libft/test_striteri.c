/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_striteri.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 15:55:20 by jkaplin           #+#    #+#             */
/*   Updated: 2019/03/07 14:22:35 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../libft.h"

int		cmp_striteri(char *s, void (*f)(unsigned int, char *))
{
	char			*your_s;
	char			*true_s;
	char			*your_result;
	char			*true_result;
	unsigned int	i;
	unsigned int	len;

	len = strlen(s);

	your_s = strdup(s);
	true_s = strdup(s);
	ft_striteri(your_s, f);
	your_result = your_s;

	i = 0;
	while (i < len)
	{
		f(i, &true_s[i]);
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

static void	f_i(unsigned int i, char *c_ptr)
{
	*c_ptr = '0' + i;
}

static void	f_plus_i(unsigned int i, char *c_ptr)
{
	*c_ptr += i;
}

static void	f_capitalize_sometimes(unsigned int i, char *c_ptr)
{
	if (*c_ptr >= 'a' && *c_ptr <= 'z' && (i % 3 == 0))
		*c_ptr = *c_ptr - 'a' + 'A';
}

static void	f_nul_bomb(unsigned int i, char *c_ptr)
{
	if (i == 2)
		c_ptr[1] = '\0';
}

int		test_striteri()
{
	int		sum;

	printf("void	ft_striteri(char *s, void (*f)(unsigned int, char *));\n");

	sum = 0;
	sum += cmp_striteri("testing", f_i);
	sum += cmp_striteri("testing", f_plus_i);
	sum += cmp_striteri("testing a bit more", f_capitalize_sometimes);
	sum += cmp_striteri("testing", f_nul_bomb);
	sum += cmp_striteri("", f_i);

	return (sum);
}
