#include "main.h"

/**
 * exec_cmd - takes an array of strings and executes it
 * @str_arr: array of strings
 * @exe: name of the program
 * @cnt: loop count
 * Return: 1
 */

int exec_cmd(char **str_arr, char *exe, int *cnt)
{
	pid_t pid;
	int status;
	char *cmd;

	cmd = check_path(str_arr[0]);
	if (cmd == NULL)
	{
		printf("%s: %d: %s: not found\n", exe, *cnt, str_arr[0]);
		(*cnt)--;
	}
	else
	{
		pid = fork();
		if (pid == -1)
			perror_exit();
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
			free(cmd);
		}
	}
	return (1);
}
