#include "main.h"

/**
 * perror_exit - prints error with perror and exits
 * Return: void
 */

void perror_exit(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}
