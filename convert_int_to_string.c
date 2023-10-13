#include "main.h"

/**
 * convert_int_to_str - converts an integer to a string
 * @n: integer
 * Return: pointer to string
 */

char *convert_int_to_str(int n)
{
	int tmp = n;
	unsigned int len = 0, count = 1, x = 0;
	char *str;

	while (tmp > 9)
	{
		tmp /= 10;
		count *= 10;
	}
	tmp = n;
	while (tmp > 0)
	{
		tmp /= 10;
		len++;
	}
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		perror_exit();
	for (; count >= 1; count /= 10)
	{
		str[x] = ((n / count) % 10) + 48;
		x++;
	}
	str[x] = '\0';
	return (str);
}
