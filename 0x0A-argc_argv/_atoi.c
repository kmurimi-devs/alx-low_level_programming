#include <stdio.h>
#include "main.h"
/**
  * _atoi - convert string to integer
  *@str: string to be converted
  * Return: the int converted from string
  */
int _atoi(char *str)
{
	int number = 0;
	int sign = 1;
	int i = 0;

	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}

	for (; str[i] != '\0'; ++i)
		number = number * 10 + str[i] - '0';

	return (sign * number);
}
