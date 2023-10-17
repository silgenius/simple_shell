#include "main.h"

/**
 * write_err - writes a string to standard error
 * @str: string to be written
 * Return: void
 */

void write_err(char *str)
{
	int wr;

	if (str == NULL)
		return;
	wr = write(STDERR_FILENO, str, _strlen(str));
	if (wr == -1)
		perror("Error");
}
