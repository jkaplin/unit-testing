#include <stdio.h>

int myFunction(int num) 
{ 
	if (num == 0) 

		// if number is 0, do not perform any operation. 
		return 0; 
	else
		// if number is power of 2, return number else return 0 
		
	if ((num & (num - 1)) == 0)
	{
		printf("POWER OF 2 (:\n");
		return (num);
	}
	else
	{
		printf("not a POWER OF 2 ):\n");
		return 0;
	}
} 
