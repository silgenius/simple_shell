#include "main.h"

/**
 * main - initiates a shell
 * @ac: no of command line args
 * @av: array of command line args
 * Return: Always 0
 */

int main(int ac, char *av[])
{
	(void)ac;
	shell_loop(av[0]);
	return (0);
}
