#include "main.h"

/**
 * _strsep - extracts token from a string
 * @str: pointer to string
 * @delim: delimiters
 * Return: pointer to token
 */

char *_strsep(char **str, char *delim)
{
	char *start, *end;

	start = *str;
	if (start == NULL)
		return (NULL);
	end = start + strcspn(start, delim);
	if (*end)
	{
		*end++ = '\0';
		*str = end;
	}
	else
		*str = NULL;
	return (start);
}
