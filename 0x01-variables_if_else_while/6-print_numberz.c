#include <stdio.h>
/**
  *main - print single digit numbers
  *Return: 0 always - success
  */
int main(void)
{
	int i;

	for (i = 48; i < 58; i++)
	{
		putchar(i);
	}
	putchar('\n');
	return (0);
}
