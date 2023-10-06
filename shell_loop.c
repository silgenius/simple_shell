#include "main.h"

void shell_loop()

{
	char *input;
	char **str_arr;
	int x;

	x = 1;

	while (x)
	{
		input = malloc(1024);
		if (input == NULL)
		{
			perror("Error");
			return;
		}

		if (read_line(input) == -1)
		{
			perror("Error");
			return;
		}

		str_arr = split_string(input);
		x = execute_string(str_arr);
	}
}


