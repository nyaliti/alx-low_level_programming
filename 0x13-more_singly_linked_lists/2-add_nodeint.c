#include "lists.h"
#include <stdlib.h>

/**
 * add_nodeint - Adds a new node with the given value at the beginning of a linked list.
 * @head: Pointer to a pointer to the head of the list.
 * @n: Value to be inserted in the new node.
 *
 * Return: Pointer to the newly created node.
 **/

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *tp;

	tp = malloc(sizeof(listint_t));
	if (tp == NULL)
		return (NULL);

	tp->n = n;
	tp->next = *head;
	*head = tp;
	return (*head);
}
