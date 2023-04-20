#include "main.h"

/**
 * main - copies the content of a file to another file
 * @argc: number of arguments passed to the program
 * @argv: array of arguments
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	int fd_r, fd_w, x, m, n;
	char buf[BUFSIZ];

	// check if there are 3 arguments (program name, file from, file to)
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	// open file from for reading
	fd_r = open(argv[1], O_RDONLY);
	if (fd_r < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	// open file to for writing, create if not exists, truncate if exists
	fd_w = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	// loop through file from and write to file to
	for (;;)
	{
		// read from file from into buf of size BUFSIZ
		x = read(fd_r, buf, BUFSIZ);

		// break loop if no more bytes to read
		if (x == 0)
			break;

		// check for errors while writing to file to
		if (fd_w < 0 || write(fd_w, buf, x) != x)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			close(fd_r);
			exit(99);
		}
	}

	// check for errors while reading from file from
	if (x < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	// close file from and file to
	m = close(fd_r);
	n = close(fd_w);

	// check for errors while closing file descriptors
	if (m < 0 || n < 0)
	{
		if (m < 0)
			dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_r);
		if (n < 0)
			dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_w);
		exit(100);
	}

	return (0);
}

