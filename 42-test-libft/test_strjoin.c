/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 07:21:08 by jkaplin           #+#    #+#             */
/*   Updated: 2019/02/22 07:24:42 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft.h"

int		cmp_strjoin(char const *s1, char const *s2)
{
	char	*your_result;
	char	*true_result;

	char	*str;
	int		i;
	int		j;

	str = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	true_result = str;

	your_result = ft_strjoin(s1, s2);

	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n");
	printf("s1 = \"%s\" | s2 = \"%s\"\n\n", s1, s2);
	printf("your_result: \"%s\"\n", your_result);
	printf("true_result: \"%s\"\n", true_result);
	if ((your_result == NULL && true_result == NULL) || strcmp(your_result, true_result) == 0)
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

int		test_strjoin()
{
	int		sum;

	printf("char	*ft_strjoin(char const *s1, char const *s2);\n");

	sum = 0;
	sum += cmp_strjoin("testing", "game");
	sum += cmp_strjoin("", "test");
	sum += cmp_strjoin("test", "");
	sum += cmp_strjoin("", "");
	return (sum);
}
