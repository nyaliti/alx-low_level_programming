#include "main.h"
#include <stdlib.h>

/**
 * set_bit - sets the value of a bit to 1 at a given index
 * @n: pointer to the number
 * @index: index to set the bit
 *
 * Return: 1 on success, -1 on failure
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	/* Check if index is within the size of n in bits */
	if (index > sizeof(n) * 8)
		return (-1);

	/* Set the bit at the given index */
	*n |= (1 << index);

	return (1);
}

