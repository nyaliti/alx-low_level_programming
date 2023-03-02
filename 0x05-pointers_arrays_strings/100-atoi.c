#include "main.h"

/**
 * _atoi - Converts a string to an integer.
 * @s: The string to be converted.
 *
 * Return: The converted integer.
 */
int _atoi(char *s)
{
    int sign = 1, res = 0;
    char *p = s;

    while (*p)
    {
        if (*p == '-')
            sign *= -1;
        if (*p >= '0' && *p <= '9')
            res = res * 10 + (*p - '0');
        if (res && !(*p >= '0' && *p <= '9'))
            break;
        p++;
    }

    return (res * sign);
}
