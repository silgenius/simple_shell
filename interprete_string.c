#include "main.h"

/**
 * interprete_cmd - takes an array of strings and interprets it
 * @str_arr: an array of strings
 * @exe: name of the program
 * @cnt: the loop count
 * Return: 0 or 1
 */

int interprete_cmd(char **str_arr, char *exe, int *cnt)
{
	int x;

	for (x = 0; x < 1; x++)
	{
		if (check_builtin(str_arr[x]) != NULL)
			return ((*check_builtin(str_arr[x]))(str_arr));
	}
	return (exec_cmd(str_arr, exe, cnt));
}
