#include "main.h"
#include <stdlib.h>
#include <stdio.h>

#define ERR_MSG "Error"

/**
 * is_digit - checks if a string contains only digits
 * @s: string to be evaluated
 *
 * Return: 1 if all characters are digits, 0 otherwise
 */
int is_digit(char *s)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return 0;
		i++;
	}
	return 1;
}

/**
 * _strlen - returns the length of a string
 * @s: string to evaluate
 *
 * Return: the length of the string
 */
int _strlen(char *s)
{
	int length = 0;

	while (s[length] != '\0')
		length++;

	return length;
}

/**
 * handle_errors - handles errors in the program
 */
void handle_errors(void)
{
	printf("Error\n");
	exit(98);
}

/**
 * main - multiplies two positive numbers
 * @argc: number of command-line arguments
 * @argv: array of command-line arguments
 *
 * Return: always 0 (Success)
 */
int main(int argc, char *argv[])
{
	char *num1, *num2;
	int len1, len2, total_len, i, carry, digit1, digit2, *result, isLeadingZero = 0;

	num1 = argv[1], num2 = argv[2];
	if (argc != 3 || !is_digit(num1) || !is_digit(num2))
		handle_errors();

	len1 = _strlen(num1);
	len2 = _strlen(num2);
	total_len = len1 + len2 + 1;
	result = malloc(sizeof(int) * total_len);
	if (!result)
		return 1;

	for (i = 0; i <= len1 + len2; i++)
		result[i] = 0;

	for (len1 = len1 - 1; len1 >= 0; len1--)
	{
		digit1 = num1[len1] - '0';
		carry = 0;

		for (len2 = _strlen(num2) - 1; len2 >= 0; len2--)
		{
			digit2 = num2[len2] - '0';
			carry += result[len1 + len2 + 1] + (digit1 * digit2);
			result[len1 + len2 + 1] = carry % 10;
			carry /= 10;
		}

		if (carry > 0)
			result[len1 + len2 + 1] += carry;
	}

	for (i = 0; i < total_len - 1; i++)
	{
		if (result[i])
			isLeadingZero = 1;

		if (isLeadingZero)
			_putchar(result[i] + '0');
	}

	if (!isLeadingZero)
		_putchar('0');

	_putchar('\n');
	free(result);
	return 0;
}
