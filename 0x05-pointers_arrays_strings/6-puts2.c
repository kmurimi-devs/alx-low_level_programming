#include "main.h"
/**
  * puts2 - print one character of two from the first one
  * @str: input string
  * Return: print
  */
void puts2(char *str)
{
	int len = 0;
	int i = 0;
	char *x = str;
	int y;

	while (*x != '\0')
	{
		x++;
		len++;
	}
	i = len - 1;
	for (y = 0; y <= i; y++)
	{
		if (y % 2 == 0)
		{
			_putchar(str[y]);
		}
	}
	_putchar('\n');
}
