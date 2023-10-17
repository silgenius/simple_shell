#include "main.h"

/**
 * _strchr - locates a character in a string
 * @s: pointer to string
 * @c: character
 * Return: if found, a pointer to the first occurrence
 */

char *_strchr(char *s, char c)
{
	int x = 0;

	while (*(s + x) != '\0')
	{
		if (*(s + x) == c)
			return (s + x);
		x++;
	}
	if (c == '\0')
		return (s + x);
	return (NULL);
}

/**
 * _strlen - returrns the length of a string
 * @s: string variable
 * Return: length of string
 */

int _strlen(char *s)
{
	int length;

	length = 0;
	while (*s++ != '\0')
		length++;
	return (length);
}

/**
 * _strdup - returns a pointer to a duplicate of a string
 * @str: string
 * Return: pointer to duplicate string
 */

char *_strdup(char *str)
{
	int x, length;
	char *ptr;

	x = length = 0;
	if (str == NULL)
		return (NULL);
	length = _strlen(str);
	ptr = (char *)malloc(sizeof(char) * length + 1);
	if (ptr == NULL)
		return (NULL);
	while (str[x])
	{
		ptr[x] = str[x];
		x++;
	}
	ptr[x] = '\0';
	return (ptr);
}

/**
 * _strndup - returns a pointer to a duplicate of a string
 * @str: string
 * @n: number of bytes to be copied
 * Return: pointer to duplicate string
 */

char *_strndup(char *str, size_t n)
{
	unsigned int x, length;
	char *ptr;

	x = length = 0;
	if (str == NULL)
		return (NULL);
	length = _strlen(str);
	ptr = (char *)malloc(sizeof(char) * length + 1);
	if (ptr == NULL)
		return (NULL);
	while (str[x] && x < n)
	{
		ptr[x] = str[x];
		x++;
	}
	ptr[x] = '\0';
	return (ptr);
}

/**
 * _strcmp - compares two strings lexicographically
 * @s1: first string
 * @s2: second string
 * Return: integer difference between the two strings
 */

int _strcmp(char *s1, char *s2)
{
	int x, diff;

	for (x = 0; ; x++)
	{
		if (s1[x] && s2[x] && (s1[x] != s2[x]))
		{
			diff =  s1[x] - s2[x];
			break;
		}
		else if (s1[x] && !s2[x])
		{
			diff = 0 - s1[x];
			break;
		}
		else if (!s1[x] && s2[x])
		{
			diff = s2[x];
			break;
		}
		else if (!s1[x] && !s2[x])
		{
			diff = 0;
			break;
		}
	}
	return (diff);
}
