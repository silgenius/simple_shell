#include "main.h"

/**
 * shell_exit - exits the shell
 * @str_arr: array of strings
 * Return: 0
 */

int shell_exit(char **str_arr)
{
	(void)str_arr;
	return (0);
}

int print_env(char **str_arr)
{
	int fd;
	ssize_t byteread;
	char file[20];
	char buffer[4096];
	char *temp;
	pid_t my_pid;

	(void) str_arr;

	my_pid = getpid();
	sprintf(file, "/proc/%u/environ", my_pid);

	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit(98);
	byteread = read(fd, buffer, sizeof(buffer));

	close(fd);

	if (byteread > 0)
	{
		temp = buffer;
		while (temp < (buffer + byteread))
		{
			printf("%s\n", temp);
			temp += strlen(temp) + 1;
		}
	}
	else
		exit(98);
	return (1);
}
