#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Reads a text file and prints its contents to the POSIX standard output.
 * @filename: A pointer to the name of the file to be read.
 * @letters: The maximum number of bytes to be read and printed by the function.
 *
 * Return: If the function fails or filename is NULL - 0.
 *             Otherwise - the actual number of bytes read and printed by the function.
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	 ssize_t x, v, y;
	char *buffer;

	if (filename == NULL)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer ==  NULL)
		return (0);

	x = open(filename, O_RDONLY);
	v = read(x, buffer, letters);
	y = write(STDOUT_FILENO, buffer, v);

	if (x == -1 || v == -1 || y == -1 || y != v)
	{
		free(buffer);
		return (0);
	}

	free(buffer);
	close(x);

	return (y);

}
