#include "main.h"

/**
 * print_binary - prints the binary representation of a number
 * @n: parameter
 */
void print_binary(unsigned long int n)
{
	int i, count = 0;
	unsigned long int current;

	/* iterate through each bit of the number starting from the most significant bit */
	for (i = 63; i >= 0; i--)
	{
		/* shift the number to the right by i bits and get the current bit */
		current = n >> i;

		/* if the current bit is 1, print 1 and increment the count of 1s */
		if (current & 1)
		{
			_putchar('1');
			count++;
		}
		/* if the current bit is 0 and there have been 1s already, print 0 */
		else if (count)
			_putchar('0');
	}

	/* if there were no 1s in the number, print a single 0 */
	if (!count)
		_putchar('0');
}

