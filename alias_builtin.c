#include "main.h"

/**
 * alias_builtin - Handles the 'alias' built-in command.
 * @str_arr: An array of strings containing the command and arguments.
 * @input: The input string (not used in this function).
 * @exe: The name of the shell executable (not used in this function).
 * @cnt: A pointer to an integer representing the command count.
 *
 * Description: This function implements the behavior of the 'alias' command in
 * the shell. It allows the user to define, print, or modify aliases.
 */
void alias_builtin(char **str_arr, char *input,
		char *exe, int *cnt)
{

	char *name, *value, *equal_sign;
	int i;

	(void)input;
	(void)exe;
	if (str_arr[1] == NULL)
		print_alias();
	else
	{
		for (i = 1; str_arr[i] != NULL; i++)
		{
			equal_sign = _strchr(str_arr[i], '=');

			if (equal_sign != NULL && equal_sign != str_arr[i])
			{
				/* Allocate memory for name and copy characters up to the equals sign */
				name = malloc((equal_sign - str_arr[i]) + 1);
				_strncpy(name, str_arr[i], equal_sign - str_arr[i]);

				name[equal_sign - str_arr[i]] = '\0';
				value = _strdup(equal_sign + 1);

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

/**
 * modify_alias - Modifies the value of an existing alias.
 * @check: Pointer to the head of the alias linked list.
 * @name: The name of the alias to be modified.
 * @value: The new value for the alias.
 *
 * Description: This function iterates through the linked list of aliases. If
 * it finds an alias with a matching name, it updates the value and
 * returns a pointer to the updated value. If no match is found, it
 * returns NULL.
 *
 * Return: A pointer to the updated value if modification is successful, or
 * NULL if the alias is not found.
 */
char *modify_alias(alias *check, char *name, char *value)
{
	while (check != NULL)
	{
		if (strcmp(check->name, name) == 0)
		{
			check->value = _strdup(value);
			return (check->value);
		}
		else
			check = check->next;
	}
	return (NULL);
}
