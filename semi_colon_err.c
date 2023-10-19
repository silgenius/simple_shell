#include "main.h"

/**
 * print_colon_err - prints error msg for colon to std output
 * @exe: name of program
 * @cnt: loop count
 * Return: void
 */

void print_colon_err(char *exe, int *cnt)
{
	char *ptr = convert_int_to_str(*cnt);

	_print_err(exe);
	_print_err(": ");
	_print_err(ptr);
	free(ptr);
	_print_err(": Syntax error: \';\' unexpected\n");
	exit_status = 2;
}
