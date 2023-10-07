#include "main.h"

/**
 * split_string - splits a string into an array of strings
 * @input: string to be split
 * Return: pointer to array of strings
 */

char **split_string(char *input)
{
	char *str;
	char **str_arr = malloc(sizeof(char *) * 24);
	int x;

	if (str_arr == NULL)
	{
		exit(98);
	}
	x = 0;
	str = strtok(input, " \n\t\r\a");
	while (str != NULL)
	{
		str_arr[x] = malloc(sizeof(char) * strlen(str));
		if (str_arr[x] == NULL)
		{
			while (x >= 0)
			{
				free(str_arr[x]);
				x--;
			}
			free(str_arr);
			exit(98);
		}
		str_arr[x] = str;
		str = strtok(NULL, " \n\t\r\a");
		x++;
	}
	str_arr[x] = '\0';

	return (str_arr);
}
