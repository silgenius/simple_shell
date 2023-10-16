#include "main.h"

/**
 * print_colon_err - prints error msg for colon to std output
 * @exe: name of program
 * @cnt: loop count
 * @exit_status: error code
 * Return: void
 */

void print_colon_err(char *exe, int *cnt, int *exit_status)
{
	dprintf(STDERR_FILENO, "%s: %d: Syntax error: %c;%c unexpected\n",
		exe, *cnt, 34, 34);
	*exit_status = 2;
}
