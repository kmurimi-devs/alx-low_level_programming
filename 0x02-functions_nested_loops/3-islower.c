#include "main.h"
/**
  *_islower - check if letter is capital or small letter
  *@c: ascii value of letter
  *Return: 1 if lowercase else return zero
  */
int _islower(int c)
{
	if (c >= 97 && c <= 122)
		return (1);
	else
		return (0);
}
