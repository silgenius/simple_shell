#include "main.h"

/**
 * shell_exit - exits the shell
 * @str_arr: array of strings
 * @input: pointer to input command
 * @exe: name of program
 * @cnt: loop count
 * Return: void
 */

void shell_exit(char **str_arr, char *input, char *exe,
		int *cnt)
{
	char *ptr;
	int exit_value = exit_status;

	free_alias();
	if (str_arr[1])
	{
		exit_value = string_to_int(str_arr[1]);
		if (exit_value == 0)
		{
			_print_err(exe);
			_print_err(": ");
			ptr = convert_int_to_str(*cnt);
			_print_err(ptr);
			free(ptr);
			_print_err(": exit: Illegal number: ");
			_print_err(str_arr[1]);
			_print_err("\n");
			exit_status = 2;
			if (!isatty(STDERR_FILENO))
			{
				free(input);
				free_str_arr(str_arr);
				exit(exit_status);
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

void shell_setenv(char **str_arr, char *input, char *exe,
		  int *cnt)
{
	char *str, *ptr, *new_var, *env_dup;
	int x = 0;

	(void)input;
	(void)exe;
	new_var = create_env(str_arr[1], str_arr[2]);
	if (new_var == NULL)
	{
		_print_err("usage: setenv <variable_name> <variable_value\n");
		(*cnt)--;
		return;
	}
	for (; environ[x]; x++)
	{
		env_dup = _strdup(environ[x]);
		ptr = env_dup;
		str = _strsep(&ptr, "=");
		if (*str != '\0' && _strcmp(str_arr[1], str) == 0)
		{
			free(env_dup);
			/*free(environ[x]);*/
			environ[x] = _strdup(new_var);
			if (environ[x] == NULL)
				perror_exit();
			free(new_var);
			return;
		}
		free(env_dup);
	}
	if (!environ[x])
	{
		environ[x] = _strdup(new_var);
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

void shell_unsetenv(char **str_arr, char *input, char *exe,
		    int *cnt)
{
	char *str, *ptr, *env_dup;
	int x = 0;

	(void)input;
	(void)exe;
	if (str_arr[1] == NULL)
	{
		_print_err("usage: unsetenv <variable_name>\n");
		(*cnt)--;
		return;
	}
	for (; environ[x]; x++)
	{
		env_dup = _strdup(environ[x]);
		ptr = env_dup;
		str = _strsep(&ptr, "=");
		if (*str != '\0' && strcmp(str_arr[1], str) == 0)
		{
			free(env_dup);
			for (; environ[x]; x++)
			{
				if (environ[x + 1])
				{
					environ[x] = _strdup(environ[x + 1]);
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
void change_dir(char **str_arr, char *input, char *exe,
		int *cnt)
{
	int fd, check;
	char buff[1024];
	char *pwd_old, *ptr;

	(void)input;
	(void)exe;
	pwd_old = getenv("PWD");
	check = 1;

	if (str_arr[1] == NULL)
	{
		fd = chdir(getenv("HOME"));
		check = 0;
	}
	else if (_strcmp(str_arr[1], "-") == 0)
	{
		fd = chdir(getenv("OLDPWD"));
		if (fd != -1)
		{
			_print(getenv("OLDPWD"));
			_print("\n");
		}
		check = 0;
	}

	if (check)
		fd = chdir(str_arr[1]);
	if (fd == -1)
	{
		_print_err(exe);
		_print_err(": ");
		ptr = convert_int_to_str(*cnt);
		_print_err(ptr);
		free(ptr);
		_print_err(": cd: can't cd to ");
		_print_err(str_arr[1]);
		_print_err("\n");
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

void print_env(char **str_arr, char *input, char *exe,
	       int *cnt)
{
	int x = 0;

	(void)str_arr;
	(void)input;
	(void)exe;
	(void)cnt;
	for (; environ[x]; x++)
	{
		_print(environ[x]);
		_print("\n");
	}
}
