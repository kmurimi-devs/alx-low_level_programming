#include <stdlib.h>

/**
 * argstostr - concatenates strings from a double pointer array
 * @ac: number of strings
 * @av: double pointer array of strings
 *
 * Return: pointer to the concatenated string, or NULL on failure
 */
char *argstostr(int ac, char **av)
{
	int i, j, len = 0, index = 0;
	char *str;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++)
			len++;
	}

	len += ac;
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++)
		{
			str[index] = av[i][j];
			index++;
		}
		str[index] = '\n';
		index++;
	}

	str[index] = '\0';
	return (str);
}
