#include "main.h"

/**
 * append_text_to_file - Appends text to the end of a file.
 *
 * @filename: A pointer to the name of the file.
 * @text_content: The string to append to the end of the file.
 *
 * Return: On success, returns 1.
 *         On failure, returns -1 and sets errno to indicate the error.
 *         Possible errors include:
 *           - If the file does not exist and the user lacks write permissions.
 *           - If filename is NULL.
 */

int append_text_to_file(const char *filename, char *text_content)
{
    int x, y, length = 0;

    if (filename == NULL)
        return (-1);

    if (text_content != NULL)
    {
        while (text_content[length])
            length++;
    }

    x = open(filename, O_WRONLY | O_APPEND);
    y = write(x, text_content, length);

    if (x == -1 || y == -1)
        return (-1);

    close(x);

    return (1);
}
