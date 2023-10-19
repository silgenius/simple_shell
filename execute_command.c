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
	char *cmd, *ptr;

	cmd = check_path(str_arr[0]);
	if (cmd == NULL)
	{
		_print_err(exe);
		_print_err(": ");
		ptr = convert_int_to_str(*cnt);
		_print_err(ptr);
		free(ptr);
		_print_err(": ");
		_print_err(str_arr[0]);
		_print_err(": ");
		_print_err("not found\n");
		exit_status = 127;
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
			exit_status = WEXITSTATUS(status);
		}
	}
	return (1);
}
