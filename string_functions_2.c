#include "main.h"

/**
 * _strcat - appends a src string to a destination string
 * @dest: destination string
 * @src: src string
 * Return: pointer to destination string
 */

char *_strcat(char *dest, char *src)
{
	int x, y;

	for (x = 0; ; x++)
	{
		if (dest[x])
			continue;
		else
			break;
	}
	for (y = 0; ; y++)
	{
		if (src[y])
			dest[x + y] = src[y];
		else
			break;
	}
	dest[x + y] = '\0';
	return (dest);
}

/**
 * _strcpy - copies a string to a buffer
 * @dest: pointer pointint to buffer
 * @src: pointer pointing to string
 * Return: the pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
	int x;
	int length;

	length = 0;
	for (x = 0; ; x++)
	{
		if (*(src + x))
			length++;
		else
			break;
	}
	for (x = 0; x < length; x++)
		*(dest + x) = *(src + x);
	*(dest + (length)) = '\0';

	return (dest);
}

/**
 * _strcpy - copies at most n bytes from a string to a buffer
 * @dest: pointer pointint to buffer
 * @src: pointer pointing to string
 * @n: number of bytes
 * Return: the pointer to dest
 */

char *_strncpy(char *dest, char *src, int n)
{
	int x, length= 0;

	length = _strlen(src) > n ? n : _strlen(src);
	for (x = 0; x < length; x++)
		*(dest + x) = *(src + x);
	*(dest + (length)) = '\0';

	return (dest);
}

/**
 * _strcspn - calculates the length of the initial segment of s which consists
 * entirely of bytes not in reject.
 * @s: pointer to string
 * @reject: pointer to prefix substring
 *
 * Return: number of bytes in the initial segment of s which are not in the
 * string reject.
 */

unsigned int _strcspn(char *s, char *reject)
{
	unsigned int x, y;

	x = 0;
	if (s == NULL)
		return (x);
	while (s[x])
	{
		y = 0;
		while (reject[y])
		{
			if (s[x] == reject[y])
				return (x);
			y++;
		}
		x++;
	}
	return (x);
}
