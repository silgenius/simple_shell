#include "main.h"

/**
 * check_variable - Handles variable replacement in input string.
 * @input: The input string to be processed.
 *
 * Description: This function takes an input string and processes it to replace
 * variables. It handles the $? variable, which represents the
 * exit status of the last command, and the $$ variable, which
 * represents the current process ID. The modified string is then
 * returned.
 *
 * Return: A dynamically allocated string with variables replaced.
 */
void check_variable(char *input)
{
	char *str = strdup(input);
	char *var;
	int count, i;
	char tmp[10];
	pid_t pid;

	pid = getpid();
	count = 0;
	i = 0;
	while (*str != '\0')
	{
		if (*str == '$' && *(str + 1) != ' ' && *(str + 1) != '\0')
		{
			str++;

			if (*str == '$')
			{
				sprintf(tmp, "%u", pid);
				var = tmp;
			}
			else if (*str == '?')
				var = "0";
			else
			{
				while (*str != ' ' && *str != '\0')
				{
					tmp[i] = *str;
					i++;
					str++;
				}
				tmp[i] = '\0';
				var = getenv(tmp);
			}

			if (var == NULL)
			{
				input[count] = ' ';
				count++;
			}
			else
			{
				strcat(var, " ");
				while (*var != '\0')
				{
					input[count] = *var;
					count++;
					var++;
				}
			}
		}
		else
		{
			input[count] = *str;
			count++;
		}
		str++;
	}

	input[count] = '\0';

}

