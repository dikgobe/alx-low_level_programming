#include "lists.h"
#include<stdio.h>

/**
 * add_nodeint :adds a new node at the beginning of a listint_t list.
 *
 * @head : Head pointer of double pointer
 * @n : integer to add the list
 * Return : the address of a new element and Null if it failed
 *
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *pointer;

	if (head == NULL)
		return (NULL);
	pointer = malloc(sizeof(listint_t));
	if (pointer == NULL)
		return(NULL);
	pointer = n;
	pointer->next = *head
	* head = pointer;
	return (pointer);
}
