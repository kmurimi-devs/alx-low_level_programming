#include "main.h"
/**
 * _strncat - concat two strings
 * use limited mem size
 * @dest: where to concat
 * @src: string to be added
 * @n: data size in bytes
 *
 * Return: dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int i;
	int j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (j < n && src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
