#include "main.h"

/**
  *_isalpha - checks if input is alphabet
  *@c: ascii value of character
  *Return: 1 if alphabet and zero if not alphabet
  */
int _isalpha(int c)
{
	if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
		return (1);
	else
		return (0);
}
