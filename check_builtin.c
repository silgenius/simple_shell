#include "main.h"

/**
 * check_builtin - checks if the string passed is a builtin
 * @string: pointer to string
 * Return: a pointer to the function
 */

void (*check_builtin(char *string))(char **, char *, char *, int *)
{
	builtin_t list[] = {{"exit", shell_exit},
			    {"setenv", shell_setenv},
			    {"unsetenv", shell_unsetenv},
			    {"cd", change_dir},
			    {"env", print_env},
			    {"alias", alias_builtin},
			    {NULL, NULL}};
	int x = 0;

	while (list[x].str != NULL)
	{
		if (_strcmp(list[x].str, string) == 0)
			return (list[x].builtin);
		x++;
	}
	return (NULL);
}
