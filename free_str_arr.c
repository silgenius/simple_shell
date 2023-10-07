#include "main.h"

/**
 * free_str_arr - frees an array of strings
 * @str_arr: array of strings
 * Return: void
 */

void free_str_arr(char **str_arr)
{
	if (str_arr == NULL)
		return;
	free(str_arr);
}
