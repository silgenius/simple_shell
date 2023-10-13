#include "main.h"

void alias_builtin(char **str_arr)
{
	if (str_arr[1] == NULL)
		print_alias();
	else if (str_arr[1]
