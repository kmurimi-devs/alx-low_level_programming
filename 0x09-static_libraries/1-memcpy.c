#include "main.h"
/**
 * _memcpy - a function that copies memory area
 * @dest: where mem is stored
 * @src: where mem is copied
 * @n: number of bytes
 *
 * Return: copied memory
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	int r = 0;
	int i = n;

	for (; r < i; r++)
	{
		dest[r] = src[r];
		n--;
	}
	return (dest);
}
