#include "lists.h"
#include <stdlib.h>

/**
 * sum_listint - Sum all of the data (n) in a list.
 * @head: Address of the first node of the list.
 * Return: Integer.
 **/
int sum_listint(listint_t *head)
{
	/* Initialize the aggregate variable */
	int aggregate = 0;

	/* Traverse the list and add each node's value to the aggregate */
	for (; head != NULL; head = head->next)
		aggregate += head->n;

	/* Return the final aggregate value */
	return (aggregate);
}

