#include "main.h"

void write_var_to_input(char *var, char *input, int *count);

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
				write_var_to_input(tmp, input, &count);
			}
			else if (*str == '?')
				write_var_to_input("0", input, &count);
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

				if (var == NULL)
				{
					input[count] = ' ';
					count++;
				}
				else
				{
					strcat(var, " ");
					write_var_to_input(var, input, &count);
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

/**
 * write_var_to_input - Writes a variable to an input string.
 * @var: The variable to be written.
 * @input: The input string.
 * @count: A pointer to an integer representing the current count.
 *
 * Description: This function writes the provided variable to the input string
 * at the current count position. It updates the count to reflect
 * the new position after writing.
 *
 * Return: None.
 */
void write_var_to_input(char *var, char *input, int *count)
{
	while (*var != '\0')
	{
		input[*count] = *var;
		(*count)++;
		var++;
	}
}
