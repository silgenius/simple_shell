#include "main.h"

/**
 * shell_loop - initiates the shell
 * @exe: name of the program
 * Return: void
 */

void shell_loop(char *exe)
{
	char *input;
	char **str_arr;
	int x = 1;
	int count = 1;
	size_t bufsize = 1024;
	ssize_t len;

	while (x)
	{
		input = malloc(sizeof(char) * bufsize);
		if (input == NULL)
		{
			perror("Error malloc error");
			free(input);
			return;
		}
		if (isatty(STDIN_FILENO))
			printf("($) ");

		len = read_line(input, &bufsize);
		if (len == -1)
		{
			/* perror("Error read_line"); */
			free(input);
			exit(98);
		}
		if (len == 0)
		{
			free(input);
			continue;
		}

		str_arr = split_string(input);
		x = interprete_cmd(str_arr, exe, &count);
		free(input);
	}
}
