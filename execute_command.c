#include "main.h"

/**
 * exec_cmd - takes an array of strings and executes it
 * @str_arr: array of strings
 * Return: 1
 */

int exec_cmd(char **str_arr)
{
	pid_t pid;
	int status;
	char *cmd;

	cmd = check_path(str_arr[0]);
	if (cmd == NULL)
	{
		printf("%s command not found\n", str_arr[0]);
	}
	else
	{
		pid = fork();
		if (pid == -1)
		{
			perror("Error");
			exit(98);
		}
		if (pid == 0)
		{
			if (execve(cmd, str_arr, environ) == -1)
			{
				perror("Error");
			}
		}
		if (pid > 0)
		{
			wait(&status);
		}
	}
	return (1);
}
