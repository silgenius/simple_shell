#include "main.h"

/**
 * check_comment - checks its argument for a comment(preceded by a space)
 * and if found, removes the rest of the characters (comment inclusive)
 * @str: argument
 * Return: void
 */
void check_comment(char *str)
{
	int x = 0;

	while (str[x])
	{
		if (str[x] == '#')
		{
			if (x == 0 || (str[x - 1] == ' '))
			{
				str[x++] = '\0';
				while (str[x])
					str[x] = 0;
			}
		}
		x++;
	}
}
