#include "main.h"

/**
 * flip_bits - returns the number of bits needed to flip a number into another
 * @n: number to flip
 * @m: number to flip into
 * Return: no. of bits to flip
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
    unsigned int count = 0;
    unsigned int i = 0;

    while (i <= (sizeof(unsigned long int) * 8))
    {
        if ((m & 1) != (n & 1))
        {
            count++;
        }
        m >>= 1;
        n >>= 1;
        i++;
    }
    return (count);
}

