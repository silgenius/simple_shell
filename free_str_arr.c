#include "main.h"

/**
 * free_str_arr - frees an array of strings
 * @str_arr: array of strings
 * Return: void
 */

void free_str_arr(char **str_arr)
{
	int x = 0;

	if (str_arr == NULL)
		return;
	while (str_arr[x])
	{
		free(str_arr[x]);
		x++;
	}
	free(str_arr);
}
