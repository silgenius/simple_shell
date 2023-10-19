#include "main.h"

/**
 * create_env - creates the format for en anv variable
 * @var: variable name
 * @value: variable value
 * Return: pointer to format
 */

char *create_env(char *var, char *value)
{
	char *new_var;

	if (var == NULL || value == NULL || _strlen(var) == 0 || _strchr(var, '='))
		return (NULL);
	new_var = malloc(sizeof(char) * (_strlen(var) + _strlen(value) + 2));
	if (new_var == NULL)
		perror_exit();
	_strcpy(new_var, var);
	_strcat(new_var, "=");
	_strcat(new_var, value);
	_strcat(new_var, "\0");
	return (new_var);
}
