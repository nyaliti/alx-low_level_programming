#include "lists.h"
#include <stdlib.h>

/**
 * free_listint - Frees a list.
 * @head: Address of the first node of a list.
 **/

void free_listint(listint_t *head)
{
    listint_t *tp, *tp2;
    
    for (tp = head; tp != NULL; tp = tp2)
    {
        tp2 = tp->next;
        free(tp);
    }
}

