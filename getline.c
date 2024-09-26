#include "monty.h"

int custom_getline(char **lineptr, size_t *n, FILE *stream)
{
    size_t pos = 0;
    int c;

    if (*lineptr == NULL)
    {
        *lineptr = malloc(128);
        if (*lineptr == NULL)
            return -1;
        *n = 128;
    }

    while ((c = fgetc(stream)) != EOF)
    {
        if (pos + 1 >= *n)
        {
            size_t new_size = *n * 2;
            char *new_ptr = realloc(*lineptr, new_size);
            if (new_ptr == NULL)
                return -1;
            *lineptr = new_ptr;
            *n = new_size;
        }

        (*lineptr)[pos++] = c;

        if (c == '\n')
            break;
    }

    if (pos == 0)
        return -1;

    (*lineptr)[pos] = '\0';
    return pos;
}
