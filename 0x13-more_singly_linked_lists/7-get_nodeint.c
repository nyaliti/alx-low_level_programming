#include "lists.h"
#include <stdlib.h>

/**
 * get_nodeint_at_index - Find a node in a list.
 * @head: Address of the first node in a list.
 * @index: Position of the node to find (starting from 0).
 * Return: Node address.
 **/
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	/* Initialize a counter variable */
	unsigned int i = 0;

	/* If the head of the list is NULL, return NULL */
	if (head == NULL)
		return (NULL);

	/* Traverse the list until the desired index is reached */
	while (i < index)
	{
		head = head->next;
		if (head == NULL)
			return (NULL);
		i++;
	}

	/* Return the node at the desired index */
	return (head);
}

