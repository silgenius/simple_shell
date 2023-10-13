#include "main.h"

/**
 * parse_string - checks the input command for semicolons etc
 * @input: input command
 * @exe: how the program is called
 * @cnt: loop count
 * Return: Always 1
 */

int parse_string(char *input, char *exe, int *cnt, int* exit_status)
{
	char *str, *ptr;
	int x = 1, semi_present;

	ptr = input;
	if (*ptr == ';')
	{
		printf("%s: %d: Syntax error: %c;%c unexpected\n", exe, *cnt, 34, 34);
		(*cnt)--;
		return (1);
	}
	/**
	 * check if chk_cmt has semicolons, return the part of the chk_cmd and
	 * and pass to interprete command till it returns NULL
	 */
	semi_present = _strchr(ptr, ';');
	str = _strsep(&ptr, ";");
	while (str != NULL)
	{
		if (*str != '\0')
			x = interprete_cmd(input, exe, cnt, str, exit_status);
		if (x == 0)
		{
			if (semi_present)
			{
				dprintf(STDERR_FILENO, "%s: %d: Syntax error: %c;%c unexpected\n", exe, *cnt, 34, 34);
				(*cnt)--;
			}
			x = 1;
			break;
		}
		str = _strsep(&ptr, ";");
	}
	return (x);
}
