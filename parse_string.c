#include "main.h"

/**
 * parse_string - checks the input command for semicolons etc
 * @input: input command
 * @exe: how the program is called
 * @cnt: loop count
 * @exit_status: value of error code
 * Return: Always 1
 */

int parse_string(char *input, char *exe, int *cnt, int *exit_status)
{
	char *str, *ptr;
	int x = 1, semi_present;

	ptr = input;
	if (*ptr == ';')
	{
		print_colon_err(exe, cnt, exit_status);
		(*cnt)--;
		return (1);
	}
	/**
	 * check if ptr has semicolons, return that part of the ptr and
	 * and pass to interprete command till it returns NULL
	 */
	semi_present = _strchr(ptr, ';');
	str = _strsep(&ptr, ";");
	while (str != NULL)
	{
		if (*str != '\0')
			x = interprete_cmd(input, exe, cnt, str, exit_status);
		if (x == 0)
		{
			if (semi_present)
			{
				print_colon_err(exe, cnt, exit_status);
				(*cnt)--;
			}
			x = 1;
			break;
		}
		str = _strsep(&ptr, ";");
	}

	return (x);
}
