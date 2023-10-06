#include "main.h"

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
