#include "lists.h"

/**
 * free_listint_safe - frees a linked list
 * @h: pointer to the first node in the linked list
 *
 * Return: number of elements in the freed list
 */
size_t free_listint_safe(listint_t **h)
{
	int num;
	size_t length = 0;
	listint_t *str;

	if (!h || !*h)
		return (0);

	while (*h)
	{
		num = *h - (*h)->next;
		if (num > 0)
		{
			str = (*h)->next;
			free(*h);
			*h = str;
			length++;
		}
		else
		{
			free(*h);
			*h = NULL;
			length++;
			break;
		}
	}

	*h = NULL;

	return (length);
}
