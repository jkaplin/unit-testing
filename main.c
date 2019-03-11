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
	return (0);
}
