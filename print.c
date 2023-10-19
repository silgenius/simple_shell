#include "main.h"

/**
 * _print - prints a string to stdout
 * @str: string
 * Return: void
 */

void _print(char *str)
{
	int wr;

	if (str == NULL)
		return;
	wr = write(STDOUT_FILENO, str, _strlen(str));
	if (wr == -1)
		perror_exit();
}

/**
 * _print_err - prints a string to stderr
 * @str: string
 * Return: void
 */

void _print_err(char *str)
{
	int wr;

	if (str == NULL)
		return;
	wr = write(STDERR_FILENO, str, _strlen(str));
	if (wr == -1)
		perror_exit();
}
