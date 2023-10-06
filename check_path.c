#include "main.h"

/**
 * check_path - takes an argumentt and checks if it exists in $PATH
 * @command: string argument
 * Return: path to string argument, NULL if it doesn't exist
 */

char *check_path(char *command)
{
	struct stat buf;
	char *path, *path_dup, *str, *f_path;
	int cmd_len, dir_len;

	path = getenv("PATH");
	if (path)
	{
		path_dup = strdup(path);
		cmd_len = strlen(command);
		str = strtok(path_dup, ":");
		while (str != NULL)
		{
			dir_len = strlen(str);
			f_path = malloc(sizeof(char) * (dir_len + cmd_len + 2));
			if (f_path == NULL)
				exit(98);
			strcpy(f_path, str);
			strcat(f_path, "/");
			strcat(f_path, command);
			strcat(f_path, "\0");
			if (stat(f_path, &buf) == 0)
			{
				free(path_dup);
				return (f_path);
			}
			free(f_path);
			str = strtok(NULL, ":");
		}
		free(path_dup);
		if (stat(command, &buf) == 0)
			return (command);
		return (NULL);
	}
	return (NULL);
}
