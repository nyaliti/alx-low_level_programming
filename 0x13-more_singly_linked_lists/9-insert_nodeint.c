#include "lists.h"
#include <stdlib.h>

/**
 * insert_nodeint_at_index - Insert a new node at a given position.
 * @head: First node address.
 * @idx: Position of the new node to be inserted in.
 * @n: Data of the new node.
 * Return: Address of the new node.
 **/
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	/* Declare variables */
	listint_t *new_node, *temp;
	unsigned int i = 0;

	/* If the list is empty and the index is not 0, return NULL */
	if (*head == NULL && idx != 0)
		return (NULL);

	/* Traverse the list until the desired index is reached */
	if (idx != 0)
	{
		temp = *head;
		while (i < idx - 1 && temp != NULL)
		{
			temp = temp->next;
			i++;
		}
		if (temp == NULL)
			return (NULL);
	}

	/* Create the new node */
	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = n;

	/* If inserting at the beginning of the list, update head */
	if (idx == 0)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}

	/* Insert the new node at the desired index */
	new_node->next = temp->next;
	temp->next = new_node;

	/* Return the new node address */
	return (new_node);
}

