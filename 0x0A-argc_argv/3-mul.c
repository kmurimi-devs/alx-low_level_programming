#include <stdio.h>
#include "main.h"
/**
  *main - print the product of two numerical arguments
  *@argc: number of arguements passed
  *@argv: array of arguements passed
  *Return: (0) if success, (1) if failed
  */
int main(int argc, char *argv[])
{
	int result, n1, n2;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}
	n1 = _atoi(argv[1]);
	n2 = _atoi(argv[2]);
	result = n1 * n2;

	printf("%d\n", result);
	return (0);
}
