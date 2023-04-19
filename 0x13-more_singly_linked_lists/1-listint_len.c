#include "lists.h"

/**
 * listint_len - Calculate the number of elements in a linked list.
 * @h: Pointer to the head of the list.
 * Return: Number of elements in the list.
 **/

size_t listint_len(const listint_t *h)
{
	const listint_t *tp;
	unsigned int cnr = 0;

	for (tp = h; tp != NULL; tp = tp->next)
{
    cnr++; // increment cnr for each node
}

	return (cnr);
}
