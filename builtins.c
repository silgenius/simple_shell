#include "main.h"

/**
 * shell_exit - exits the shell
 * @str_arr: array of strings
 * Return: 0
 */

int shell_exit(char **str_arr)
{
	free_str_arr(str_arr);
	return (0);
}

/**
 * change_dir - Changes the current working directory.
 * @str_arr: An array of strings containing the directory path.
 *
 * Description: This function takes an array of strings where the first element
 * is the command and the second element (if present) is the path
 * of the directory to change to. If no path is provided, it changes
 * to the home directory. It updates the environment variable 'PWD'
 * with the new current working directory if successful.
 *
 * Return: 1 if the directory change is successful, otherwise an error message
 * is printed and the return value is still 1.
 */
int change_dir(char **str_arr)
{
	int count, i, fd, check;
	char buff[1024];

	count = 0;
	check = 1;

	if (str_arr[1] == NULL)
	{
		fd = chdir(getenv("HOME"));
		check = 0;
	}
	 for (i = 1; str_arr[i] != NULL; i++)
	 {
		 while (*str_arr[i] != '\0')
		 {
			 buff[count] = *str_arr[i];
			 count++;
			 str_arr[i]++;
		 }
	 }
	 buff[count] = '\0';
	 if (check)
	 	fd = chdir(buff);
	 if (fd == -1)
	 {
		 perror("./hsh: cd");
	 }
	 else
	 {
		 if (getcwd(buff, sizeof(buff)) != NULL)
		 {
			 setenv("PWD", buff, 1);
		 }
	 }
	 return (1);
}
