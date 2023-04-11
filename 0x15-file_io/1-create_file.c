#include "main.h"

/**
 * create_new_file - creates a new file and writes text to it
 * @filename: name of the file to create
 * @text_content: text to write to the file
 *
 * Return: 1 on success, -1 on failure
 */
int create_new_file(const char *filename, char *text_content)
{
    int file_des, status = -1;
    int text_length, x;

    if (filename == NULL)
        return (status);

    file_des = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

    if (file_des < 0)
        return (status);

    status = 1;
    if (text_content != NULL)
    {
        for (i = 0, text_length = 0; text_content[x] != '\0'; x++)
            text_length++;
        status = write(file_des, text_content, text_length);
        if (status >= 0)
            status = 1;
    }

    close(file_des);
    return (status);
}

