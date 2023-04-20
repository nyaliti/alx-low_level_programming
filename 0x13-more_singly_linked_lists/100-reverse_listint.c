#include "lists.h"

/**
 * reverse_listint - reverses a linked list
 * @head: pointer to the first node in the list
 *
 * Return: pointer to the first node in the new list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL;
	listint_t *next = NULL;

	/* Traverse the list using a for loop */
	for (; *head != NULL; *head = next)
	{
		/* Save the next node */
		next = (*head)->next;

		/* Reverse the link */
		(*head)->next = prev;

		/* Move prev and head pointers to next nodes */
		prev = *head;
	}

	/* Set the head to the last node, which is the new first node */
	*head = prev;

	return (*head);
}

