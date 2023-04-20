#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list
 * @head: linked list to search for
 *
 * Return: address of the node where the loop starts, or NULL
 */
listint_t *find_listint_loop(listint_t *head)
{
	/* Initialize slow and fast pointers to head of the list */
	listint_t *slow = head;
	listint_t *fast = head;

	/* If the list is empty, return NULL */
	if (!head)
		return (NULL);

	/* Traverse the list with the fast and slow pointers */
	for (; slow && fast && fast->next;)
	{
		fast = fast->next->next;
		slow = slow->next;
		/* If the pointers meet, there is a loop in the list */
		if (fast == slow)
		{
			/* Reset slow pointer to the head of the list */
			slow = head;
			/* Traverse the list with slow and fast pointers */
			for (; slow != fast;)
			{
				slow = slow->next;
				fast = fast->next;
			}
			return (fast);
		}
	}

	/* No loop in the list */
	return (NULL);
}

