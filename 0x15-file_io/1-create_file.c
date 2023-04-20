#include "main.h"

/**
 * create_file - creates a file and fills it with text
 * @filename: name of the file to create
 * @text_content: text to write in the file
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int fd;  // file descriptor
	int bytes_written, i = 0;  // bytes_written - number of bytes written to the file, i - loop counter

	if (!filename)  // check if filename is NULL
		return (-1);

	// create the file with read, write, and execute permissions for owner, and no permissions for group and others
	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600); 
	if (fd < 0)  // check if file descriptor is valid
		return (-1);

	if (text_content)  // if there is text to write
	{
		// count the number of characters in the text content
		for (; text_content[i] != '\0'; i++)
			;
		bytes_written = write(fd, text_content, i);  // write the text content to the file
		if (bytes_written != i)  // check if all bytes were written
			return (-1);
	}

	close(fd);  // close the file descriptor

	return (1);
}

