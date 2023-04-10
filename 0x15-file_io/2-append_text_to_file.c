#include "main.h"

/**
 * append_text_to_file -  appends text at the end of a file.
 * @filename: The file name
 * @text_content: The text contnet
 *
 * Return: int
 */
int append_text_to_file(const char *filename, char *text_content)
{
    int file_descriptor, status = -1;
    int length, x;

    if (filename == NULL)
        return (status);

    file_descriptor = open(filename, O_WRONLY | O_APPEND);
    if (file_descriptor == -1)
        return (status);

    status = 1;

    if (text_content != NULL) {
        x = 0;
        while (text_content[x] != '\0') {
            length++;
            x++;
        }
        status = write(file_descriptor, text_content, length);
        if (status != -1)
            status = 1;
    }

    close(file_descriptor);
    return (status);
}

