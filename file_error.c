#include "main.h"

/**
 * file_error - prints an error to stderr when opening a file fails
 * @exe: name of program
 * @file: name of file
 * Return: void
 */

void file_error(char *exe, char *file)
{
	dprintf(STDERR_FILENO, "%s: 0: cannot open %s: No such file\n",
		exe, file);
	exit(2);
}
