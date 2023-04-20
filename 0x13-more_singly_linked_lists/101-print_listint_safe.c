#include "lists.h"

/**
 * print_listint_safe - prints a linked list, safely
 * @head: list of type listint_t to print
 *
 * Return: number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
    size_t num = 0;
    long int diff;

    for (; head; head = head->next, num++) {
        diff = head - head->next; // Calculate the difference between the current node and the next node.
        printf("[%p] %d\n", (void *)head, head->n); // Print the current node's address and data.
        if (diff > 0)
            continue; // If the difference is greater than zero, continue iterating through the list.
        else {
            printf("-> [%p] %d\n", (void *)head->next, head->next->n); // Otherwise, print the next node's address and data.
            break; // Stop iterating through the list.
        }
    }

    return (num);
}

