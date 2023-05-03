#include "lists.h"

/**
 * sum_listint - calculates the sum of all the data in a listint_t list
 * @head: first node in the linked list
 *
 * Return: resulting sum
 */
int sum_listint(listint_t *head)
{
	listint_t *str = head;
	int total = 0;

	while (str)
	{
		total += str->n;
		str = str->next;
	}

	return (total);
}
