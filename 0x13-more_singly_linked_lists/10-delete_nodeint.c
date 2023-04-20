#include "lists.h"
#include <stdlib.h>

/**
 * delete_nodeint_at_index - Delete a node at a given position.
 * @head: First node address.
 * @index: Position of the node to delete.
 * Return: If success (1).
 **/

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int x = 0; // Renamed i to x
	listint_t *current, *next;

	/* Check if the list or the head of the list is empty */
	if (head == NULL || *head == NULL)
		return (-1);

	/* Check if the node to be deleted is the head node */
	if (index == 0)
	{
		next = (*head)->next;
		free(*head);
		*head = next;
		return (1);
	}

	/* Traverse the list until the node before the desired node is reached */
	current = *head;
	while (x < index - 1)
	{
		if (current->next == NULL)
			return (-1);
		current = current->next;
		x++;
	}

	/* Delete the desired node */
	next = current->next;
	current->next = next->next;
	free(next);
	return (1);
}

