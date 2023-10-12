#include "main.h"

/**
 * interprete_cmd - takes string, splits into arrays and
 * runs associated function it
 *
 * @input: pointer to input command string
 * @exe: name of the program
 * @cnt: the loop count
 * @str: string to be split
 * Return: 0 or 1
 */

int interprete_cmd(char *input, char *exe, int *cnt, char *str, int *exit_status)
{
	int ret = 1, b = 0;
	size_t arr_size = sizeof(char *) * 24, x = 0, new_arr_size;
	char *ptr;
	char **str_arr = malloc(arr_size);

	if (str_arr == NULL)
		perror_exit();
	ptr = strtok(str, " \n\t\r\a");
	if (ptr == NULL)
	{
		free(str_arr);
		return (0);
	}
	while (ptr != NULL)
	{
		str_arr[x] = strdup(ptr);
		if (str_arr[x] == NULL)
			perror_exit();
		ptr = strtok(NULL, " \n\t\r\a");
		x++;
		if (x >= arr_size)
		{
			new_arr_size = arr_size + 2;
			str_arr = _realloc(str_arr, arr_size, new_arr_size);
			arr_size = new_arr_size;
			if (str_arr == NULL)
				perror_exit();
		}
	}
	str_arr[x] = '\0';
	if (check_builtin(str_arr[0]) != NULL)
	{
		(*check_builtin(str_arr[0]))(str_arr, input, exe, cnt);
		b = 1;
	}
	if (b != 1)
		ret = (exec_cmd(str_arr, exe, cnt, exit_status));
	free_str_arr(str_arr);
	free(input);
	return (ret);
}
