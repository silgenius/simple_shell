#include "main.h"

/**
 * read_line - reads user input from the stdin
 * @input: buffer to write the read into
 * @bufsize: size of the buffer
 * Return: length of read if successful, else -1
 */

ssize_t read_line(char *input, size_t *bufsize)
{
	ssize_t result = getline(&input, bufsize, stdin);

	if (result > 0)
	{
		if (input[result - 1] == '\n')
		{
			input[result - 1] = 0;
			result--;
		}
	}
	return (result);
}
