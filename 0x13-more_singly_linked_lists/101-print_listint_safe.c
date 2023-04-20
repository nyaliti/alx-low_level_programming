#include "lists.h"

/**
 * print_listint_safe - prints a linked list, safely
 * @head: list of type listint_t to print
 *
 * Return: number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t number = 0;
	long int difference;

	for (; head != NULL; number++)
	{
		difference = head - head->next;  // get the difference between the current node address and the next node address
		printf("[%p] %d\n", (void *)head, head->n); // print the current node's address and value
		if (difference > 0)  // if the difference is positive, move to the next node
			head = head->next;
		else  // if the difference is not positive, it means we have encountered a loop in the list
		{
			printf("-> [%p] %d\n", (void *)head->next, head->next->n);  // print the address and value of the node where the loop was detected
			break;
		}
	}

	return (number);  // return the number of nodes in the list
}

