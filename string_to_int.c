#include "main.h"

/**
 * string_to_int - converts a string to an integer
 * @s: string to be converted
 * Return: value of converted string
 */

int string_to_int(char *s)
{
	int x = 0, num = 0, len;

	if (s == NULL)
		return (num);
	len = strlen(s);
	for (; x < len; x++)
	{
		if (s[x] > 47 && s[x] < 58)
			num = num * 10 + (s[x] - 48);
		else
			return (0);
	}
	return (num);
}
