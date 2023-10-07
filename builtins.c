#include "main.h"

/**
 * shell_exit - exits the shell
 * @str_arr: array of strings
 * Return: 0
 */

int shell_exit(char **str_arr)
{
	free_str_arr(str_arr);
	return (0);
}
