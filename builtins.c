#include "main.h"

/**
 * shell_exit - exits the shell
 * @str_arr: array of strings
 * @input: pointer to input command
 * @exe: name of program
 * @cnt: loop count
 * Return: void
 */

void shell_exit(char **str_arr, char *input, char *exe, int *cnt, int *exit_status)
{
	int exit_value = *exit_status;

	if (str_arr[1])
	{
		if ((exit_value = string_to_int(str_arr[1])) == 0)
		{
			dprintf(STDERR_FILENO, "%s: %d: exit: Illegal number: %s\n", exe, *cnt, str_arr[1]);
			if (!isatty(STDERR_FILENO))
			{
				free(input);
				free_str_arr(str_arr);
				exit(2);
			}
			(*cnt)--;
		}
		else
		{
			free(input);
			free_str_arr(str_arr);
			exit(exit_value);
		}
	}
	else
	{
		free(input);
		free_str_arr(str_arr);
		exit(exit_value);
	}
}

/**
 * shell_setenv - creates or modifies an environmental variable
 * @str_arr: array of strings
 * @input: pointer to input command
 * @exe: name of program
 * @cnt: loop count
 * Return: void
 */

void shell_setenv(char **str_arr, char *input, char *exe, int *cnt, int *exit_status)
{
	char *str, *new_var, *env_dup;
	int x = 0;

	(void)input;
	(void)exe;
	(void)exit_status;
	new_var = create_env(str_arr[1], str_arr[2]);
	if (new_var == NULL)
	{
		write_err("usage: setenv <variable_name> <variable_value\n");
		(*cnt)--;
		return;
	}
	for (; environ[x]; x++)
	{
		env_dup = strdup(environ[x]);
		str = strtok(env_dup, "=");
		if (strcmp(str_arr[1], str) == 0)
		{
			free(env_dup);
			free(environ[x]);
			environ[x] = strdup(new_var);
			if (environ[x] == NULL)
				perror_exit();
			free(new_var);
			break;
		}
		free(env_dup);
	}
	if (!environ[x])
	{
		environ[x] = strdup(new_var);
		if (environ[x] == NULL)
			perror_exit();
		x++;
		environ[x] = NULL;
	}
	free(new_var);
}

/**
 * shell_unsetenv - deletes an environmental variable
 * @str_arr: array of strings
 * @input: pointer to input command
 * @exe: name of program
 * @cnt: loop count
 * Return: void
 */

void shell_unsetenv(char **str_arr, char *input, char *exe, int *cnt, int *exit_status)
{
	char *str, *env_dup;
	int x = 0;

	(void)input;
	(void)exe;
	(void)exit_status;
	if (str_arr[1] == NULL)
	{
		write_err("usage: unsetenv <variable_name>\n");
		(*cnt)--;
		return;
	}
	for (; environ[x]; x++)
	{
		env_dup = strdup(environ[x]);
		str = strtok(env_dup, "=");
		if (strcmp(str_arr[1], str) == 0)
		{
			free(env_dup);
			for (; environ[x]; x++)
			{
				free(environ[x]);
				if (environ[x + 1])
				{
					environ[x] = strdup(environ[x + 1]);
					if (environ[x] == NULL)
						perror_exit();
				}
				else
					environ[x] = NULL;
			}
			break;
		}
		free(env_dup);
	}
}

/**
 * change_dir - Changes the current working directory.
 * @str_arr: An array of strings containing the directory path.
 * @input: pointer to input command
 * @exe: name of program
 * @cnt: loop count
 *
 * Description: This function takes an array of strings where the first element
 * is the command and the second element (if present) is the path
 * of the directory to change to. If no path is provided, it changes
 * to the home directory. It updates the environment variable 'PWD'
 * with the new current working directory if successful.
 *
 * Return: 1 if the directory change is successful, otherwise an error message
 * is printed and the return value is still 1.
 */
void change_dir(char **str_arr, char *input, char *exe, int *cnt, int *exit_status)
{
	int fd, check;
	char buff[1024];
	char *pwd_old;

	(void)input;
	(void)exe;
	(void)exit_status;
	pwd_old = getenv("PWD");
	check = 1;
	if (str_arr[1] == NULL)
	{
		fd = chdir(getenv("HOME"));
		check = 0;
	}
	else if (strcmp(str_arr[1], "-") == 0)
	{
		fd = chdir(getenv("OLDPWD"));
		fd == - 1 ? fd = -1 : printf("%s\n", getenv("OLDPWD"));
		check = 0;
	}

	if (check)
		fd = chdir(str_arr[1]);
	if (fd == -1)
	{
		perror("./hsh: cd");
		(*cnt)--;
	}
	else
	{
		if (getcwd(buff, sizeof(buff)) != NULL)
		{
			setenv("PWD", buff, 1);
			setenv("OLDPWD", pwd_old, 1);
		}
	}
}

/**
 * print_env - prints the environment's variables
 * @str_arr: array of strings
 * @input: pointer to input command
 * @exe: name of program
 * @cnt: loop count
 * Return: void
 */

void print_env(char **str_arr, char *input, char *exe, int *cnt, int *exit_status)
{
	int x = 0;

	(void)str_arr;
	(void)input;
	(void)exe;
	(void)cnt;
	(void)exit_status;
	for (; environ[x]; x++)
		printf("%s\n", environ[x]);
}
