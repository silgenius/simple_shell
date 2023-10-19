#include "main.h"

/**
 * detectControlOperators - Detect control operators in the input command.
 *
 * This function checks the input command for the presence
 * of control operators.
 * It looks for "&&" (logical AND), "||" (logical OR),
 * and ";" (semicolon) in the command. If any of these control operators is
 * found,it returns the corresponding
 * integer value: 1 for "&&", 2 for "||", 3 for ";".
 * If no control operators are found, it returns 0.
 *
 * @command: Input command to be checked for control operators.
 * Return: Integer value representing the type of control operator found
 * or 0 if none.
 */
int detectControlOperators(const char *command)
{
	if (strstr(command, "&&") != NULL)
		return (1);
	else if (strstr(command, "||") != NULL)
		return (2);
	else if (strstr(command, ";") != NULL)
		return (3);
	else
		return (0);
}

