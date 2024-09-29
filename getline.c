#include <stdio.h>
#include <stdlib.h>

/**
 * custom_getline - Reads a line from a file stream.
 * @lineptr: Pointer to the buffer containing the read line.
 * @n: Pointer to the size of the buffer.
 * @stream: File stream to read from.
 * Return: The number of characters read, or -1 on failure.
 */
int custom_getline(char **lineptr, size_t *n, FILE *stream)
{
    char *buf;
    int c;
    size_t len = 0;

    if (lineptr == NULL || n == NULL || stream == NULL)
        return (-1);

    if (*lineptr == NULL)
    {
        *n = 128;
        *lineptr = malloc(*n);
        if (*lineptr == NULL)
            return (-1);
    }

    buf = *lineptr;

    while ((c = fgetc(stream)) != EOF)
    {
        if (len + 1 >= *n)
        {
            size_t new_size = *n * 2;
            char *new_buf = realloc(*lineptr, new_size);
            if (!new_buf)
                return (-1);

            *n = new_size;
            buf = new_buf;
        }

        buf[len++] = c;
        if (c == '\n')
            break;
    }

    if (len == 0)
        return (-1);

    buf[len] = '\0';
    *lineptr = buf;
    return (len);
}
