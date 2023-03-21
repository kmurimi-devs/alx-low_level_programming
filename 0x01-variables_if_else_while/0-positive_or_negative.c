#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
  *main - takes number and checks whether it is positve or negative
  *Return: (0) uses printf to output
  */
int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	/* your code goes there */
	if (n > 0)
		printf("%d is positive\n", n);
	else
		printf("%d is negative\n", n);

	return (0);
}
