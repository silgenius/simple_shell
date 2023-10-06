#include "main.h"

char **split_string(char *input)
{
	char *str;
	char **str_arr = malloc(sizeof(char *) * 24);
	int x;

	if (str_arr == NULL)
	{
		free(str_arr);
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
