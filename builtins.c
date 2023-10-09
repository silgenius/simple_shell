#include "main.h"

/**
 * shell_exit - exits the shell
 * @str_arr: array of strings
 * @input: pointer to input command
 * @exe: name of program
 * @cnt: loop count
 * Return: void
 */

void shell_exit(char **str_arr, char *input, char *exe, int *cnt)
{
	int exit_value = 0;

	if (str_arr[1])
	{
		exit_value = string_to_int(str_arr[1]);
		if (exit_value == 0)
		{
			printf("%s: %d: exit: Illegal number: %s\n", exe, *cnt, str_arr[1]);
			(*cnt)++;
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

void shell_setenv(char **str_arr, char *input, char *exe, int *cnt)
{
	char *str, *new_var, *env_dup;
	int x = 0;

	(void)input;
	(void)exe;
	(void)cnt;
	new_var = create_env(str_arr[1], str_arr[2]);
	if (new_var == NULL)
		write_err("usage: setenv <variable_name> <variable_value\n");
	else
	{
		for (; environ[x]; x++)
		{
			env_dup = strdup(environ[x]);
			str = strtok(env_dup, "=");
			if (strcmp(str_arr[1], str) == 0)
			{
				free(env_dup);
				free(environ[x]);
				environ[x] = strdup(new_var);
				free(new_var);
				break;
			}
			free(env_dup);
		}
		if (!environ[x])
		{
			environ[x] = strdup(new_var);
			x++;
			environ[x] = NULL;
		}
		free(new_var);
	}
}

/**
 * shell_unsetenv - deletes an environmental variable
 * @str_arr: array of strings
 * @input: pointer to input command
 * @exe: name of program
 * @cnt: loop count
 * Return: void
 */

void shell_unsetenv(char **str_arr, char *input, char *exe, int *cnt)
{
	char *str, *env_dup;
	int x = 0;

	(void)input;
	(void)exe;
	(void)cnt;
	if (str_arr[1] == NULL)
		write_err("usage: unsetenv <variable_name>\n");
	else
	{
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
						environ[x] = strdup(environ[x + 1]);
					else
						environ[x] = NULL;
				}
				break;
			}
			free(env_dup);
		}
	}
}
