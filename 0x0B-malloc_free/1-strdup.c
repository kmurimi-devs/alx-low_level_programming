#include <stdlib.h>
#include <stdio.h>
/**
 * _strdup - copy a string and save it in a new location
 * @str: string to be copied
 * Return: pointer to copu or Null
 */
char *_strdup(char *str)
{
	char *copied;
	int i = 0;
	int j = 0;

	if (str == NULL)
		return (NULL);
	while (str[i] != '\0')
		i++;
	copied = malloc(sizeof(char) * (i + 1));
	if (copied == NULL)
		return (NULL);
	for (; str[j]; j++)
		copied[j] = str[j];
	return (copied);
}
