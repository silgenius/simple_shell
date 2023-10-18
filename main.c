#include "main.h"

/**
 * main - initiates a shell
 * @ac: no of command line args
 * @av: array of command line args
 * Return: Always 0
 */

int main(int ac, char *av[])
{
	if (ac == 1)
		shell_loop(av[0], NULL);
	else
		shell_loop(av[0], av[1]);
	return (0);
}
