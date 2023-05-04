#include "main.h"

/**
 * _atoi - converts chars to integer
 *
 * @c: char to convert
 *
 * Return: converted integer
 */
unsigned int _atoi(char c)
{
	return ((unsigned int) c - '0');
}

/**
 * _strlen - gets the length of a string
 *
 * @str: string input
 *
 * Return: string length
 */
unsigned int _strlen(const char *str)
{
	unsigned int length = 0;

	/* iterate through string until null terminator is reached */
	while (str[length] != '\0')
		length++;

	return (length);
}

/**
 * binary_to_uint - a function that converts a binary number
 *                  to an unsigned int
 *
 * @b: string that contains 0 and 1 characters
 *
 * Return: the number converted or 0
 *         if @b contains a character
 *         that is not 0 or 1 or when
 *         @b is null
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0, num = 0;
	unsigned int length = _strlen(b);

	/* if b is NULL, return 0 */
	if (b == NULL)
		return (0);

	#ifdef DEBUG
	printf("String is %s, and length is %u.\n", b, length);
	#endif

	/* iterate through string in reverse order */
	for (int i = length - 1; i >= 0; i--)
	{
		num = _atoi(b[i]); /* convert character to unsigned int */

		/* if num is not 0 or 1, return 0 */
		if (num != 0 && num != 1)
			return (0);

		/* add num to result using bitwise OR operator and shift result left by 1 bit */
		result = (result << 1) | num;

		#ifdef DEBUG
		printf("Number is %u, index is %i and result is %u.\n", num, i, result);
		#endif
	}

	return (result);
}

