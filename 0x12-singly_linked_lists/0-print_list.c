#include <stdio.h>
#include "list.h"

/**
 * print_list - print the elements of a linked list
 * @h: pointer to the list
 *
 * Return: number of nodes
 */
size_t print_list(const list_t *h)
{
	size_t s = 0;

	while (h)
	{
		if (!h->str)
			printf("[0] (nil)\n");
		else
			printf("[%u] %s\n", h->len, h->str);
		h = h->next;
		s++;
	}
	return (s);
}
