<<<<<<< HEAD

void	ft_putstr(char const *s);
int main()
{
	ft_putstr("test\n");
=======
#include <stdio.h>
#include "file.c"
int		main(int argc, char **argv)
{
	int		fd;
	type	result;

	result = my_min_function(4, 3);
	if (result == expected)
		printf("SUCCESS");
	else
		printf("FAILURE");
>>>>>>> 31105447c83766163a13b28e2f15c43b07f7e28c
	return (0);
}
