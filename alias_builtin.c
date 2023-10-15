#include "main.h"

/**
 * alias_builtin - Handles the 'alias' built-in command.
 * @str_arr: An array of strings containing the command and arguments.
 * @input: The input string (not used in this function).
 * @exe: The name of the shell executable (not used in this function).
 * @cnt: A pointer to an integer representing the command count.
 * @exit_status: A pointer to the exit status (not used in this function).
 *
 * Description: This function implements the behavior of the 'alias' command in
 *              the shell. It allows the user to define, print, or modify aliases.
 */
void alias_builtin(char **str_arr, char *input, char *exe, int *cnt, int *exit_status)
{

	char *name, *value, *equal_sign;
	int i;

	(void)input;
	(void)exe;
	(void)exit_status;

	if (str_arr[1] == NULL)
		print_alias();
	else
	{
		for(i = 1; str_arr[i] != NULL; i++)
		{
			equal_sign = strchr(str_arr[i], '=');

			if (equal_sign != NULL && equal_sign != str_arr[i])
			{
				/* Allocate memory for name and copy characters up to the equals sign */
				name = malloc((equal_sign - str_arr[i]) + 1);
				strncpy(name, str_arr[i], equal_sign - str_arr[i]);

				name[equal_sign - str_arr[i]] = '\0';
				value = strdup(equal_sign + 1);

				create_alias(name, value);

				free(name);
				free(value);
			}
			else
			{
				search_alias(str_arr[i]);
				(*cnt)--;
			}
		}
	}
}
