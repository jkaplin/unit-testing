/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 15:53:48 by jkaplin           #+#    #+#             */
/*   Updated: 2019/03/07 14:24:55 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

#define FN_AMOUNT 44

int		main(int argc, char **argv)
{
	t_fn	fn[FN_AMOUNT];
	int		(*ptr_fn)();
	int		sum;
	int		i;
	int		j;

	fn[0].str = "memset";
	fn[0].fn = test_memset;
	fn[1].str = "bzero";
	fn[1].fn = test_bzero;
	fn[2].str = "memcpy";
	fn[2].fn = test_memcpy;
	fn[3].str = "memccpy";
	fn[3].fn = test_memccpy;
	fn[4].str = "memmove";
	fn[4].fn = test_memmove;
	fn[5].str = "memchr";
	fn[5].fn = test_memchr;
	fn[6].str = "memcmp";
	fn[6].fn = test_memcmp;
	fn[7].str = "strlen";
	fn[7].fn = test_strlen;
	fn[8].str = "strdup";
	fn[8].fn = test_strdup;
	fn[9].str = "strcpy";
	fn[9].fn = test_strcpy;
	fn[10].str = "strncpy";
	fn[10].fn = test_strncpy;
	fn[11].str = "strcat";
	fn[11].fn = test_strcat;
	fn[12].str = "strncat";
	fn[12].fn = test_strncat;
	fn[13].str = "strlcat";
	fn[13].fn = test_strlcat;
	fn[14].str = "strchr";
	fn[14].fn = test_strchr;
	fn[15].str = "strrchr";
	fn[15].fn = test_strrchr;
	fn[16].str = "strstr";
	fn[16].fn = test_strstr;
	fn[17].str = "strnstr";
	fn[17].fn = test_strnstr;
	fn[18].str = "strcmp";
	fn[18].fn = test_strcmp;
	fn[19].str = "strncmp";
	fn[19].fn = test_strncmp;
	fn[20].str = "atoi";
	fn[20].fn = test_atoi;
	fn[21].str = "isalpha";
	fn[21].fn = test_isalpha;
	fn[22].str = "isdigit";
	fn[22].fn = test_isdigit;
	fn[23].str = "isalnum";
	fn[23].fn = test_isalnum;
	fn[24].str = "isascii";
	fn[24].fn = test_isascii;
	fn[25].str = "isprint";
	fn[25].fn = test_isprint;
	fn[26].str = "toupper";
	fn[26].fn = test_toupper;
	fn[27].str = "tolower";
	fn[27].fn = test_tolower;



	fn[28].str = "memalloc";
	fn[28].fn = test_memalloc;
	fn[29].str = "memdel";
	fn[29].fn = test_memdel;
	fn[30].str = "strnew";
	fn[30].fn = test_strnew;
	fn[31].str = "strdel";
	fn[31].fn = test_strdel;
	fn[32].str = "strclr";
	fn[32].fn = test_strclr;
	fn[33].str = "striter";
	fn[33].fn = test_striter;
	fn[34].str = "striteri";
	fn[34].fn = test_striteri;
	fn[35].str = "strmap";
	fn[35].fn = test_strmap;
	fn[36].str = "strmapi";
	fn[36].fn = test_strmapi;
	fn[37].str = "strequ";
	fn[37].fn = test_strequ;
	fn[38].str = "strnequ";
	fn[38].fn = test_strnequ;
	fn[39].str = "strsub";
	fn[39].fn = test_strsub;
	fn[40].str = "strjoin";
	fn[40].fn = test_strjoin;
	fn[41].str = "strtrim";
	fn[41].fn = test_strtrim;
	fn[42].str = "strsplit";
	fn[42].fn = test_strsplit;
	fn[43].str = "itoa";
	fn[43].fn = test_itoa;
/*
	fn[44].str = "putchar";
	fn[44].fn = test_putchar;
	fn[45].str = "putstr";
	fn[45].fn = test_putstr;
	fn[46].str = "putendl";
	fn[46].fn = test_putendl;
	fn[47].str = "putnbr";
	fn[47].fn = test_putnbr;
	fn[48].str = "putchar_fd";
	fn[48].fn = test_putchar_fd;
	fn[49].str = "putstr_fd";
	fn[49].fn = test_putstr_fd;
	fn[50].str = "putendl_fd";
	fn[50].fn = test_putendl_fd;
	fn[51].str = "putnbr_fd";
	fn[51].fn = test_putnbr_fd;



	fn[52].str = "lstnew";
	fn[52].fn = test_lstnew;
	fn[53].str = "lstdelone";
	fn[53].fn = test_lstdelone;
	fn[0].str = "lstdel";
	fn[0].fn = test_lstdel;
	fn[55].str = "lstadd";
	fn[55].fn = test_lstadd;
	fn[56].str = "lstiter";
	fn[56].fn = test_lstiter;
	fn[57].str = "lstmap";
	fn[57].fn = test_lstmap;
*/
	i = 1;
	while (i < argc)
	{
		ptr_fn = NULL;
		j = 0;
		while (j < FN_AMOUNT)
		{
			if (fn[j].str != NULL && argv[i] != NULL && strcmp(fn[j].str, argv[i]) == 0)
			{
				ptr_fn = fn[j].fn;
				break;
			}
			j++;
		}
		if (ptr_fn == NULL)
		{
			printf("NO SUCH FUNCTION AS %s\n", argv[i]);
			return (1);
		}
		sum = ptr_fn();
		if (sum == 0)
			printf("- > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > \e[1;4;32m PERFECT \e[0m\n");
		else
			printf("- > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > \e[1;4;31m IMPROVE \e[0m \e[1;31m : fix %d tests \e[0m\n", sum);
		i++;
	}
	if (argc == 1)
	{
		j = 0;
		while(j < FN_AMOUNT)
		{
			ptr_fn = fn[j].fn;
			sum = ptr_fn();
			if (sum == 0)
			printf("- > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > \e[1;4;32m PERFECT \e[0m\n");
			else
			printf("- > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > \e[1;4;31m IMPROVE \e[0m \e[1;31m : fix %d tests \e[0m\n", sum);
			j++;
		}
	}
	return (0);
}
