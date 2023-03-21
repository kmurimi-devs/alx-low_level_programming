#include "main.h"
/**
  *_abs - give the absolute value
  *@a: number to be checked
  *Return: absolute value
  */
int _abs(int a)
{
	if (a < 0)
		a = -(a);
	else if (a > 0)
		a = a;
	return (a);
}
