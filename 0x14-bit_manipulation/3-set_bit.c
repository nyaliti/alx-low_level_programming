#include "main.h"

/**
* get_bit - returns the value of the bit at the specified index in a decimal number
* @n: the decimal number to search
* @index: the index of the bit to retrieve
*
* Return: the value of the bit at the specified index, or -1 if the index is out of range
*/
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
		return (-1);

	unsigned long int mask = 1UL << index;
	*n |= mask;

	return (1);
}
