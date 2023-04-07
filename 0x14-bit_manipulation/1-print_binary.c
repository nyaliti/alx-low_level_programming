#include "main.h"

/**
*print_binary - prints the binary representation of a number
*@n: number to be printed
*
*Return: void
*/

void display_binary(unsigned long int z)
{
if (z > 1)
	display_binary(z >> 1);

_putchar((z & 1) + '0');
}
