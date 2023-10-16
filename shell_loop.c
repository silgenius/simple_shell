#include "main.h"

/**
 * shell_loop - initiates the shell
 * @exe: name of the program
 * Return: void
 */

void shell_loop(char *exe)
{
	char *input;
	int count = 1, x = 1, exit_status = 0;
	ssize_t bufsize = line_size, len;

	while (x)
	{
		input = malloc(sizeof(char) * bufsize);
		if (input == NULL)
			perror_exit();
		if (isatty(STDIN_FILENO))
			printf("($) ");

		len = read_line(&input, &bufsize);
		if (len == -1)
		{
			free(input);
			exit(exit_status);
		}
		if (len == 0)
		{
			free(input);
			continue;
		}
		check_comment(input);
		check_variable(input, &exit_status);
		x = parse_string(input, exe, &count, &exit_status);
		count++;
		free(input);
	}
}
