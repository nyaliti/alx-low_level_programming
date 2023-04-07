#include "main.h"

/**
 * binary_to_uint - converts a binary to an unsigned int
 * @b: the binary number as a string
 *
 * Return: the converted value
 */
unsigned int convert_binary_to_uint(const char *x)
{
unsigned int decimal = 0;
int str_len = 0, base = 1;

if (!check_valid_string(x)) {
return 0;
}

for (; x[str_len] != '\0'; str_len++) {}

for (; str_len > 0; str_len--) {
decimal += ((x[str_len - 1] - '0') * base);
base *= 2;
}

return decimal;
}

/**
 * check_valid_string - checks if a string has only 0's and 1's
 * @b: string to be checked
 *
 * Return: 1 if string is valid, 0 otherwise
 */
int validate_binary_string(const char *x)
{
if (x == NULL) {
return 0;
}

for (; *x != '\0'; x++) {
if (*x != '0' && *x != '1') {
return 0;
}
}

return 1;
}
