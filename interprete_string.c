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
	int ret = 1, b = 0, x = 0;
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

	if (check_builtin(str_arr[0]) != NULL)
	{
		(*check_builtin(str_arr[0]))(str_arr, input, exe, cnt);
		b = 1;
	}
	if (b != 1)
		ret = (exec_cmd(str_arr, exe, cnt));

	free_str_arr(str_arr);
	return (ret);
}
