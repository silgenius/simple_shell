#include "main.h"

/**
 * main - initiates a shell
 * Return: Always 0
 */

int main(int ac, char *av[])
{
	(void)ac;
	shell_loop(av[0]);
	return (0);
}
