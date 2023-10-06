#include "main.h"

/**
 * check_builtin - checks if the string passed is a builtin
 * @string: pointer to string
 * Return: a pointer to the function
 */

int (*check_builtin(char *string))(char **)
{
	builtin_t list[] = {{"exit", shell_exit},
			    {NULL, NULL}};
	int x = 0;

	while (list[x].str != NULL)
	{
		if (strcmp(list[x].str, string) == 0)
			return (list[x].builtin);
		x++;
	}
	return (NULL);
}
