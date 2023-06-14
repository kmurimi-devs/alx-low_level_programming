#include <stdlib.h>
/**
 * create_array - create array of assigned size
 * @size: size of array
 * @c: char to initialize array
 * Return: pointer to array or NULL
 */
char *create_array(unsigned int size, char c)
{
	char *arr;
	unsigned int i;

	arr = malloc(sizeof(char) * size);
	if (size == 0 || arr == NULL)
		return (NULL);
	for (u = 0; i < size; i++)
		arr[i] = c;
	return (arr);
}

