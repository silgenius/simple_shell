#include "main.h"

/**
 * shell_loop - initiates the shell
 * Return: void
 */

void shell_loop(void)
{
	char *input;
	char **str_arr;
	int x;
	size_t bufsize = 1024;
	ssize_t len;

	x = 1;

	while (x)
	{
		input = malloc(sizeof(char) * bufsize);
		if (input == NULL)
		{
			perror("Error");
			return;
		}

		printf("($) ");
		len = read_line(input, &bufsize);
		if (len == -1)
		{
			perror("Error");
			exit(98);
		}
		if (len == 0)
			continue;

		str_arr = split_string(input);
		x = interprete_cmd(str_arr);
		free(input);
	}
}
