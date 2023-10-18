#include "main.h"

/**
 * check_path - takes an argumentt and checks if it exists in $PATH
 * @command: string argument
 * Return: path to string argument, NULL if it doesn't exist
 */

char *check_path(char *command)
{
	struct stat buf;
	char *path, *path_dup, *str, *ptr, *f_path;
	int cmd_len = _strlen(command), dir_len;

	path = getenv("PATH");
	if (path)
	{
		path_dup = _strdup(path);
		ptr = path_dup;
		str = _strsep(&ptr, ":");
		while (str != NULL)
		{
			if (*str != '\0')
			{
				dir_len = _strlen(str);
				f_path = malloc(sizeof(char) * (dir_len + cmd_len + 2));
				if (f_path == NULL)
					perror_exit();
				_strcpy(f_path, str);
				_strcat(f_path, "/");
				_strcat(f_path, command);
				_strcat(f_path, "\0");
				if (stat(f_path, &buf) == 0)
				{
					free(path_dup);
					return (f_path);
				}
				free(f_path);
			}
			str = _strsep(&ptr, ":");
		}
		free(path_dup);
	}
	if (stat(command, &buf) == 0)
		return (_strdup(command));
	return (NULL);
}
