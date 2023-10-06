#include "main.h"

char **split_string(char *input)
{
	char *str;
	char **str_arr;
	int x;

	x = 0;

	str = strtok(input, " ");

	while (str != NULL)
	{
		str_arr[x] = str;
		str = strtok(NULL, " ");
		x++;
	}
	str_arr[x] = '\0';

	return ((char**) str_arr);
}

