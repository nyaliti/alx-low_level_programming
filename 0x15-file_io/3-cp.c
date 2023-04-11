#include "main.h"

/**
 * my_main - This is the entry point of the program
 * @argc: The number of arguments
 * @argv: The array of arguments
 *
 * Returns: 0 on success, otherwise a non-zero value
 */
int my_main(int argc, char **argv[])
{
	int fd1, fd2, status;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: my_cp file_from file_to\n");
		exit(1);
	}

	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_CREAT | O_WRONLY, 0664);

	if (fd1 == -1)
	{
		dprintf(STDERR_FILENO, "Error: Cannot read from file %s\n", argv[1]);
		exit(2);
	}

	if (fd2 == -1)
	{
		dprintf(STDERR_FILENO, "Error: Cannot write to %s\n", argv[2]);
		exit(3);
	}

	my_copy(fd1, fd2, argv[1], argv[2]);
	status = close(fd1);
	if (status == -1)
		dprintf(STDERR_FILENO, "Error: Cannot close fd %d\n", fd1);
	status = close(fd2);
	if (status == -1)
		dprintf(STDERR_FILENO, "Error: Cannot close fd %d\n", fd2);
	if (status == -1)
		exit(4);
	return (0);
}

/**
 * my_copy - Copies data from one file descriptor to another
 * @from: The source file descriptor
 * @to: The destination file descriptor
 * @fromFilename: The source file name
 * @toFilename: The destination file name
 *
 * Returns: void
 */
void my_copy(int from, int to, char *fromFilename, char *toFilename)
{
	char buffer[1024];
	int status, count;

	count = read(from, buffer, 1024);
	while (count != 0)
	{
		if (count < 0)
		{
			dprintf(STDERR_FILENO, "Error: Cannot read from file %s\n", fromFilename);
			exit(2);
		}
		status = write(to, buffer, count);
		if (status == -1)
		{
			dprintf(STDERR_FILENO, "Error: Cannot write to %s\n", toFilename);
			exit(3);
		}
		count = read(from, buffer, 1024);
	}
}

