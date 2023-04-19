#include "lists.h"
#include <stdlib.h>

/**
 * pop_listint - Removes the first element of a singly linked list.
 * @head: Pointer to the list.
 * Return: Integer value of the removed element.
 **/

int pop_listint(listint_t **head)
{
	listint_t *tp;
	int my_deta;

	if (*head == NULL)
		return (0);

	tp = *head;
	*head = tp->next;
	my_deta = tp->n;
	free(tp);
	return (my_deta);
}
