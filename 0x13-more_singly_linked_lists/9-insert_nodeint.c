#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node in a linked list,
 * at a given position
 * @head: pointer to the first node in the list
 * @idx: index where the new node is added
 * @n: data to insert in the new node
 *
 * Return: pointer to the new node, or NULL
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int index;
	listint_t *str = *head;
	listint_t *ptr;

	ptr = malloc(sizeof(listint_t));
	if (!ptr || !head)
		return (NULL);

	ptr->n = n;
	ptr->next = NULL;

	if (idx == 0)
	{
		ptr->next = *head;
		*head = ptr;
		return (ptr);
	}

	for (index = 0; str && index < idx; index++)
	{
		if (index == idx - 1)
		{
			ptr->next = str->next;
			str->next = ptr;
			return (ptr);
		}
		else
			str = str->next;
	}

	return (NULL);
}