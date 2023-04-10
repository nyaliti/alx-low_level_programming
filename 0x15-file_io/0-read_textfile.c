#include "main.h"

/**
 * read_textfile -  reads a text file and prints it to the POSIX
 * standard output.
 * @filename: The file name
 * @letters: Total number of letters to be read
 *
 * Return: number of letters read & printed
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int x, readCount;
	char b[1];
	ssize_t printCount = 0;

	if (filename == NULL)
		return (0);
	x = open(filename, O_RDONLY);
	if (x == -1)
		return (0);

	for (readCount = read(x, b, 1); readCount > 0 && printCount < (ssize_t)letters; readCount = read(x, b, 1))
	{
		printCount += write(STDOUT_FILENO, b, 1);
	}

	close(x);
	return (printCount);
}

