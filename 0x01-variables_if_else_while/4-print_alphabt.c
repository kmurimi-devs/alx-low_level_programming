#include <stdio.h>
/**
  * main - print lowercase alphabet excluding 'e' and 'q'
  * Return: zero
  */
int main(void)
{
	char ch = 'a';

	while (ch <= 'z')
	{
		if (ch != 'e' && ch != 'q')
			putchar(ch);
		ch++;
	}
	putchar('\n');
	return (0);
}
