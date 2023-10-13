#include "main.h"

void create_alias(alias **head, char *name, char *value)
{
	alias *ptr;
	alias *new_node;

	new_node = malloc(sizeof(alias));
	if (new_node == NULL)
		perror("Error");

	new_node->name = name;
	new_node->value = value;
	new_node->next = NULL;

	if (*head == NULL)
		*head = new_node;
	else
	{
		ptr = *head;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = new_node;
	}
}

void print_alias(alias *head)
{
	alias *ptr;

	ptr = head;
	while (ptr != NULL)
	{
		printf("%s=%s\n", ptr->name, ptr->value);
		ptr = ptr->next;
	}
}

char *search_alias(alias *head, char *name)
{
	alias *ptr;

	ptr = head;
	while (ptr != NULL)
	{
		if (strcmp(ptr->name, name) == 0)
			return (ptr->value);
		else
			ptr = ptr->next;
	}

	printf("./hsh: alias: %s: not found", name);
	return (NULL);
}

void free_alias(alias *head)
{
	alias *ptr;

	while (head != NULL)
	{
		ptr = head->next;
		free(head);
		head = ptr;
	}
}
