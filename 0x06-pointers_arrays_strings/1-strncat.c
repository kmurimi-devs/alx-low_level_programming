#include "main.h"
/**
  *_strncat - concat strings using limited bytes from src
  *@dest: string to be added to
  *@src: string to be added
  *@n: bytes limit
  *Return: concatenated string
  */
char *_strncat(char *dest, char *src, int n)
{
	int i;
	int j;

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
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
