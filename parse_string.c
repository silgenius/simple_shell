#include "main.h"
#define EXIT_STATUS

/**
 * parse_string - checks the input command for semicolons etc
 * @input: input command
 * @exe: how the program is called
 * @cnt: loop count
 * Return: Always 1
 */

int parse_string(char *input, char *exe, int *cnt)
{
	char *str, *ptr, *semi_present;
	int x = 1, check = detectControlOperators(input);

	ptr = input;
	if (check_ptr(ptr, cnt, exe) == 1)
		return (1);
	/**
	 * check if ptr has semicolons, return that part of the ptr and
	 * and pass to interprete command till it returns NULL
	 */
	semi_present = _strchr(ptr, ';');
	str = _strsep(&ptr, "&|;");
	while (str != NULL)
	{
		if (*str != '\0')
			x = interprete_cmd(input, exe, cnt, str);
		if (x == 0)
		{
			if (semi_present)
			{
				print_colon_err(exe, cnt);
				(*cnt)--;
			}
			x = 1;
			break;
		}
		if (ptr != NULL && (*ptr == '&' || *ptr == '|'))
			ptr++;
		if (check == 1 && exit_status != 0)
			str = _strsep(&ptr, "&|;");
		if (check == 2 && exit_status == 0)
			str = _strsep(&ptr, "&|;");
		if (ptr != NULL && (*ptr == '&' || *ptr == '|'))
			ptr++;
		str = _strsep(&ptr, "&|;");
	}

	return (x);
}

/**
 * check_ptr - Check if a character in the input string is a special symbol.
 *
 * This function checks whether the given character in the input string is
 * a semicolon (';'), ampersand ('&'), or pipe ('|'). If any of these special
 * symbols is found, it prints an error message using the print_colon_err
 * function,decrements the loop count, and returns 1. Otherwise, it returns 0.
 *
 * @ptr: Pointer to the character being checked in the input string.
 * @cnt: Pointer to the loop count.
 * @exe: Pointer to the name of the executable (program name).
 * Return: 1 if the character is a special symbol, 0 otherwise.
 */
int check_ptr(char *ptr, int *cnt, char *exe)
{
	if (*ptr == ';' || *ptr == '&' || *ptr == '|')
	{
		print_colon_err(exe, cnt);
		(*cnt)--;
		return (1);
	}

	return (0);
}
