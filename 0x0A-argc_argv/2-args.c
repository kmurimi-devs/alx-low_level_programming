#include <stdio.h>
/**
  * main - print all received arguments
  * @argc: number of arguments
  * @argv: array of arguements
  * Return: 0 always - success
  */
int main(int argc, char *argv[])
{
	int n;

	for (n = 0; n < argc; n++)
	{
		printf("%s\n", argv[n]);
	}
	return (0);
}
