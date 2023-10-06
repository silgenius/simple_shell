#include "main.h"

ssize_t read_line(char *input)
{
	ssize_t result;

	result = getline(&input, 1024, stdin);

	if (result <= 0)
	{
		perror("Error");
		return (-1);
	}
}
