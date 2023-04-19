#include <stdio.h>
/**
  *main - print the number of args passed
  *@argc: count of arguements passed to function
  *@argv: arguements passed to a function as an array
  *Return: 0 if successful
  */
int main(int argc, char *argv[])
{
	(void) argv;
	printf("%d\n", argc - 1);
	return (0);
}
