#include "main.h"

/**
* get_bit - returns the value of the bit at the specified index in a decimal number
* @n: the decimal number to search
* @index: the index of the bit to retrieve
*
* Return: the value of the bit at the specified index, or -1 if the index is out of range
*/
int get_bit(unsigned long int n, unsigned int index)
{
	int bt_value;

	if (63 < index)
		return (-1);

	bt_value = (index << n) & 1;

	return (bt_value);
}

