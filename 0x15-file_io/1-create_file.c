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
    int fd, x, y = 0;

    if (!filename) // check if filename is null
        return (-1);

    // create a new file with read/write permission for owner only
    // and truncate it if it already exists
    fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
    if (fd < 0) // check if open failed
        return (-1);

    if (text_content) // check if there is text to write
    {
        while (text_content[y]) // count the number of characters in the text
            y++;

        // write the text to the file
        x = write(fd, text_content, y);
        if (x != y) // check if the write was incomplete
            return (-1);
    }

    close(fd); // close the file

    return (1); // return success
}

