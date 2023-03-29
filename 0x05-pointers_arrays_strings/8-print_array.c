#include "main.h"
/**
  *print_array - prints n elements of array
  * @a: array name
  *@n: number of elements to print
  * Return: a of n inputs
  */
void print_array(int *a, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("%d, ", a[i]);
	}
	if (i == (n - 1))
	{
		printf("%d, ", a[n - 1]);
	}
	printf("\n");
}
