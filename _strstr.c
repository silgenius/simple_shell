#include "main.h"

/**
 * _strchr - locates a character in a string
 * @s: pointer to string
 * @c: character
 * Return: if found, 1 else 0
 */

int _strchr(char *s, char c)
{
	int x = 0;

	while (*(s + x) != '\0')
	{
		if (*(s + x) == c)
			return (1);
		x++;
	}
	if (c == '\0')
		return (1);
	return (0);
}
