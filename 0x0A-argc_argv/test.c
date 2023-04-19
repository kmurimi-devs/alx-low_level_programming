#include <stdio.h>
#include "main.h"

/**
  *main - convert strings into nums
  *return: 0
  */
int main(void)
{
	char str1[] = "87645";
	char str2[] = "-34567";

	int val1 = _atoi(str1);
	int val2 = _atoi(str2);

	printf("%d, val1 & val2 is %d", val1, val2);
	return (0);
}
