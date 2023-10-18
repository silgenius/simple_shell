#define EXIT_STATUS
#include "main.h"

/**
 * _prompt - prints a prompt
 *
 * Return: void
 */

void _prompt(void)
{
	write(STDOUT_FILENO, "($) ", 4);
}

/**
 * shell_loop - initiates the shell
 * @exe: name of the program
 * Return: void
 */

void shell_loop(char *exe)
{
	char *input;
	int count = 1, x = 1;
	ssize_t bufsize = line_size, len;

	while (x)
	{
		input = malloc(sizeof(char) * bufsize);
		if (input == NULL)
			perror_exit();
		if (isatty(STDIN_FILENO))
			_prompt();

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
		check_variable(input);
		x = parse_string(input, exe, &count);
		count++;
		free(input);
	}
}
