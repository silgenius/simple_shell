#define DEFINE_ALIAS
#include "main.h"

/**
 * create_alias - Creates or updates an alias with a given name and value.
 * @name: The name of the alias.
 * @value: The value associated with the alias.
 *
 * Description: This function creates a new alias or updates an existing one
 * with the specified name and value. If an alias with the same name already
 * exists, its value is replaced with the provided value. If not, a new
 * alias is created.
 */
void create_alias(char *name, char *value)
{
	alias *ptr, *check, *new_node;
	char *tmp;

	check = head;
	/* truncate single quote ( ' ) if found in value */
	if (*value == '\'')
	{
		value++;
		tmp = _strndup(value, _strlen(value) - 1);
		value = _strdup(tmp);
	}

	/* modifies alias with similar name */
	if (modify_alias(check, name, value) != NULL)
		return;

	new_node = malloc(sizeof(alias));
	if (new_node == NULL)
		perror("Error");

	new_node->name = _strdup(name);
	new_node->value = _strdup(value);
	new_node->next = NULL;

	if (head == NULL)
		head = new_node;
	else
	{
		ptr = head;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = new_node;
	}
}

/**
 * print_alias - Prints a list of all aliases.
 *
 * Description: This function prints a list of all aliases,
 * one per line, in the format name='value'.
 */
void print_alias(void)
{
	alias *ptr;

	ptr = head;
	while (ptr != NULL)
	{
		printf("%s=\'%s\'\n", ptr->name, ptr->value);
		ptr = ptr->next;
	}
}

/**
 * search_alias - Searches for an alias by name.
 * @name: The name of the alias to search for.
 *
 * Description: This function searches for an alias with the specified name.
 * If found, it returns a pointer to the alias value; otherwise,
 * it returns NULL.
 *
 * Return: A pointer to the alias value if found, or NULL if not found.
 */
char *search_alias(char *name)
{
	alias *ptr;

	ptr = head;
	while (ptr != NULL)
	{
		if (_strcmp(ptr->name, name) == 0)
		{
			printf("%s=\'%s\'\n", ptr->name, ptr->value);
			return (ptr->value);
		}
		else
			ptr = ptr->next;
	}

	printf("./hsh: alias: %s: not found\n", name);
	return (NULL);
}

/**
 * free_alias - Frees memory allocated for alias nodes.
 *
 * Description: This function iterates through the linked list of aliases and
 * frees the memory allocated for each alias node.
 */
void free_alias(void)
{
	alias *ptr;

	while (head != NULL)
	{
		ptr = head->next;
		free(head);
		head = ptr;
	}
}

/**
 * replace_alias - Replaces an alias with its corresponding value.
 * @str_arr: The alias to be replaced.
 *
 * Description: This function searches for an alias with the specified name.
 * If found, it reallocates memory for the alias value, copies the
 * value, and returns a pointer to the new string. If the alias is
 * not found, it returns the original string.
 *
 * Return: A pointer to the new string if the alias is found, or the original
 * string if not found.
 */
char *replace_alias(char *str_arr)
{
	alias *ptr;

	ptr = head;

	while (ptr != NULL)
	{
		if (_strcmp(ptr->name, str_arr) == 0)
		{
			/*
			 * no need to realloc, just free str_arr, strdup
			 * already dynamically allocs memory
			 */
			free(str_arr);
			str_arr = _strdup(ptr->value);
			if (str_arr == NULL)
				perror_exit();
			return (replace_alias(str_arr));
		}

		else
			ptr = ptr->next;
	}

	return (str_arr);
}
