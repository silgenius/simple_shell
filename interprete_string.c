#include "main.h"

/**
 * interprete_cmd - takes string, splits into arrays and
 * runs associated function it
 *
 * @input: string to be split
 * @exe: name of the program
 * @cnt: the loop count
 * Return: 0 or 1
 */

int interprete_cmd(char *input, char *exe, int *cnt)
{
	int i, ret = 0, b = 0, x = 0;
	char *str;
	char **str_arr = malloc(sizeof(char *) * 24);

	str = strtok(input, " \n\t\r\a");
	while (str != NULL)
	{
		str_arr[x] = strdup(str);
		str = strtok(NULL, " \n\t\r\a");
		x++;
	}
	str_arr[x] = '\0';

	for (i = 0; i < 1; i++)
	{
		if (check_builtin(str_arr[i]) != NULL)
		{
			ret = ((*check_builtin(str_arr[i]))(str_arr));
			b = 1;
			break;
		}
	}
	if (b != 1)
		ret = (exec_cmd(str_arr, exe, cnt));

	x--;
	while (x >= 0)
	{
		free(str_arr[x]);
		x--;
	}
	free(str_arr);
	return (ret);
}
