#include <stdio.h>

/**
 * get_endianness - Determines the endianness of the system.
 *
 * Return: 1 for little endian, 0 for big endian.
 */
int get_endianness(void)
{
	unsigned int num = 1;
	char *ptr = (char *)&num;

	if (*ptr)
		return (1);
	else
		return (0);
}

