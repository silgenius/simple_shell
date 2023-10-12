#include "main.h"

/**
 * read_line - reads user input from the stdin
 * @input: buffer to write the read into
 * @bufsize: size of the buffer
 * Return: length of read if successful, else -1
 */

ssize_t read_line(char **lineptr, ssize_t *bufsize)
{
        ssize_t position = 0;
        int c;

        while (1)
        {
                c = getchar();
                if (c == EOF)
                        return (-1);
                if (c == '\n')
                {
                        (*lineptr)[position] = '\0';
                        return (position);
                }
                else if (c == ' ' && position == 0)
                        continue;
                else
                        (*lineptr)[position] = c;
                position++;

                if (position >= *bufsize)
                {
                        *bufsize += line_size;
                        *lineptr = _realloc(*lineptr, *bufsize - line_size, *bufsize);
                        if (*lineptr == NULL)
                        {
                                perror("Error");
                                return (-1);
                        }
                }
        }
}
